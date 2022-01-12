//
// Created by looperX on 2021/12/27.
//

#ifndef SAVA_SCAN_AESUTIL_H
#define SAVA_SCAN_AESUTIL_H

#include "openssl/aes.h"

std::string rtrim(const std::string &s);

class AESUtil {
public:
    AESUtil() {}
    ~AESUtil() {}
    std::string encryptData(const std::string &plainText);
    std::string decryptData(const std::string &cipher);
    bool init(std::string key);

private:
    bool inited_;
    AES_KEY m_enc_aes_;
    AES_KEY m_dec_aes_;
};

#endif //SAVA_SCAN_AESUTIL_H
