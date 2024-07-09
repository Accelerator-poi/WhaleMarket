#pragma once

#ifndef USER_H
#define USER_H
// #ifdef __USER_H__

#include "config.h"
// #include "Buffer/Buffer.h"
#include <memory>
class Buffer;
class User
{
public:
    const char* GetId() const;
    const char* GetName() const;
    const char* GetPwd() const;
    const char* GetTelephone() const;
    const char* GetAddress() const;
    const float GetBalance() const;
    void SetId(char* Id);
    void SetName(char* Name);
    void SetPwd(char* Pwd);
    void SetTelephone(char* Telephone);
    void SetAddress(char* Address);
    void SetBalance(float Balance);
    User(const char* Id,const char* Name,const char* Pwd,const char* Telephone,const char* Address, float Balance);
    ~User();
private:
    char id[ID_MAX_LEN];
    char name[NAME_MAX_LEN];
    char password[PWD_MAX_LEN];
    char telephone[TELEPHONE_MAX_LEN];
    char address[ADDRESS_MAX_LEN];
    float balance;
    Buffer* buffer;
};

#endif