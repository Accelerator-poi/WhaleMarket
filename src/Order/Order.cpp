#include "Order/Order.h"
#include "Buffer/Buffer.h"

Order::Order(const char *OrderId, const char *GoodsId, float Price, const char *Time, const char *SellerId, const char *BuyerId)
{
    buffer = new Buffer;
    buffer->copy(this->orderid, OrderId, sizeof(this->orderid));
    buffer->copy(this->goodsid, GoodsId, sizeof(this->goodsid));
    this->price = Price;
    buffer->copy(this->time, Time, sizeof(this->time));
    buffer->copy(this->sellerid, SellerId, sizeof(this->sellerid));
    buffer->copy(this->buyerid, BuyerId, sizeof(this->buyerid));
}

Order::~Order()
{
    delete buffer;
}

const char *Order::GetOrderId() const
{
    return this->orderid;
}

const char *Order::GetGoodsId() const
{
    return this->goodsid;
}

const float Order::GetPrice() const
{
    return this->price;
}

const char *Order::GetTime() const
{
    return this->time;
}

const char *Order::GetSellerId() const
{
    return this->sellerid;
}

const char *Order::GetBuyerId() const
{
    return this->buyerid;
}

void Order::SetOrderId(char *OrderId)
{
    buffer->copy(this->orderid, OrderId, sizeof(this->orderid));
}

void Order::SetGoodsId(char *GoodsId)
{
    buffer->copy(this->goodsid, GoodsId, sizeof(this->goodsid));
}

void Order::SetPrice(float Price)
{
    this->price = Price;
}

void Order::SetTime(char *Time)
{
    buffer->copy(this->time, Time, sizeof(this->time));
}

void Order::SetSellerId(char *SellerId)
{
    buffer->copy(this->sellerid, SellerId, sizeof(this->sellerid));
}

void Order::SetBuyerId(char *BuyerId)
{
    buffer->copy(this->buyerid, BuyerId, sizeof(this->buyerid));
}
