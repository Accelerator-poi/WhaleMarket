#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"
#include <iostream>

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
        case PageState::InformatioPage:
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

void MainMenu::MainHandle(int choice)
{
    switch(choice)
    {
        // case 1:

    }    
}