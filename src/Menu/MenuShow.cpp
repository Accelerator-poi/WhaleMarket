#include "Menu/MenuShow.h"

const char *menuPrompts[MENU_NUM] = {"\
+==============+================+===============+========+\n\
| 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |\n\
+==============+================+===============+========+\n",
                                            "\
+=========+==========+==========+=========+==========+=======+========+\n\
| 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |\n\
+=========+==========+==========+=========+==========+=======+========+\n",
                                            "\
+=========+==========+==============+========+\n\
| 1.Buyer | 2.Seller | 3.Infomation | 4.Back |\n\
+=========+==========+==============+========+\n",
                                            "\
+=========+=======+==========+=========+===============+========+\n\
| 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Information | 6.Back |\n\
+=========+=======+==========+=========+===============+========+\n",
                                            "\
+========+=========+==========+=======+=========+========+\n\
| 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |\n\
+========+=========+==========+=======+=========+========+\n",
                                            "\
+===============+==========+==========+========+\n\
| 1.Information | 2.Modify | 3.Top Up | 4.Back |\n\
+===============+==========+==========+========+\n",
                                            "\
+============+===========+===========+========+\n\
| 1.Password | 2.Contact | 3.Address | 4.Back |\n\
+============+===========+===========+========+\n",
                                            "\
+========+=========+===============+========+\n\
| 1.Name | 2.Price | 3.Description | 4.Back |\n\
+========+=========+===============+========+\n"};

std::map<std::string, int> UserMap = {{"Id", 0}, {"Name", 1}, {"Password", 2}, {"Telephone", 3}, {"Address", 4}, {"Balance", 5}};
std::map<std::string, int> GoodsMap = {{"Id", 0}, {"Name", 1}, {"Price", 2}, {"Info", 3}, {"SellerId", 4}, {"Time", 5}, {"State", 6}};
std::map<std::string, int> OrderMap = {{"Id", 0}, {"GoodsId", 1}, {"Price", 2}, {"Time", 3}, {"SellerId", 4}, {"BuyerId", 5}};

int PageNum[MENU_NUM] = {4,7,4,6,6,4,4,4};

// int GoodBuffer[6] = {10,15,10,15,10,15};

// char* GoodTile[6] = {'GoodId','Name','Price','SellerId','Time','State'};
const char* GoodTile[6] = {"GoodId","Name","Price","SellerId","Time","State"};
const char* OrderTile[6] = {"Id","GoodId","Price","Time","BuyerId","SellerId"};
const char* UserTile[5] = {"Id","Name","Telephone","Address","Balance"};