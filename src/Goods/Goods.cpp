#include "Goods/Goods.h"
#include "Buffer/Buffer.h"

char *stateprompte[3] = {"已售出", "已下架", "销售中"};

Goods::Goods(char *GoodsId, char *Name, float Price, char *Info, char *SellerId, char *Time, int State)
{
    buffer = new Buffer;
    buffer->copy(this->goodsid, GoodsId, sizeof(this->goodsid));
    buffer->copy(this->name, Name, sizeof(this->name));
    this->price = Price;
    buffer->copy(this->info, Info, sizeof(this->info));
    buffer->copy(this->sellerid, SellerId, sizeof(this->sellerid));
    this->time = Time;
    this->state = State;
}

Goods::~Goods()
{
    delete buffer;
}

const char *Goods::GetGoodsId() const
{
    return this->goodsid;
}

const char *Goods::GetName() const
{
    return this->name;
}

const float Goods::GetPrice() const
{
    return this->price;
}

const char *Goods::GetInfo() const
{
    return this->info;
}

const char *Goods::GetSellerId() const
{
    return this->sellerid;
}

const char *Goods::GetTime() const
{
    return this->time;
}

const int Goods::GetState() const
{
    return this->state;
}

void Goods::SetGoodsId(char *Id)
{
    buffer->copy(this->goodsid, Id, sizeof(this->goodsid));
}

void Goods::SetName(char *Name)
{
    buffer->copy(this->name, Name, sizeof(this->name));
}

void Goods::SetPrice(float Price)
{
    this->price = Price;
}

void Goods::SetInfo(char *Info)
{
    buffer->copy(this->info, Info, sizeof(this->info));
}

void Goods::SetSellerId(char *SellerId)
{
    buffer->copy(this->sellerid, SellerId, sizeof(this->sellerid));
}

void Goods::SetTime(char *Time)
{
    this->time = Time;
}

void Goods::SetState(int State)
{
    this->state = State;
}
