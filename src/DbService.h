//
// Created by looperX on 2021/11/15.
//

#ifndef SAVA_SCAN_DBSERVICE_H
#define SAVA_SCAN_DBSERVICE_H

#include <iostream>
#include <string>
#include <functional>
#include <thread>
#include <queue>

#include "DbConnector.h"

using namespace std;
using namespace std::placeholders;

class DbService
{
public:
    DbService();

    static DbService* getInstance();
    void subscribe(int cid);
    void unsubscribe(int cid);
    bool publish(int channel, string message);
    bool sendReplayInfo(const ReplyInfo& replyInfo);
    void handleRedisSubscribeMessage(int cid, const string& msg);
    void setExecCb(std::function<void(TaskInfo taskInfo)> cb);
    TaskInfo convertMsg(string msg);

private:
    DbConnector dbConnector_;
    std::function<void(TaskInfo taskInfo)> cb_;
};

#endif //SAVA_SCAN_DBSERVICE_H
