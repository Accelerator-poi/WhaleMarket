#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include <iostream>

MainMenu::MainMenu()
{
    this->currentState = PageState::MainPage;
    int choice;
    while(true)
    {
        PageShow();
        std::cout<<"请输入选项:";
        std::cin>>choice;
        switch(this->currentState)
        {
            case PageState::MainPage:
                MainHandle(choice);
                break;
            case PageState::AdminPage:
                AdminHandle(choice);
                break;
            case PageState::UserPage:
                UserHandle(choice);
                break;
            case PageState::BuyerPage:
                BuyerHandle(choice);
                break;
            case PageState::SellerPage:
                SellerHandle(choice);
                break;
            case PageState::InformationPage:
                InfoHandle(choice);
                break;
            case PageState::ModifyPage:
                ModifyHandle(choice);
                break;
            case PageState::GoodPage:
                GoodHandle(choice);
                break;
        }
    }
}

void MainMenu::PageShow()
{
    switch(this->currentState)
    {
        case PageState::MainPage:
            std::cout<<menuPrompts[0];
            break;
        case PageState::AdminPage:
            std::cout<<menuPrompts[1];
            break;
        case PageState::UserPage:
            std::cout<<menuPrompts[2];
            break;
        case PageState::BuyerPage:
            std::cout<<menuPrompts[3];
            break;
        case PageState::SellerPage:
            std::cout<<menuPrompts[4];
            break;
        case PageState::InformationPage:
            std::cout<<menuPrompts[5];
            break;
        case PageState::ModifyPage:
            std::cout<<menuPrompts[6];
            break;
        case PageState::GoodPage:
            std::cout<<menuPrompts[7];
            break;
    }
}
