//
// Created by looperX on 2021/11/15.
//

#ifndef SAVA_DETECATOR_SAVADETECATOR_H
#define SAVA_DETECATOR_SAVADETECATOR_H

#include <iostream>
#include <functional>
#include <memory>

#include "DbService.h"

class SavaDetecator {
public:
    explicit SavaDetecator(uint32_t product_id);
    ~SavaDetecator();
    void scanFile(const TaskInfo& taskInfo);

private:
    void init();
    static int file_status_callback(SAVAPI_CALLBACK_DATA *data);
    void unRegister();

    SAVAPI_GLOBAL_INIT global_init_;
    SAVAPI_FD instance_;
    SAVAPI_INSTANCE_INIT instance_init_;
    uint32_t product_id_;
    SAVAPI_APC_GLOBAL_INIT apc_global_init_;
};

#endif //SAVA_DETECATOR_SAVADETECATOR_H
