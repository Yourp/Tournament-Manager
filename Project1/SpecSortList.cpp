#include "SpecSortList.h"



SpecSortList::SpecSortList()
{

}

void SpecSortList::AddHealer(std::string Name)
{
    unsigned int index = 0;

    for (auto itr : HealerList)
        index++;
    
    HealerList[index] = Name;
}

void SpecSortList::AddDamager(std::string Name)
{
    unsigned int index = 0;

    for (auto itr : DamagerList)
        index++;

    DamagerList[index] = Name;
}
