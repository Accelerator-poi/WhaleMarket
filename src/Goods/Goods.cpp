#include "Goods/Goods.h"
#include "Buffer/Buffer.h"

const char *stateprompte[3] = {"已售出", "已下架", "销售中"};

Goods::Goods(const char *GoodsId,const char *Name,const float Price,
            const char *Info,const char *SellerId,const char *Time,const int State)
{
    buffer = new Buffer;
    buffer->copy(this->goodsid, GoodsId, sizeof(this->goodsid));
    buffer->copy(this->name, Name, sizeof(this->name));
    this->price = Price;
    buffer->copy(this->info, Info, sizeof(this->info));
    buffer->copy(this->sellerid, SellerId, sizeof(this->sellerid));
    buffer->copy(this->time, Time, sizeof(this->time));
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
    buffer->copy(this->time, Time, sizeof(this->time));
}

void Goods::SetState(int State)
{
    this->state = State;
}
