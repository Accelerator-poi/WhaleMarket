#include "User/User.h"
#include "MyException/MyException.h"
#include "Buffer/Buffer.h"
#include <cstring>

User::User(const char *Id, const char *Name, const char *Pwd, const char *Telephone, const char *Address, float Balance)
{
    buffer = new Buffer();
    buffer->copy(this->id, Id, sizeof(this->id));
    buffer->copy(this->name, Name, sizeof(this->name));
    buffer->copy(this->password, Pwd, sizeof(this->password));
    buffer->copy(this->telephone, Telephone, sizeof(this->telephone));
    buffer->copy(this->address, Address, sizeof(this->address));
    balance = Balance;
}

User::~User()
{
    if (buffer != nullptr)
        delete buffer;
}

const char *User::GetId() const
{
    return this->id;
}

const char *User::GetName() const
{
    return this->name;
}

const char *User::GetPwd() const
{
    return this->password;
}

const char *User::GetAddress() const
{
    return this->address;
}

const char *User::GetTelephone() const
{
    return this->telephone;
}

const float User::GetBalance() const
{
    return balance;
}

void User::SetId(char *Id)
{
    buffer->copy(this->id, Id, sizeof(this->id));
}

void User::SetName(char *Name)
{
    buffer->copy(this->name, Name, sizeof(this->name));
}

void User::SetPwd(char *Pwd)
{
    buffer->copy(this->password, Pwd, sizeof(this->password));
}

void User::SetTelephone(char *Telephone)
{
    buffer->copy(this->telephone, Telephone, sizeof(this->telephone));
}

void User::SetAddress(char *Address)
{
    buffer->copy(this->address, Address, sizeof(this->address));
}

void User::SetBalance(float Balance)
{
    this->balance = Balance;
}
