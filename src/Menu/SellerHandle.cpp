#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "Goods/Goods.h"
#include "MyException/MyException.h"
#include <iostream>
#include <iomanip>
// #include <format>
#include <ctime>

void MainMenu::SellerHandle(int choice)
{
    switch (choice)
    {
    case 1:
        SellGoods();
        break;
    case 2:
        SellerGoodsInfo();
        break;
    case 3:
        currentState = PageState::GoodPage;
        break;
    case 4:
        SellerBanGood();
        break;
    case 5:
        SellerViewOrder();
        break;
    case 6:
        currentState = PageState::UserPage;
        break;
    default:
        break;
    }
}

void MainMenu::SellGoods()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string GoodName, GoodInfo;
    float GoodPrice;
    std::vector<std::string> tempvec;
    Datafiles Goodsfile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");

    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout << "请输入商品名称：";
    std::cin >> GoodName;
    while (true)
    {
        std::cout << "请输入商品价格：";
        std::cin >> GoodPrice;
        if (GoodPrice <= 0)
        {
            std::cout << "价格不能为负数！" << std::endl;
        }
        else
        {
            break;
        }
    }
    std::cout << "请输入商品描述: ";
    std::cin >> GoodInfo;

    Goodsfile.getdata(tempvec);
    int GoodNum = tempvec.size();
    std::string GoodId;
    std::ostringstream oss;
    oss << 'G' <<std::setw(5) << std::setfill('0') << GoodNum;
    GoodId = oss.str();

    time_t now;
    time(&now);
    tm *ltm = localtime(&now);
    std::string Time = std::to_string(ltm->tm_year + 1900) + "-" + std::to_string(ltm->tm_mon + 1) + "-" + std::to_string(ltm->tm_mday);

    Goods NewGood(GoodId.c_str(), GoodName.c_str(), GoodPrice, GoodInfo.c_str(), this->UserId.c_str(), Time.c_str(), 2);
    Goodsfile.savedata(NewGood);
    std::cout << "商品添加成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::SellerGoodsInfo()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }
    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;
    GoodData.find("SellerId", this->UserId, GoodsMap, GoodFile, GoodVec);
    if (GoodVec.empty())
    {
        std::cout << "无商品！" << std::endl;
        return;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << GoodTile[i];
    }
    std::cout << std::endl;
    for (auto Good : GoodVec)
    {
        for (int i = 0; i < int(Good.size() - 1); i++)
        {
            if(i <=2)
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Good[i];
            else
                std::cout << std::setw(15) << std::setfill(' ') << std::left << Good[i+1];
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::ModifyGoods()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;
    GoodData.find("SellerId", this->UserId, GoodsMap, GoodFile, GoodVec);
    std::string GoodId;
    bool flag = false;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;

    while (true)
    {
        std::cout << "请输入商品ID:" << std::endl;
        std::cin >> GoodId;

        for (auto Good : GoodVec)
        {
            if (Good[0] == GoodId)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            std::cout << "您没有这件商品！" << std::endl;
        }
        else
        {
            break;
        }
    }
    int choice;
    std::string ModifyStr;
    flag = false;
    while (true)
    {
        std::cout << "请选择要修改的信息：" << std::endl;
        std::cout << "1.商品名称" << std::endl;
        std::cout << "2.商品价格" << std::endl;
        std::cout << "3.商品描述" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "请输入新的商品名称：" << std::endl;
            std::cin >> ModifyStr;
            flag = true;
            break;
        case 2:
            std::cout << "请输入新的商品价格：" << std::endl;
            std::cin >> ModifyStr;
            flag = true;
            break;
        case 3:
            std::cout << "请输入新的商品描述：" << std::endl;
            std::cin >> ModifyStr;
            flag = true;
            break;
        default:
            std::cout << "输入错误！" << std::endl;
            break;
        }
        if (flag)
        {
            break;
        }
    }

    switch (choice)
    {
    case 1:
        GoodData.Modify("Id", GoodId, "Name", ModifyStr, GoodsMap, GoodFile);
        break;
    case 2:
        GoodData.Modify("Id", GoodId, "Price", ModifyStr, GoodsMap, GoodFile);
        break;
    case 3:
        GoodData.Modify("Id", GoodId, "Info", ModifyStr, GoodsMap, GoodFile);
        break;
    default:
        throw MyException("选项不合法!");
        break;
    }
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::SellerBanGood()
{
    if (this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    Datafiles GoodFile("/home/luffy/WhaleMarket-Framework/data/GoodData.txt");
    Data GoodData;
    std::vector<std::vector<std::string>> GoodVec;
    GoodData.find("SellerId", this->UserId, GoodsMap, GoodFile, GoodVec);
    std::string GoodId;
    bool flag = false;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;

    while (true)
    {
        std::cout << "请输入商品ID:";;
        std::cin >> GoodId;

        for (auto Good : GoodVec)
        {
            if (Good[0] == GoodId)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            std::cout << "您没有这件商品！" << std::endl;
        }
        else
        {
            break;
        }
    }

    if (GoodVec[0][6] == "销售中")
    {
        GoodData.Modify("Id", GoodId, "State", "已下架", GoodsMap, GoodFile);
        std::cout << "商品已下架！" << std::endl;
    }
    else
        std::cout << "此商品不在销售中,无法下架!" << std::endl;

    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::SellerViewOrder()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    Datafiles OrderFile("/home/luffy/WhaleMarket-Framework/data/OrderData.txt");
    Data OrderData;
    std::vector<std::vector<std::string>> OrderVec;
    OrderData.find("SellerId", this->UserId, OrderMap, OrderFile, OrderVec);
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;

    if(OrderVec.empty())
    {
        std::cout << "您没有历史订单!" << std::endl;
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << OrderTile[i];
    }
    std::cout << std::endl;

    for(auto Order : OrderVec)
    {
        for(int i = 0; i < int(Order.size()); i++)
        {
            std::cout << std::setw(15) << std::setfill(' ') << std::left << Order[i];
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(90) << std::setfill('*') << '*' << std::endl;
}