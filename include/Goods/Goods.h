#pragma once

#ifndef GOODS_H
#define GOODS_H

#include "config.h"
class Buffer;

extern char* stateprompte[3];

class Goods
{
    public:
        Goods(char* GoodsId,char* Name,float Price,char* Info,char* SellerId,char* Time,int State);
        ~Goods();
        const char* GetGoodsId() const;
        const char* GetName() const;
        const float GetPrice() const;
        const char* GetInfo() const;
        const char* GetSellerId() const;
        const char* GetTime() const;
        const int GetState() const;

        void SetGoodsId(char* Id);
        void SetName(char* Name);
        void SetPrice(float Price);
        void SetInfo(char* Info);
        void SetSellerId(char* SellerId);
        void SetTime(char* Time);
        void SetState(int State);

    private:
        char goodsid[ID_MAX_LEN];
        char name[NAME_MAX_LEN];
        float price;
        char info[GOODSINFO_MAX_LEN];
        char sellerid[ID_MAX_LEN];
        char* time;
        int state;
        Buffer* buffer;
};

#endif
