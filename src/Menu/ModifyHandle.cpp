#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "MyException/MyException.h"

#include <iostream>
#include <iomanip>

void MainMenu::ModifyHandle(int choice)
{
    switch(choice)
    {
        case 1:
            UserModifyPwd();
            break;
        case 2:
            UserModifyTelephone();
            break;
        case 3:
            UserModifyAddress();
            break;
        case 4:
            currentState = PageState::InformationPage;
            break;
        default:
            break;
    }
}

void MainMenu::UserModifyPwd()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string UserPwd;
    Datafiles Userfile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout << "请输入新密码:";
    std::cin >> UserPwd;
    UserData.Modify("Id",this->UserId,"Password",UserPwd,UserMap,Userfile);
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::UserModifyTelephone()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string UserTelephone;
    Datafiles Userfile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout << "请输入新电话:";
    std::cin >> UserTelephone;
    UserData.Modify("Id",this->UserId,"Telephone",UserTelephone,UserMap,Userfile);
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}

void MainMenu::UserModifyAddress()
{
    if(this->UserId == "")
    {
        throw MyException("未登录!");
        return;
    }

    std::string UserAddress;
    Datafiles Userfile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
    std::cout << "请输入新地址:";
    std::cin >> UserAddress;
    UserData.Modify("Id",this->UserId,"Address",UserAddress,UserMap,Userfile);
    std::cout << "修改成功！" << std::endl;
    std::cout << std::setw(40) << std::setfill('*') << '*' << std::endl;
}