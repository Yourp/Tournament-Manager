#include "Players.h"
#include "MyForm.h"
#include "Team.h"
#include <algorithm>
#include <vector>
#include <ctime>


Players::Players()
{
    std::srand(uint32_t(time(NULL)));

    healersCount = NULL;
    damagersCount = NULL;
}

Players::~Players()
{
    ClearAllPlayers();
    ClearAllTeams();
}

void Players::AddPlayerInList(std::string name, Player * player)
{
    pList[name] = player;
    HandleSpecCounts(player->GetSpecType());
}

void Players::DeletePlayer(std::string name)
{
    auto itr = pList.find(name);

    if (itr != pList.end())
    {
        if (Player* player = itr->second)
        {
            HandleSpecCounts(player->GetSpecType(), true);
            //FreeIDs.insert(player->GetID());
            pList.erase(itr);
            delete player;
        }
    }
}

void Players::ClearAllPlayers()
{
    for (auto itr : pList)
        delete itr.second;

    pList.clear();

    healersCount = NULL;
    damagersCount = NULL;
}

void Players::ClearAllTeams()
{
    for (auto itr : tList)
        delete itr;

    tList.clear();
}

bool Players::SortTeams()
{
    std::vector<std::string> healers;
    std::vector<std::string> damagers;

    for (auto& itr : pList)
    {
        if (itr.second->GetSpecType() == SpecHealer)
        {
            healers.push_back(itr.first);
        }
        else
        {
            damagers.push_back(itr.first);
        }
    }

    std::random_shuffle(begin(healers), end(healers));
    std::random_shuffle(begin(damagers), end(damagers));

    uint8_t i = 0;

    for (; i < healers.size(); i++)
        tList.insert(new Team(&healers[i], &damagers[i]));

    for (; i < damagers.size(); i++)
        tList.insert(new Team(&damagers[i++], &damagers[i]));

    for (auto itr : tList)
        itr->CreateOponentList(tList, itr);

    return false;
}

uint8_t Players::CanBegin() const
{
    if (pList.empty() || pList.size() % 2 != 0)
        return BE_PlayersCount;

    if (healersCount > damagersCount)
        return BE_HealersCount;

    return BE_None;
}

void Players::HandleSpecCounts(uint8_t specType, bool remove)
{
    if (specType == SpecHealer)
    {
        healersCount = remove ? --healersCount : ++healersCount;
        return;
    }

    damagersCount = remove ? --damagersCount : ++damagersCount;
}

// uint8_t Players::CreatePlayerID()
// {
//     if (!FreeIDs.empty())
//     {
//         uint8_t id = *FreeIDs.begin();
//         FreeIDs.erase(id);
//         return id;
//     }
// 
//     return uint8_t(pList.size() + 1);
// }
