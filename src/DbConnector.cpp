//
// Created by looperX on 2021/11/15.
//

#include <cstring>
#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>

#include "DbConnector.h"

static const int PORT = 6379;

using namespace std;

extern ConfigInfo configInfo;

DbConnector::DbConnector() {}

bool DbConnector::connect() {
    // 负责publish发布消息的上下文连接
    publish_context_ = redisConnect(configInfo.host.c_str(), PORT);
    if (nullptr == publish_context_)
    {
        cerr << "connect redis failed!" << endl;
        return false;
    }
    reply_ = static_cast<redisReply *>(redisCommand(publish_context_, "AUTH %s", configInfo.pwd.c_str()));

    if (reply_ == nullptr) {
        cerr << "connect redis failed" << endl;
        exit(0);
        return false;
    }


    // 负责subscribe订阅消息的上下文连接
    subcribe_context_ = redisConnect(configInfo.host.c_str(), PORT);
    if (nullptr == subcribe_context_) {
        cerr << "connect redis failed!" << endl;
        return false;
    }

    reply_ = static_cast<redisReply *>(redisCommand(subcribe_context_, "AUTH %s", configInfo.pwd.c_str()));

    // 在单独的线程中，监听通道上的事件，有消息给业务层进行上报
    thread t([&]() {
        getTaskInfos();
    });
    t.detach();

    cout << "connect redis-server success!" << endl;
    return true;
}

// 向redis指定的通道channel发布消息
bool DbConnector::publish(int channel, string message)
{
    redisReply *reply = (redisReply *)redisCommand(publish_context_, "PUBLISH %d %s", channel, message.c_str());
    if (nullptr == reply) {
        cerr << "publish command failed!" << endl;
        return false;
    }
    freeReplyObject(reply);
    return true;
}

// 向redis指定的通道subscribe订阅消息
bool DbConnector::subscribe(int channel) {
    // SUBSCRIBE命令本身会造成线程阻塞等待通道里面发生消息，这里只做订阅通道，不接收通道消息
    // 通道消息的接收专门在observer_channel_message函数中的独立线程中进行
    // 只负责发送命令，不阻塞接收redis server响应消息，否则和notifyMsg线程抢占响应资源
    if (REDIS_ERR == redisAppendCommand(this->subcribe_context_, "SUBSCRIBE %d", channel)) {
        cerr << "subscribe command failed!" << endl;
        return false;
    }
    // redisBufferWrite可以循环发送缓冲区，直到缓冲区数据发送完毕（done被置为1）
    int done = 0;
    while (!done) {
        if (REDIS_ERR == redisBufferWrite(this->subcribe_context_, &done)) {
            cerr << "subscribe command failed!" << endl;
            return false;
        }
    }
    return true;
}

// 向redis指定的通道unsubscribe取消订阅消息
bool DbConnector::unsubscribe(int channel) {
    if (REDIS_ERR == redisAppendCommand(this->subcribe_context_, "UNSUBSCRIBE %d", channel)) {
        cerr << "unsubscribe command failed!" << endl;
        return false;
    }
    // redisBufferWrite可以循环发送缓冲区，直到缓冲区数据发送完毕（done被置为1）
    int done = 0;
    while (!done) {
        if (REDIS_ERR == redisBufferWrite(this->subcribe_context_, &done)) {
            cerr << "unsubscribe command failed!" << endl;
            return false;
        }
    }
    return true;
}

// 在独立线程中接收订阅通道中的消息
void DbConnector::observer_channel_message() {
    redisReply *reply = nullptr;
    while (REDIS_OK == redisGetReply(this->subcribe_context_, (void **)&reply)) {
        // 订阅收到的消息是一个带三元素的数组
        if (reply != nullptr && reply->element[2] != nullptr && reply->element[2]->str != nullptr) {
            // 给业务层上报通道上发生的消息
            notify_message_handler_(atoi(reply->element[1]->str) , reply->element[2]->str);
        }
        freeReplyObject(reply);
    }
}

void DbConnector::init_notify_handler(function<void(int, string)> fn) {
    cout << "set init_notify_handler" << endl;
    this->notify_message_handler_ = std::move(fn);
}

void DbConnector::getTaskInfos() {
    redisReply *r = nullptr;
    while (1) {
        r = reinterpret_cast<redisReply *>(redisCommand(this->subcribe_context_,"lpop queue:malware:file"));
        if (r == nullptr) {
            cout << "reply empty" << endl;
            return;
        }

        switch(r->type) {
            case REDIS_REPLY_STRING:
                if (notify_message_handler_ != nullptr) {
                    cout << "execute notify_message_handler_" << endl;
                    notify_message_handler_(r->len, r->str);
                }
                break;
            case REDIS_REPLY_ARRAY:
                break;
            default:
                break;
        }
        freeReplyObject(r);
    }
}

bool DbConnector::sendReplayInfo(const ReplyInfo& replyInfo) {
    string msg = R"({"md5":")" + replyInfo.md5 + R"(", "filePath":")" + replyInfo.filePath
            + R"(", "result":)" + to_string(replyInfo.result) + R"(, "type": ")" + replyInfo.type + "\"}";
    cout << "send replayInfo: " << msg << endl;
    redisReply *reply = (redisReply *)redisCommand(publish_context_, "lpush queue:malware:res %s", msg.c_str());
    if (nullptr == reply) {
        cerr << "publish command failed!" << endl;
        return false;
    }
    freeReplyObject(reply);
    return true;
}

DbConnector::~DbConnector() {}
