#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "MyException/MyException.h"
#include <sstream>
#include <string>
// #include "Data.h"

void Data::find(std::string key, std::string str, std::map<std::string, int> &Map,
                Datafiles &file, std::vector<std::vector<std::string>> &vec)
{
    if (Map.find(key) == Map.end())
    {
        throw MyException("该属性不存在！");
    }
    std::vector<std::string> sum;
    file.getdata(sum);
    std::vector<std::string> temp;
    for (auto _str : sum)
    {
        this->split(_str, ',', temp);
        if (temp.at(Map.find(key)->second) == str)
        {
            vec.push_back(temp);
            temp.clear();
        }
    }
}

void Data::split(std::string str, const char split, std::vector<std::string> &vec)
{
    vec.clear();
    std::stringstream s(str);
    std::string temp;
    while (getline(s, temp, split))
    {
        vec.push_back(temp);
    }
}

void Data::get(Datafiles &file, std::vector<std::vector<std::string>> &vec)
{
    std::vector<std::string> sum;
    file.getdata(sum);
    std::vector<std::string> temp;
    for (auto _str : sum)
    {
        this->split(_str, ',', temp);
        vec.push_back(temp);
        temp.clear();
    }
}

// void Data::Delete(std::string key, std::string str, std::map<std::string, int> &Map, Datafiles &file)
// {
// }
void Data::Delete(std::string key, std::string str, std::map<std::string, int> &Map, Datafiles &file)
{
    if (Map.find(key) == Map.end())
    {
        throw MyException("该属性不存在！");
    }

    std::vector<std::vector<std::string>> AllData;
    std::vector<std::vector<std::string>> NewData;
    this->get(file, AllData);
    for (auto data : AllData)
    {
        if (data.at(Map.find(key)->second) != str)
            NewData.push_back(data);
    }

    file.cleardata();
    file.savedata(NewData);
}

void Data::Modify(std::string Findkey, std::string Findstr, std::string Modifykey, std::string Modifystr,
                  std::map<std::string, int> &Map, Datafiles &file)
{
    if (Map.find(Findkey) == Map.end() || Map.find(Modifykey) == Map.end())
    {
        throw MyException("该属性不存在！");
    }

    std::vector<std::vector<std::string>> AllData;
    std::vector<std::vector<std::string>> NewData;
    this->get(file, AllData);
    for (auto data : AllData)
    {
        if (data.at(Map.find(Findkey)->second) == Findstr)
        {
            data.at(Map.find(Modifykey)->second) = Modifystr;
        }
        NewData.push_back(data);
    }
}