#pragma once

#include "config.h"
#include <map>
#include <string>

// 不同菜单的提示信息
static const char *menuPrompts[MENU_NUM] = {"\
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

// 三个键值对，txt文件索引与对应下标
extern std::map<std::string, int> UserMap;
extern std::map<std::string, int> GoodsMap;
extern std::map<std::string, int> OrderMap;

//页面选项数
//extern int PageNum[MENU_NUM] = {4,7,4,6,6,4,4,4};
extern int PageNum[MENU_NUM];

//各项信息显示长度
extern int GoodBuffer[6];

//各表表头
static const char* GoodTile[6] = {"GoodId","Name","Price","SellerId","Time","State"};
static const char* OrderTile[6] = {"Id","GoodId","Price","Time","BuyerId","SellerId"};
static const char* UserTile[5] = {"Id","Name","Telephone","Address","Balance"};