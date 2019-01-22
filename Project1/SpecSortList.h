#pragma once

#include <map>


class SpecSortList
{

public:

    SpecSortList();

    void AddHealer(std::string Name);
    void AddDamager(std::string Name);

private:

    std::map<unsigned int, std::string> HealerList;
    std::map<unsigned int, std::string> DamagerList;
};

