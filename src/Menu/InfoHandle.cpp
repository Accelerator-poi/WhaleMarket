#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "MyException/MyException.h"

#include <iostream>
#include <iomanip>

void MainMenu::InfoHandle(int choice)
{
    switch(choice)
    {
        case 1:
            UserInfomation();
            break;
        case 2:
            currentState = PageState::ModifyPage;
            break;
        case 3:
            UserTopUp();
            break;
        case 4:
            currentState = PageState::UserPage;
            break;
        default:
            break;
    }
}

void MainMenu::UserInfomation()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::vector<std::vector<std::string>> UserVec;
    Datafiles Userfile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    UserData.find("Id",this->UserId,UserMap,Userfile,UserVec);
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout <<"Id:" << UserVec[0][0] << std::endl;
    std::cout <<"Name:" << UserVec[0][1] << std::endl;
    std::cout <<"Telephone:" << UserVec[0][3] << std::endl;
    std::cout <<"Address:" << UserVec[0][4] << std::endl;
    std::cout <<"Balance:" << UserVec[0][5] << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::UserTopUp()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    float UserBalance;
    Datafiles Userfile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout << "请输入充值金额:";
    std::cin >> UserBalance;
    UserData.find("Id",this->UserId,UserMap,Userfile,UserVec);
    UserData.Modify("Id",this->UserId,"Balance",std::to_string(std::stof(UserVec[0][5]) + UserBalance),UserMap,Userfile);
    std::cout << "充值成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}