#pragma once

#ifndef GOODS_H
#define GOODS_H

#include "config.h"
class Buffer;

// extern char* stateprompte[3];
static const char *stateprompte[3] = {"已售出", "已下架", "销售中"};

class Goods
{
    public:
        Goods(const char* GoodsId,const char* Name,const float Price,const char* Info,
                const char* SellerId,const char* Time,const int State);
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
        char time[TIME_MAX_LEN];
        int state;
        Buffer* buffer;
};

#endif
