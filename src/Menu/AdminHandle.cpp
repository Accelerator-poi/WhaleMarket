#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include <iostream>
#include <iomanip>

void MainMenu::GoodsInfo()
{
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << GoodTile[i];
    }
    std::cout << std::endl;
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    Datafiles file("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    std::vector<std::vector<std::string>> Info;
    Data GoodData;
    GoodData.get(file, Info);
    for (auto Goods : Info)
    {
        for (int i = 0; i < Goods.size(); i++)
        {
            if (i != 3)
            {
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Goods[i];
            }
        }
        std::cout << std::endl;
    }
}

void MainMenu::SearchGoods()
{
    std::string GoodsId;
    bool Istrue = false;
    Datafile file("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodInfo;
    while(!Isture)
    {
        std::cout<< "请输入商品ID:"<<std::endl;
        std::cin>>GoodsId;
        GoodData.find("Id",GoodsId,GoodsMap,file,GoodInfo);
        if(!GoodInfo.empty())
        {
            Istrue = true;
            break;
        }
        std::cout<<"商品Id错误,请重新输入："
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << GoodTile[i];
    }
    std::cout << std::endl;
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    
    for (auto Goods : GoodInfo)
    {
        for (int i = 0; i < Goods.size(); i++)
        {
            if (i != 3)
            {
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Goods[i];
            }
        }
        std::cout << std::endl;
    }
}

void MainMenu::OrdersInfo()
{
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << OrderTile[i];
    }
    std::cout << std::endl;
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    Datafiles file("/home/luffy/WhaleMarket-Framework/data/OrderData.txt");
    std::vector<std::vector<std::string>> Info;
    Data GoodData;
    GoodData.get(file, Info);
    for (auto Goods : Info)
    {
        for (int i = 0; i < Goods.size(); i++)
        {
            std::cout << std::setw(15) << std::setfill(' ') << std::left << Goods[i];
        }
        std::cout << std::endl;
    }
}

void MainMenu::UsersInfo()
{
    std::cout << std::setw(75) << std::setfill('*') << '*' << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << UserTile[i];
    }
    std::cout << std::endl;
    std::cout << std::setw(75) << std::setfill('*') << '*' << std::endl;
    Datafiles file("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    std::vector<std::vector<std::string>> Info;
    Data GoodData;
    GoodData.get(file, Info);
    for (auto Goods : Info)
    {
        for (int i = 0; i < Goods.size(); i++)
        {
            if (i != 2)
            {
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Goods[i];
            }
        }
        std::cout << std::endl;
    }
}