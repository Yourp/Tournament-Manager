#pragma once

#include <map>


class SpecSortList
{

public:

    SpecSortList();

    void AddHealer(std::string Name);
    void AddDamager(std::string Name);

private:

    std::map<uint8_t, std::string> HealerList;
    std::map<uint8_t, std::string> DamagerList;
};

