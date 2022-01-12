#include <vector>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include "common.h"

#define SAVAPI_DEFAULT_HOST "localhost"
#define SAVAPI_DEFAULT_PORT 9999

void savapi_global_init_prepare(SAVAPI_GLOBAL_INIT *global_init, unsigned int product_id)
{
    memset(global_init, 0, sizeof(SAVAPI_GLOBAL_INIT));

    /* Add the product-id to the global initialization structure */
    global_init->program_type = product_id;
    global_init->api_major_version = SAVAPI_API_MAJOR_VERSION;
    global_init->api_minor_version = SAVAPI_API_MINOR_VERSION;
    printf("18");
    /* Set the following fields with empty string in order to use the default values */
    global_init->engine_dirpath = "";
    global_init->vdfs_dirpath = "";
    global_init->key_file_name = "";
}

const char *scan_answer_to_string(unsigned int scan_answer) {
    switch (scan_answer) {
        case SAVAPI_SCAN_STATUS_INFECTED:
            return "infected";
        case SAVAPI_SCAN_STATUS_SUSPICIOUS:
            return "suspicious";
        case SAVAPI_SCAN_STATUS_ERROR:
            return "error";
        case SAVAPI_SCAN_STATUS_FINISHED:
            return "finished";
        default:
            return "unknown";
    }
}

SAVAPI_STATUS savapi_instance_init_prepare(SAVAPI_INSTANCE_INIT *instance_init)
{
    SAVAPI_STATUS ret = SAVAPI_S_OK;

    /* init instance data */
    memset(instance_init, 0, sizeof(SAVAPI_INSTANCE_INIT));

    instance_init->host_name = SAVAPI_DEFAULT_HOST;

    /*
     * NOTE: The timeouts should be set according to the running
     * system's load and performance. If the system's resources
     * are low, the timeouts can be exceeded resulting in a broken
     * communication between the Client Library and the SAVAPI Service.
     * If the timeouts are infinite or too big, the client connection
     * may block while waiting for a server response.
     */

    /* unlimited timeout for the socket connection */
    instance_init->connection_timeout = 0;
    /* 6 seconds for the set operation */
    instance_init->set_timeout = 6000;
    /* 3 seconds for the get operation */
    instance_init->get_timeout = 3000;

    /* will connect via TCP/IP and not Unix sockets */
    instance_init->flags = SAVAPI_FLAG_USE_TCP;
    instance_init->port = SAVAPI_DEFAULT_PORT;

    return ret;
}

bool is_file_exists(const std::string& file_path) {
    return (access(file_path.c_str(), F_OK ) != -1);
}

std::vector<std::string> splitString(std::string str, std::string delimeter) {
    std::vector<std::string> splittedStrings = {};
    size_t pos = 0;

    while ((pos = str.find(delimeter)) != std::string::npos)
    {
        std::string token = str.substr(0, pos);
        if (token.length() > 0)
            splittedStrings.push_back(token);
        str.erase(0, pos + delimeter.length());
    }

    if (str.length() > 0)
        splittedStrings.push_back(str);
    return splittedStrings;
}

void savapi_apc_global_init_prepare(SAVAPI_APC_GLOBAL_INIT *apc_global_init)
{
    memset(apc_global_init, 0, sizeof(SAVAPI_APC_GLOBAL_INIT));

    /* get the system's temporary directory */
    apc_global_init->temp_dir = "/tmp";

    /* set the APC options to the default ones used in the SAVAPI Service */
    apc_global_init->apc_mode = SAVAPI_APC_SCAN_MODE_FULL;  /* full functionality of APC */
    apc_global_init->cache_size = 5242880;                  /* cache size of 5MB */
    apc_global_init->dump_cache_file = 0;                   /* no cache file dump */
    apc_global_init->cache_file_path = NULL;                /* default temporary directory */
    apc_global_init->blackout_retries = 5;                  /* 5 APC scan fails until APC will be declared unavailable */
    apc_global_init->blackout_timeout = 300;                /* 300 seconds after which a new connection will be tried to APC, if APC was declared unavailable */
    apc_global_init->proxy = NULL;                          /* use the system proxy or the one configured in the env (HTTPS_PROXY, HTTP_PROXY, etc) */
}

void savapi_apc_global_init_release(SAVAPI_APC_GLOBAL_INIT *apc_global_init)
{
    free(apc_global_init->temp_dir);
    memset(apc_global_init, 0, sizeof(SAVAPI_APC_GLOBAL_INIT));
}
