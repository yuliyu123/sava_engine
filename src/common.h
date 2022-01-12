#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

#include "include/savapi_unix.h"

struct TaskInfo {
    std::string filePath;
    std::string md5;
};

struct ReplyInfo {
    std::string md5;
    std::string filePath;
    bool result;
    std::string type;
};

struct ConfigInfo {
    std::string product_id;
    unsigned int channel;
    std::string host;
    std::string pwd;
};

void savapi_global_init_prepare(SAVAPI_GLOBAL_INIT *global_init, unsigned int product_id);
//int file_status_callback(SAVAPI_CALLBACK_DATA *data);
static const char *scan_answer_to_string(unsigned int scan_answer);
SAVAPI_STATUS savapi_instance_init_prepare(SAVAPI_INSTANCE_INIT *instance_init);
bool is_file_exists(const std::string& file_path);
std::vector<std::string> splitString(std::string str, std::string delimeter);
void savapi_apc_global_init_prepare(SAVAPI_APC_GLOBAL_INIT *apc_global_init);
void savapi_apc_global_init_release(SAVAPI_APC_GLOBAL_INIT *apc_global_init);