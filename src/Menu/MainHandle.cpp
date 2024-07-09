#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include <iostream>

void MainMenu::UserLogin()
{ 
    Datafiles UserFile("/home/luffy/WhaleMarket-Framework/data/UserData.txt");
    Data UserData;
    std::vector<std::vector<std::string>> UserVec;
    std::string UserName,Password;
    bool Istrue = false;
    while(!Istrue)
    {   
        // UserVec.clear();
        std::cout<<"请输入用户名："<<std::endl;
        std::cin>>UserName;
        std::cout<<"请输入密码："<<std::endl;
        std::cin>>Password;
    
        UserData.find("Name",UserName,UserMap,UserFile,UserVec);

        if(UserVec.size() == 0)
        {
            std::cout<<"用户名错误，请重试！"<<std::endl;
            std::cout<<"****************************"<<std::endl;
        }

        for(auto _user : UserVec)
        {
            if(_user[2] == Password)
            {    
                this->UserId = _user[0];
                Istrue = true;
                break;
            }
            std::cout<<"密码错误，请重试！"<<std::endl;
            std::cout<<"****************************"<<std::endl;
            
        }
    }
    std::cout<<"****************************"<<std::endl;
    this->currentState = PageState::UserPage;
}
