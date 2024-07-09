#pragma once
#ifndef DATA_H
#define DATA_H
#include<map>
#include<vector>

class string;
class Datafiles;
class Data
{
    public:
        void find(std::string key,std::string str,std::map<std::string, int> &Map,
                    Datafiles &file,std::vector<std::vector<std::string>> &vec);
        void split(std::string str, const char split, std::vector<std::string> &vec);
    private:
};

#endif