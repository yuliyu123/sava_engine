//
// Created by looperX on 2021/11/15.
//

#ifndef SAVA_SCAN_DBCONNECTOR_H
#define SAVA_SCAN_DBCONNECTOR_H

#include <iostream>
#include <functional>
#include <include/hiredis.h>

#include "common.h"

class DbConnector {
public:
    DbConnector();
    ~DbConnector();

    bool connect();
    bool publish(int channel, std::string message);

    bool subscribe(int channel);
    bool unsubscribe(int channel);
    void observer_channel_message();
    void getTaskInfos();
    bool sendReplayInfo(const ReplyInfo& replyInfo);
    void init_notify_handler(std::function<void(int, std::string)> fn);

private:
    redisContext *publish_context_;
    redisContext *subcribe_context_;
    redisReply* reply_;
    std::function<void(int, std::string)> notify_message_handler_;

};

#endif //SAVA_SCAN_DBCONNECTOR_H
