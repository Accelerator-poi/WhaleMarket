#include "Menu/MenuShow.h"

std::map<std::string, int> UserMap = {{"Id", 0}, {"Name", 1}, {"Password", 2}, {"Telephone", 3}, {"Address", 4}, {"Balance", 5}};
std::map<std::string, int> GoodsMap = {{"Id", 0}, {"Name", 1}, {"Price", 2}, {"Info", 3}, {"SellerId", 4}, {"Time", 5}, {"State", 6}};
std::map<std::string, int> OrderMap = {{"Id", 0}, {"GoodsId", 1}, {"Price", 2}, {"Time", 3}, {"SellerId", 4}, {"BuyerId", 5}};

int PageNum[MENU_NUM] = {4,7,4,6,6,4,4,4};