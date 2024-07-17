#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "Order/Order.h"
#include "MyException/MyException.h"
#include <iostream>
#include <iomanip>
// #include <format>
#include <ctime>

void MainMenu::BuyerHandle(int choice)
{
    switch (choice)
    {
    case 1:
        BuyerGoodsInfo();
        break;
    case 2:
        BuyGoods();
        break;
    case 3:
        UserSearchGoods();
        break;
    case 4:
        BuyerViewOrder();
        break;
    case 5:
        ViewGoodsInfo();
        break;
    case 6:
        currentState = PageState::UserPage;
        break;
    default:
        break;
    }
}

void MainMenu::BuyerGoodsInfo()
{
    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;
    GoodData.find("State", "销售中", GoodsMap, GoodFile, GoodVec);
    if (GoodVec.empty())
    {
        std::cout << "无商品！" << std::endl;
        return;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << GoodTile[i];
    }
    std::cout << std::endl;
    for (auto Good : GoodVec)
    {
        for (int i = 0; i < int(Good.size() - 2); i++)
        {
            if(i <3)
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Good[i];
            else    
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Good[i+1];
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::BuyGoods()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }
    std::string GoodId;
    std::cout << "请输入商品ID:";
    std::cin >> GoodId;
    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;
    GoodData.find("Id", GoodId, GoodsMap, GoodFile, GoodVec);
    if (GoodVec.empty())
    {
        std::cout << "商品不存在！" << std::endl;
        return;
    }
    if (GoodVec[0][5] == "已下架")
    {
        std::cout << "商品已下架！" << std::endl;
        return;
    }
    if (GoodVec[0][4] == this->UserId)
    {
        std::cout << "不能购买自己的商品！" << std::endl;
        return;
    }
    std::string Price = GoodVec[0][2];
    Datafiles UserFile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    UserData.find("Id", UserId, UserMap, UserFile, UserVec);
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    if (std::stod(UserVec[0][5]) < std::stod(Price))
    {
        std::cout << "余额不足！" << std::endl;
        return;
    }
    std::string LastBalance = std::to_string(std::stod(UserVec[0][5]) - std::stod(Price));
    UserData.Modify("Id", this->UserId, "Balance", LastBalance, UserMap, UserFile);

    time_t now;
    time(&now);
    tm *ltm = localtime(&now);
    std::string Time = std::to_string(ltm->tm_year + 1900) + "-" + std::to_string(ltm->tm_mon + 1) + "-" + std::to_string(ltm->tm_mday);

    std::vector<std::string> tempvec;
    Datafiles OrderFile("/home/luffy/WhaleMarket-Framework/data/OrderData.txt");
    OrderFile.getdata(tempvec);
    int OrderNum = tempvec.size();
    std::ostringstream oss;
    oss << 'O' << std::setfill('0') << std::setw(5) << OrderNum;
    std::string OrderId = oss.str();
    Order NewOrder(OrderId.c_str(), GoodId.c_str(), std::stof(Price),
                    Time.c_str(), GoodVec[0][4].c_str(), this->UserId.c_str());
    OrderFile.savedata(NewOrder);
    GoodData.Modify("Id", GoodId, "State", "已售出", GoodsMap, GoodFile);
    UserData.find("Id", GoodVec[0][4], UserMap, UserFile, UserVec);
    float SellerBalance = std::stof(UserVec[0][5]) + std::stof(Price);
    UserData.Modify("Id", GoodVec[0][4], "Balance", 
                    std::to_string(SellerBalance), UserMap, UserFile);

    std::cout << "购买成功！" << std::endl;
    std::cout << "订单号：" << OrderId << std::endl;
    std::cout << "您的余额为：" << LastBalance << std::endl;
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;


}

void MainMenu::UserSearchGoods()
{
    std::string SearchKey;
    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout << "请输入商品名" << std::endl;
    std::cin >> SearchKey;
    GoodData.find("Name", SearchKey, GoodsMap, GoodFile, GoodVec);
    for (int i = 0; i < int(GoodVec.size()); i++)
    {
        if (GoodVec[i][5] != "销售中")
        {
            GoodVec.erase(GoodVec.begin() + i);
        }
    }

    if (GoodVec.empty())
    {
        std::cout << "此商品不存在或已下架" << std::endl;
        return;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << GoodTile[i];
    }
    for (auto Good : GoodVec)
    {
        for (int i = 0; i < int(Good.size() - 1); i++)
        {
            std::cout << std::setw(15) << std::setfill(' ') << std::left << Good[i];
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::BuyerViewOrder()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    Datafiles OrderFile("/home/luffy/WhaleMarket-Framework/data/OrderData.txt");
    Data OrderData;
    std::vector<std::vector<std::string>> OrderVec;
    OrderData.find("BuyerId", this->UserId, OrderMap, OrderFile, OrderVec);
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    if (OrderVec.empty())
    {
        std::cout << "无订单！" << std::endl;
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << OrderTile[i];
    }
    std::cout << std::endl;

    for (auto Order : OrderVec)
    {
        for (int i = 0; i < int(Order.size()); i++)
        {
            std::cout << std::setw(15) << std::setfill(' ') << std::left << Order[i];
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::ViewGoodsInfo()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;

    std::string GoodId;
    std::cout << "请输入商品ID:" << std::endl;
    std::cin >> GoodId;
    GoodData.find("Id", GoodId, GoodsMap, GoodFile, GoodVec);

    if (GoodVec.empty())
    {
        std::cout << "商品不存在！" << std::endl;
        return;
    }

    if (GoodVec[0][6] != "销售中")
    {
        std::cout << "商品已下架！" << std::endl;
        return;
    }
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;

    std::cout << std::setw(15) << std::setfill(' ') << std::left
              << "商品名:" << GoodVec[0][1] << std::endl;
    std::cout << std::setw(15) << std::setfill(' ') << std::left
              << "价格:" << GoodVec[0][2] << std::endl;
    std::cout << std::setw(15) << std::setfill(' ') << std::left
              << "介绍:" << GoodVec[0][3] << std::endl;
    std::cout << std::setw(15) << std::setfill(' ') << std::left
              << "卖家ID:" << GoodVec[0][4] << std::endl;
    std::cout << std::setw(15) << std::setfill(' ') << std::left
              << "上架时间:" << GoodVec[0][5] << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}