#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "MyException/MyException.h"

#include <iostream>
#include <iomanip>

void MainMenu::GoodHandle(int choice)
{
    switch(choice)
    {
        case 1:
            GoodModifyName();
            break;
        case 2:
            GoodModifyPrice();
            break;
        case 3:
            GoodModifyInfo();
            break;
        case 4:
            currentState = PageState::SellerPage;
            break;
        default:
            break;
    }
}

void MainMenu::GoodModifyName()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string GoodId, GoodName;
    std::vector<std::vector<std::string>> GoodVec;
    Datafiles Goodsfile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    bool flag = false;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;

    while(true)
    {
        std::cout << "请输入商品Id:";
        std::cin >> GoodId;
        GoodData.find("Id",GoodId,GoodsMap,Goodsfile,GoodVec);
        for(auto Good:GoodVec)
        {
            if(Good[4] == this->UserId)
            {
                flag = true;
            }
        }

        if(!flag)
           std::cout << "您没有这件商品！" << std::endl;
        else 
           break;
    }

    std::cout << "请输入新的商品名称：";
    std::cin >> GoodName;
    GoodData.Modify("Id",GoodId,"Name",GoodName,GoodsMap,Goodsfile);
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::GoodModifyPrice()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string GoodId, ModifyStr;
    std::vector<std::vector<std::string>> GoodVec;
    Datafiles Goodsfile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    bool flag = false;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;

    while(true)
    {
        std::cout << "请输入商品Id:";
        std::cin >> GoodId;
        GoodData.find("Id",GoodId,GoodsMap,Goodsfile,GoodVec);
        for(auto Good:GoodVec)
        {
            if(Good[4] == this->UserId)
            {
                flag = true;
            }
        }

        if(!flag)
           std::cout << "您没有这件商品！" << std::endl;
        else 
           break;
    }

    std::cout << "请输入新的商品价格：";
    std::cin >> ModifyStr;
    GoodData.Modify("Id",GoodId,"Price",ModifyStr,GoodsMap,Goodsfile);
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::GoodModifyInfo()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string GoodId, ModifyStr;
    std::vector<std::vector<std::string>> GoodVec;
    Datafiles Goodsfile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    bool flag = false;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;

    while(true)
    {
        std::cout << "请输入商品Id:";
        std::cin >> GoodId;
        GoodData.find("Id",GoodId,GoodsMap,Goodsfile,GoodVec);
        for(auto Good:GoodVec)
        {
            if(Good[4] == this->UserId)
            {
                flag = true;
            }
        }

        if(!flag)
           std::cout << "您没有这件商品！" << std::endl;
        else 
           break;
    }

    std::cout << "请输入新的商品描述：";
    std::cin >> ModifyStr;
    GoodData.Modify("Id",GoodId,"Info",ModifyStr,GoodsMap,Goodsfile);
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}