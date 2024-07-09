#include "MyException/MyException.h"

MyException::MyException(const char *message) : msg(message)
{
}

const char *MyException::what() const noexcept
{
    return this->msg.c_str();
}
