#pragma once
#ifndef DATA_H
#define DATA_H
#include <map>
#include <vector>

class string;
class Datafiles;
class Data
{
public:
    void find(std::string key, std::string str, std::map<std::string, int> &Map,
              Datafiles &file, std::vector<std::vector<std::string>> &vec);
    void split(std::string str, const char split, std::vector<std::string> &vec);
    void get(Datafiles &file, std::vector<std::vector<std::string>> &vec);
    void Delete(std::string key, std::string str, std::map<std::string, int> &Map,
                Datafiles &file);
    void Modify(std::string Findkey, std::string Findstr, std::string Modifykey, std::string Modifystr,
                std::map<std::string, int> &Map,Datafiles &file);

private:
};

#endif