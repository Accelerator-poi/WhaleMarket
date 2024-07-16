#include "Buffer/Buffer.h"

Buffer::Buffer(int size)
{
    this->size = size;
}

Buffer::Buffer()
{
    this->size = BUFFER_SIZE;
}

void Buffer::copy(char *str, const char *_str)
{
    if (strlen(_str) < int(this->size))
    {
        strncpy(str, _str, strlen(_str) + 1);
    }
    else
    {
        strncpy(str, _str, int(this->size) - 1);
        str[this->size - 1] = '\0';
    }
}

void Buffer::copy(char *str, const char *_str, int size)
{
    this->size = size;
    copy(str, _str);
}
