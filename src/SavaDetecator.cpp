#include <iostream>

#include "SavaDetecator.h"

TaskInfo curTask;
static string last_record;

SavaDetecator::SavaDetecator(uint32_t product_id)
        : global_init_({0})
        , instance_(nullptr)
        , instance_init_({0})
        , product_id_(product_id)
        , apc_global_init_({0}) {
    std::cout << "SavaDetecator constructor, product info config success" << std::endl;
    init();
}

void SavaDetecator::init() {
    savapi_apc_global_init_prepare(&apc_global_init_);
    savapi_global_init_prepare(&global_init_, product_id_);
    SAVAPI_APC_initialize(&apc_global_init_);

    int ec = SAVAPI_initialize(&global_init_);
    if (ec != SAVAPI_S_OK) {
        std::cout << "SAVAPI_initialize failed with ec: " << ec << std::endl;
        return;
    }

    savapi_instance_init_prepare(&instance_init_);
    printf("Creating SAVAPI Library instance\n");
    ec = SAVAPI_create_instance(&instance_init_, &instance_);
    if (ec != SAVAPI_S_OK) {
        std::cout << "create instance failed with ec: " << ec << std::endl;
        return;
    }

    ec = SAVAPI_register_callback(instance_, SAVAPI_CALLBACK_REPORT_FILE_STATUS, file_status_callback);
    if (ec != SAVAPI_S_OK) {
        std::cout << "register callback failed with ec: " << ec << std::endl;
        return;
    }
}

void SavaDetecator::scanFile(const TaskInfo& taskInfo) {
    curTask = taskInfo;
    std::cout << "start scan file: " << taskInfo.filePath << std::endl;
    if (!is_file_exists(taskInfo.filePath)) {
        std::cout << "filePath not existed: " << taskInfo.filePath << std::endl;
        return;
    }
    int ec = SAVAPI_scan(instance_, (char*)taskInfo.filePath.c_str());
    if (ec != SAVAPI_S_OK) {
        std::cout << "SAVAPI_scan failed with error code: " << ec << std::endl;
        return;
    }
}

void SavaDetecator::unRegister() {
    SAVAPI_unregister_callback(instance_, SAVAPI_CALLBACK_REPORT_FILE_STATUS, file_status_callback);
    SAVAPI_release_instance(&instance_);
    SAVAPI_uninitialize();
}

int SavaDetecator::file_status_callback(SAVAPI_CALLBACK_DATA *data) {
    if (last_record == curTask.md5 + curTask.filePath) {
        cout << "checked, return" << endl;
        last_record = "";
        return 1;
    }
    ReplyInfo replyInfo;
    SAVAPI_FILE_STATUS_DATA *file_status_data = data->callback_data.file_status_data;
    std::cout <<  "SavaDetecator FILE_STATUS callback called for file: " << file_status_data->file_info.name << std::endl;
    std::cout <<  "scan answer: " << file_status_data->scan_answer << std::endl;
    replyInfo.result = false;
    replyInfo.md5 = curTask.md5;
    replyInfo.filePath = file_status_data->file_info.name;
    last_record = replyInfo.md5 + replyInfo.filePath;

    if (file_status_data->scan_answer == SAVAPI_SCAN_STATUS_INFECTED) {
        std::cout << "File is infected: " << file_status_data->file_info.name << std::endl;
        replyInfo.result = true;
        replyInfo.type = file_status_data->malware_info.type ? file_status_data->malware_info.type : "no type";
    }

    DbService::getInstance()->sendReplayInfo(replyInfo);
    return 0;
}

SavaDetecator::~SavaDetecator() {
    unRegister();
}
