#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include <iostream>
#include <iomanip>

void MainMenu::AdminHandle(int choice)
{
    switch (choice)
    {
    case 1:
        GoodsInfo();
        break;
    case 2:
        SearchGoods();
        break;
    case 3:
        OrdersInfo();
        break;
    case 4:
        UsersInfo();
        break;
    case 5:
        DeleteUser();
        break;
    case 6:
        BanGood();
        break;
    case 7:
        currentState = PageState::MainPage;
        break;
    default:
        break;
    }

}

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
        for (int i = 0; i < int(Goods.size()); i++)
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
    Datafiles file("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodInfo;
    while (!Istrue)
    {
        std::cout << "请输入商品ID:";
        std::cin >> GoodsId;
        GoodData.find("Id", GoodsId, GoodsMap, file, GoodInfo);
        if (!GoodInfo.empty())
        {
            Istrue = true;
            break;
        }
        std::cout << "商品Id错误,请重新输入：";
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
        for (int i = 0; i < int(Goods.size()); i++)
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
        for (int i = 0; i < int(Goods.size()); i++)
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
        for (int i = 0; i < int(Goods.size()); i++)
        {
            if (i != 2)
            {
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Goods[i];
            }
        }
        std::cout << std::endl;
    }
}

void MainMenu::DeleteUser()
{
    std::string UserId;
    Datafiles Userfile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Datafiles Goodfile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data data;
    bool Istrue = false;
    std::vector<std::vector<std::string>> Uservec;
    std::cout << std::setw(75) << std::setfill('*') << '*' << std::endl;
    while(!Istrue)
    {
        std::cout<<"请输入用户Id:";
        std::cin>>UserId;
        data.find("Id",UserId,UserMap,Userfile,Uservec);
        if(!Uservec.empty())
        {
            Istrue = true;
            break;
        }
        std::cout<<"查无此人,请检查Id是否正确!"<<std::endl;
    }
    data.Delete("Id",UserId,UserMap,Userfile);
    data.Modify("SellerId",UserId,"State","已下架",GoodsMap,Goodfile);    
    std::cout<<"删除成功!"<<std::endl;
    std::cout << std::setw(75) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::BanGood()
{
    std::string GoodId;
    Datafiles Goodfile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data data;
    bool Istrue = false;
    std::vector<std::vector<std::string>> Goodvec;
    std::cout << std::setw(75) << std::setfill('*') << '*' << std::endl;
    while(!Istrue)
    {
        std::cout<<"请输入商品Id:";
        std::cin>>GoodId;
        data.find("Id",GoodId,GoodsMap,Goodfile,Goodvec);
        if(!Goodvec.empty())
        {
            Istrue = true;
            break;
        }
        std::cout<<"未找到该商品,请检查Id是否正确!"<<std::endl;
    }
    data.Modify("Id",GoodId,"State","已下架",GoodsMap,Goodfile);
    std::cout<<"下架成功!"<<std::endl;
    std::cout << std::setw(75) << std::setfill('*') << '*' << std::endl;
}