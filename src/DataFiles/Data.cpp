#include "DataFiles/Data.h"
#include "DataFiles/DataFiles.h"
#include "MyException/MyException.h"
#include <sstream>
#include <string>

void Data::find(std::string key,std::string str,std::map<std::string, int> &Map,
Datafiles &file,std::vector<std::vector<std::string>> &vec)
{
    if(Map.find(key) == Map.end())
    {
        throw MyException("该属性不存在！");
    }
    std::vector<std::string> sum;
    file.getdata(sum);
    std::vector<std::string> temp;
    // const char* key = ",";
    for(auto _str : sum)
    {
        this->split(_str,',',temp);
        if(temp.at(Map.find(key)->second) == str)
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
    while(getline(s,temp,split))
    {
        vec.push_back(temp);
    }
}

