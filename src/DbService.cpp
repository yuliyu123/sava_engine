#include <algorithm>
#include "DbService.h"

static DbService* instance_ = nullptr;

DbService::DbService() {
    cout << "DbService constructor" << endl;
    if(dbConnector_.connect()) {
        dbConnector_.init_notify_handler(bind(&DbService::handleRedisSubscribeMessage, this, _1, _2));
    }
}

DbService* DbService::getInstance() {
    if(instance_ == nullptr)
        instance_ = new DbService();
    return instance_;
}

void DbService::subscribe(int cid)
{
    cout << "start subscribe channel: " << cid << endl;
    dbConnector_.subscribe(cid);
}

void DbService::unsubscribe(int cid)
{
    dbConnector_.unsubscribe(cid);
}

bool DbService::publish(int channel, string message)
{
    dbConnector_.publish(channel, message);
}

bool DbService::sendReplayInfo(const ReplyInfo& replyInfo) {
    dbConnector_.sendReplayInfo(replyInfo);
}

void DbService::handleRedisSubscribeMessage(int cid, const string& msg) {
    cout << "receive msg: " << msg << endl;
    TaskInfo task = convertMsg(msg);
    if (cb_ != nullptr && !task.md5.empty() && !task.filePath.empty()) {
        cb_(task);
    }
}

void DbService::setExecCb(std::function<void(TaskInfo taskInfo)> cb) {
    cout << "set execution success " << endl;
    cb_ = std::move(cb);
}

TaskInfo DbService::convertMsg(string msg) {
    if (msg.empty()) return {};
    msg.erase(std::remove_if(msg.begin(), msg.end(), [](char c) {
        return c == '{' || c == '}' || c == '"';
    }), msg.end());
    std::cout << msg << '\n';

    auto infos = splitString(msg, ",");
    if (infos.size() < 2) {
        cout << "format incorrect" << endl;
        return {};
    }

    TaskInfo taskInfo;
    for (auto info : infos) {
        auto info_msg = splitString(info, ":");
        if (info_msg.size() < 2) {
            return {};
        }
        if (info_msg[0].find("md5") != string::npos) {
            taskInfo.md5 = info_msg[1];
        } else if (info_msg[0].find("path") != string::npos) {
            taskInfo.filePath = info_msg[1];
        } else {
            cout << "unrecognized field" << endl;
            return {};
        }
    }
    return taskInfo;
}

