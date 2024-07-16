#include <iostream>
#include <functional>
#include "User/User.h"
#include "MyException/MyException.h"
#include "Buffer/Buffer.h"
#include "DataFiles/DataFiles.h"
#include "DataFiles/Data.h"
#include "Menu/MenuShow.h"
#include "Menu/MainMenu.h"

extern "C"
{
    void welcomeMessage();
    void invalidMessage();
}

int main()
{
    welcomeMessage();
    invalidMessage();

    // const char* Id = "id";
    // const char* Name = "name";
    // const char* Pwd = "pwd";
    // const char* Telephone = "telephone";
    // const char* Address = "address";
    // const User user(Id,Name,Pwd,Telephone,Address,1.1);

    // Datafiles data("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    // auto savedata_bind = [&data](const User* user){data.savedata(*user);};
    // ErrorFunction("data执行保存失败",savedata_bind,&user);
    // Data MyData;
    // std::vector<std::vector<std::string>> vec;
    // MyData.find("Id","id",UserMap,data,vec);
    // data.savedata(vec);
    // for(auto _vec : vec)
    // {
    //     for(auto _str : _vec)
    //     {
    //         std::cout<<_str<<" ";
    //     }
    //     std::cout<<std::endl;
    // };
    int num;
    MainMenu menu;
    menu.PageShow();
    std::cin>>num;
    menu.MainHandle(num);
    menu.PageShow();
    return 0;
}
