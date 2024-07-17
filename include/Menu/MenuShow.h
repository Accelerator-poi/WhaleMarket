#pragma once

#include "config.h"
#include <map>
#include <string>

// 不同菜单的提示信息
extern const char* menuPrompts[MENU_NUM];

// 三个键值对，txt文件索引与对应下标
extern std::map<std::string, int> UserMap;
extern std::map<std::string, int> GoodsMap;
extern std::map<std::string, int> OrderMap;

//页面选项数
extern int PageNum[MENU_NUM];

//各项信息显示长度
extern int GoodBuffer[6];

//各表表头
extern const char* GoodTile[6];
extern const char* OrderTile[6];
extern const char* UserTile[5];