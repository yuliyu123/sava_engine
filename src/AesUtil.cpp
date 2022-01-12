//
// Created by looperX on 2021/12/27.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "AesUtil.h"

using namespace std;

extern char SECRET_KEY[32];

std::string rtrim(const std::string &s){
    int len = s.length() - 1;
    for(; len > 0; len--){
        if(s[len]!='\0'){
            break;
        }
    }
    return s.substr(0,len + 1);
}

bool AESUtil::init(std::string key) {
    int len = key.length();
    assert( len == 16 || len  == 24 || len  == 32 );
    if( AES_set_encrypt_key((const unsigned char *)key.c_str(),len * 8, &m_enc_aes_) < 0 ) {
        return false;
    }

    if( AES_set_decrypt_key((const unsigned char *)key.c_str(),len * 8, &m_dec_aes_) < 0 ) {
        return false;
    }

    inited_ = true;
    return true;
}

std::string AESUtil::encryptData(const std::string& plainText) {
    std::string res;
    if(!inited_) {
        cout << "Please init key!" << endl;
        return res;
    }
    //AES_ecb_encrypt(const unsigned char *in, unsigned char *out,const AES_KEY *key, const int enc);
    assert(plainText.length() > 0 );

    unsigned char buf[17] = {0};
    unsigned char cipher[17] = {0};
    //f83c9a60dc0cdb98219f79d6d5db1635
    for(int i=0;i<plainText.length();i+=16) {
        memset(buf,0,17);
        if(plainText.length() - i > 16) {
            plainText.copy((char *)buf,16,i);
        }
        else {
            plainText.copy((char *)buf,plainText.length()-i ,i);
        }
        memset(cipher,0,17);
        AES_ecb_encrypt(buf, cipher,&m_enc_aes_, AES_ENCRYPT);
        res.append(std::string((char *)cipher,16));
    }
    return res;
}

std::string AESUtil::decryptData(const std::string& cipher) {
    std::string res;
    if(!inited_) {
        return res;
    }

    if(cipher.length() % 16 != 0) {
        return res;
    }

    unsigned char buf[17] = {0};
    unsigned char plainText[17] = {0};

    for(int i=0;i<cipher.length();i+=16) {
        memset(buf,0,17);
        cipher.copy((char *)buf,16,i);
        memset(plainText,0,17);
        AES_ecb_encrypt(buf,plainText,&m_dec_aes_, AES_DECRYPT);
        res.append(std::string((char *)plainText,16));
    }
    return rtrim(res);
}

//int main() {
//    AESUtil aesUtil;
//    string text = "moresec@sec";
//    strcpy(normal_key, SECRET_KEY);
//    cout << "normal_key: " << normal_key << endl;
//    aesUtil.init(normal_key);
//    std::string en_res = aesUtil.encryptData(text);
//    cout << "en_res: " << en_res << endl;
//
//    auto out = base64_encode(en_res.c_str(), en_res.length());
//    cout << "base64 encode: " << out << endl;
//    auto de_res = aesUtil.decryptData(base64_decode(out));
//    cout << "de_res: " << de_res.c_str() << endl;
//
//    string en_data = "xQhTQU+HrA3qrFh74rNaQg==";
//    cout << "de_res 2: " << aesUtil.decryptData(base64_decode(en_data)) << endl;
//}
