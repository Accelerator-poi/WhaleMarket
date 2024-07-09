#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>
#include<stdexcept>
#include<string>

/// @brief 异常处理类
class MyException:public std::exception
{
    public:
    MyException(const char* message);
    const char* what() const noexcept override;

    private:
    std::string msg;
};

template <typename Func, typename... Args>
inline void ErrorFunction(const char *errorMessage, Func functionPtr, Args... args)
{
    try
    {
        functionPtr(args...); // 调用传入的函数
    }
    catch (const MyException &e)
    {
        std::cerr << errorMessage << ": " << e.what() << std::endl;
        exit(0); // 退出程序
    }
}

#endif
