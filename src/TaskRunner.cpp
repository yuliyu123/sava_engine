#include <thread>
#include <iostream>
#include <utility>

#include "ThreadPool.h"
#include "TaskRunner.h"
#include "DbService.h"

using namespace std;

TaskRunner::TaskRunner(ConfigInfo config_info)
    : config_info_(std::move(config_info))
    , pool_(new ThreadPool(1))
    , sava_detecator_(stoi(config_info_.product_id)){
    cout << "TaskRunner constructor" << endl;
}

void TaskRunner::run() {
    DbService::getInstance()->setExecCb(bind(&TaskRunner::onExec, this, placeholders::_1));
}

void TaskRunner::onExec(TaskInfo taskInfo) {
    std::vector<std::future<void> > results;
    results.emplace_back(pool_->enqueue([this, taskInfo] () {
        sava_detecator_.scanFile(taskInfo);
    }));
}

void TaskRunner::publish(const std::string& filePath) {
    DbService::getInstance()->publish(config_info_.channel, filePath);
}

TaskRunner::~TaskRunner() {
    DbService::getInstance()->unsubscribe(3);
}
