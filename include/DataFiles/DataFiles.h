#pragma once

#ifndef DATAFILES_H
#define DATAFILES_H

#include <fstream>
#include <vector>

class string;
class User;
class Goods;
class Order;

class Datafiles
{
public:
    Datafiles(std::string filename);
    void savedata(const User& user);
    void savedata(const Goods& goods);
    void savedata(const Order& order);
    void savedata(const std::vector<std::vector<std::string>> &vec);
    void getdata(std::vector<std::string>& data);

private:
    std::string filename;
    std::ifstream infile;
    std::ofstream outfile;
};

#endif