#include <iostream>
#include <unistd.h>

#include "src/TaskRunner.h"
#include "src/AesUtil.h"
#include "src/Base64.h"

char SECRET_KEY[] = "L*)D)p?+I1_e_^kh";
char normal_key[16] = {0};
ConfigInfo configInfo = {};

using namespace std;

bool initConfig(char *argv[], ConfigInfo& configInfo) {
    configInfo.product_id = argv[1];
    if (configInfo.product_id.empty()) {
        cerr << "invalid encrypt product_id" << endl;
        return false;
    }

    configInfo.host = argv[2];
    if (configInfo.host.empty()) {
        cerr << "invalid redis server" << endl;
        return false;
    }

    configInfo.pwd = argv[3];
    if (configInfo.pwd.empty()) {
        cerr << "invalid redis encrypt pwd" << endl;
        return false;
    }
    return true;
}

void decryptConfigData(ConfigInfo& configInfo) {
    AESUtil aesUtil;
    strcpy(normal_key, SECRET_KEY);
    aesUtil.init(normal_key);
    configInfo.product_id = aesUtil.decryptData(base64_decode(configInfo.product_id));
    configInfo.pwd = aesUtil.decryptData(base64_decode(configInfo.pwd));
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "args not matched, pls specify encrypt product id， redis host and encrypt pwd" << endl;
        return 0;
    }

    if (initConfig(argv, configInfo) == 0) {
        cout << "config err" << endl;
        return 0;
    }
    decryptConfigData(configInfo);
    TaskRunner taskRunner(configInfo);
    taskRunner.run();
    while (true) {
        sleep(1000);
    }
    return 0;
}
