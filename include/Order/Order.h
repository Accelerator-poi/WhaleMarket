#pragma once

#ifndef ORDER_H
#define ORDER_H
#include "config.h"
class Buffer;

class Order
{
public:
    Order(const char* OrderId,const char* GoodsId,float Price,const char* Time,const char* SellerId,const char* BuyerId);
    ~Order();
    const char* GetOrderId() const;
    const char* GetGoodsId() const;
    const float GetPrice() const;
    const char* GetTime() const;
    const char* GetSellerId() const;
    const char* GetBuyerId() const;

    void SetOrderId(char* OrderId);
    void SetGoodsId(char* GoodsId);
    void SetPrice(float Price);
    void SetTime(char* Time);
    void SetSellerId(char* SellerId);
    void SetBuyerId(char* BuyerId);

private:
    char orderid[ID_MAX_LEN];
    char goodsid[ID_MAX_LEN];
    float price;
    char* time;
    char sellerid[ID_MAX_LEN];
    char buyerid[ID_MAX_LEN];
    Buffer* buffer;
};

#endif