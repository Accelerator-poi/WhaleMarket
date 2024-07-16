#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "Goods/Goods.h"
#include "MyException/MyException.h"
#include <iostream>
#include <iomanip>

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
        ModifyGoods();
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
    if(this->UserId == "")
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
    while(ture)
    {
        std::cout << "请输入商品价格：";
        std::cin >> GoodPrice;
        if(GoodPrice <= 0)
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
    ostringstream oss;


}