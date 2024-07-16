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
        strncpy(str, _str, this->size - 1);
        str[this->size - 1] = '\0';
    }
}

void Buffer::copy(char *str, const char *_str, int size)
{
    this->size = size;
    copy(str, _str);
}

void Buffer::fill(char *str, const char *_str, int size)
{
    if (strlen(_str) < int(this->size))
    {
        strncpy(str, _str, strlen(_str) + 1);
        for (int i = strlen(_str) + 1; i < int(this->size); i++)
            str[i] = ' ';
    }
    else
        strncpy(str, _str, this->size);
}
