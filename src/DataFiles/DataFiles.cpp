#include "DataFiles/DataFiles.h"
#include "MyException/MyException.h"
#include "User/User.h"
#include "Goods/Goods.h"
#include "Order/Order.h"
#include <string>

Datafiles::Datafiles(std::string filename)
{
    this->filename = filename;
}

void Datafiles::savedata(const User &user)
{
    outfile.open(this->filename, std::ios::app);
    infile.open(this->filename);
    if (!outfile.is_open() || !infile.is_open())
        throw MyException("文件打开失败");
    if (infile.peek() == std::ifstream::traits_type::eof())
        outfile << "Id,Name,Pwd,Telephone,Address,Balance" << std::endl;
    outfile << user.GetId() << "," << user.GetName() << "," << user.GetPwd() << ","
            << user.GetTelephone() << "," << user.GetAddress() << "," << user.GetBalance()
            << std::endl;
    outfile.close();
    outfile.clear();
    infile.close();
    infile.close();
}

void Datafiles::savedata(const Goods &goods)
{
    outfile.open(this->filename, std::ios::app);
    infile.open(this->filename);
    if (!outfile.is_open() || !infile.is_open())
        throw MyException("文件打开失败");
    if (infile.peek() == std::ifstream::traits_type::eof())
        outfile << "GoodsId,Name,Price,Info,SellerId,Time,State" << std::endl;
    outfile << goods.GetGoodsId() << "," << goods.GetName() << "," << goods.GetPrice()
            << "," << goods.GetInfo() << "," << goods.GetSellerId() << ","
            << goods.GetTime() << "," << stateprompte[goods.GetState()] << std::endl;
    outfile.close();
    outfile.clear();
    infile.close();
    infile.clear();
}

void Datafiles::savedata(const Order &order)
{
    outfile.open(this->filename, std::ios::app);
    infile.open(this->filename);
    if (!outfile.is_open() || !infile.is_open())
        throw MyException("文件打开失败");
    if (infile.peek() == std::ifstream::traits_type::eof())
        outfile << "OrderId,GoodsId,Price,Time,SellerId,BuyerId" << std::endl;
    outfile << order.GetOrderId() << "," << order.GetGoodsId() << ","
            << order.GetPrice() << "," << order.GetTime() << ","
            << order.GetSellerId() << "," << order.GetBuyerId() << std::endl;
    outfile.close();
    outfile.clear();
    infile.close();
    infile.close();
}

void Datafiles::savedata(const std::vector<std::vector<std::string>> &vec)
{
    outfile.open(this->filename, std::ios::app);
    infile.open(this->filename);
    if (!outfile.is_open() || !infile.is_open())
        throw MyException("文件打开失败");
    for (auto infovec : vec)
    {
        for (auto info : infovec)
        {
            if (info != infovec.back())
                outfile << info << ",";
            else
                outfile << info << std::endl;
        }
    }
    outfile.close();
    outfile.clear();
    infile.close();
    infile.clear();
}

void Datafiles::getdata(std::vector<std::string> &data)
{
    data.clear();
    infile.open(this->filename);
    if (!infile.is_open())
        throw MyException("文件打开失败");
    std::string line;
    getline(infile, line); // 去除第一行
    while (getline(infile, line))
    {
        data.push_back(line);
    }
    infile.close();
    infile.clear();
}

void Datafiles::cleardata()
{
    std::string tile = "";
    infile.open(this->filename);
    if (!infile.is_open())
    {
        throw MyException("文件打开失败");
    }
    std::string line;
    getline(infile, line);
    infile.close();
    infile.clear();
    outfile.open(this->filename);
    if (!outfile.is_open())
    {
        throw MyException("文件打开失败");
    }
    outfile << line << std::endl;
    outfile.close();
    outfile.clear();
}

// const char *Datafiles::getfilename()
// {
//     return this->filename.c_str();
// }
