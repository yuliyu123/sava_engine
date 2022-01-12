//
// Created by looperX on 2021/11/15.
//

#ifndef SAVA_SCAN_TASHRUNNER_H
#define SAVA_SCAN_TASHRUNNER_H

#include <queue>
#include <vector>
#include <memory>

#include "SavaDetecator.h"
#include "src/ThreadPool.h"
#include "DbService.h"

class TaskRunner {
public:
    explicit TaskRunner(ConfigInfo  configInfo);
    ~TaskRunner();
    void run();
    void publish(const std::string& filePath);
    void onExec(TaskInfo taskInfo);

private:
    ConfigInfo config_info_;
    std::unique_ptr<ThreadPool> pool_;
    SavaDetecator sava_detecator_;
};

#endif //SAVA_SCAN_TASHRUNNER_H
