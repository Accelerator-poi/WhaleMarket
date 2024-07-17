#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "User/User.h"
#include <iostream>
#include <iomanip>

void MainMenu::MainHandle(int choice)
{
    switch (choice)
    {
    case 1:
        UserLogin();
        break;
    case 2:
        UserSignIn();
        break;
    case 3:
        AdminLogin();
        break;
    case 4:
        exit(0);
        break;
    }
}

void MainMenu::UserLogin()
{
    std::cout << "****************************" << std::endl;
    Datafiles UserFile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::string UserName, Password;
    bool Istrue = false;
    while (!Istrue)
    {
        // UserVec.clear();
        std::cout << "请输入用户名：";
        std::cin >> UserName;
        std::cout << "请输入密码：";
        std::cin >> Password;

        UserData.find("Name", UserName, UserMap, UserFile, UserVec);

        if (UserVec.empty())
        {
            std::cout << "用户名错误，请重试！" << std::endl;
            std::cout << "****************************" << std::endl;
        }

        for (auto _user : UserVec)
        {
            if (_user[2] == Password)
            {
                this->UserId = _user[0];
                Istrue = true;
                break;
            }
            std::cout << "密码错误，请重试！" << std::endl;
            std::cout << "****************************" << std::endl;
        }
    }
    std::cout << "****************************" << std::endl;
    this->currentState = PageState::UserPage;
}

void MainMenu::UserSignIn()
{
    std::cout << "****************************" << std::endl;
    bool Istrue = false;
    Datafiles UserFile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::vector<std::string> UserInfo;
    std::string UserName, Password;

    while (!Istrue)
    {
        UserVec.clear();
        std::cout << "请输入用户名：";
        std::cin >> UserName;
        UserData.find("Name", UserName, UserMap, UserFile, UserVec);
        if (UserVec.empty())
        {
            Istrue = true;
            break;
        }
        std::cout << "此用户名已被占用！";
        std::cout << "****************************" << std::endl;
    }

    std::cout << "请输入密码：";
    std::cin >> Password;
    UserFile.getdata(UserInfo);
    int UserNum = UserInfo.size();
    std::ostringstream oss;
    oss << "U" << std::setfill('0') << std::setw(5) << UserNum;
    std::string UserId = oss.str();
    User NewUser(UserId.c_str(), UserName.c_str(), Password.c_str(), "NULL", "NULL", 0);
    UserFile.savedata(NewUser);
    std::cout << "注册成功！" << std::endl;
    std::cout << "****************************" << std::endl;
}

void MainMenu::AdminLogin()
{
    std::cout << "****************************" << std::endl;
    std::string AdminName, Password;
    std::string RightName = "Admin";
    std::string RightPwd = "123456";
    bool Istrue = false;
    while (!Istrue)
    {
        std::cout << "请输入管理员账号:";
        std::cin >> AdminName;
        std::cout << "请输入管理密码：";
        std::cin >> Password;
        if (AdminName == RightName && Password == RightPwd)
        {
            Istrue = true;
            std::cout << "登陆成功！" << std::endl;
            this->currentState = PageState::AdminPage;
            break;
        }
        std::cout << "账号或密码错误，请重试：" << std::endl;
        std::cout << "****************************" << std::endl;
    }
    std::cout << "****************************" << std::endl;
}