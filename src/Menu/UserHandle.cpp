#include "Menu/MainMenu.h"
#include "Menu/MenuShow.h"

void MainMenu::UserHandle(int choice)
{
    switch (choice)
    {
        case 1:
            this->currentState = PageState::BuyerPage;
            break;
        case 2:
            this->currentState = PageState::SellerPage;
            break;
        case 3:
            this->currentState = PageState::InformatioPage;
            break;
        case 4:
            this->currentState = PageState::MainPage;
            break;
        default:
            break;
    }
}


