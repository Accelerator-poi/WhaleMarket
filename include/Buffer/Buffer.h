#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include<memory>
#include <cstring>
#include "config.h"

class Buffer
{
    public:
    Buffer(int size);
    Buffer();
    void copy(char* str,const char* _str);
    void copy(char* str,const char* _str, int size);
    private:
    int size;
};

#endif