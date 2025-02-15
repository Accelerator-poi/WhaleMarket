#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include<string>

// 不同菜单的名称
enum class PageState
{
    MainPage,
    AdminPage,
    UserPage,
    BuyerPage,
    SellerPage,
    InformationPage,
    ModifyPage,
    GoodPage
};

class MainMenu
{
public:
    MainMenu();
    void PageShow();
    void MainHandle(int choice);
    void AdminHandle(int choice);
    void UserHandle(int choice);
    void BuyerHandle(int choice);
    void SellerHandle(int choice);
    void InfoHandle(int choice);
    void ModifyHandle(int choice);
    void GoodHandle(int choice);

    void UserLogin();
    void UserSignIn();
    void AdminLogin();

    void GoodsInfo();
    void SearchGoods();
    void OrdersInfo();
    void UsersInfo();
    void DeleteUser();
    void BanGood();

    void BuyerGoodsInfo();
    void BuyGoods();
    void UserSearchGoods();
    void BuyerViewOrder();
    void ViewGoodsInfo();

    void SellGoods();
    void SellerGoodsInfo();
    // void ModifyGoods();
    void SellerBanGood();
    void SellerViewOrder();

    void GoodModifyName();
    void GoodModifyPrice();
    void GoodModifyInfo();

    void UserModifyPwd();
    void UserModifyTelephone();
    void UserModifyAddress();

    void UserInfomation();
    void UserTopUp();

private:
    PageState currentState = PageState::MainPage;
    std::string UserId = "";
};

#endif