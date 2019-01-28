#include "Players.h"


Players::Players()
{
}

Players::~Players()
{
    ClearAllPlayers();
}

void Players::AddPlayerInList(std::string name, Player * player)
{
    pList[name] = player;
}

void Players::DeletePlayer(std::string name)
{
    auto itr = pList.find(name);

    if (itr != pList.end())
    {
        if (Player* player = itr->second)
        {
            FreeIDs.insert(player->GetID());
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
}

uint8_t Players::CreatePlayerID()
{
    if (!FreeIDs.empty())
    {
        uint8_t id = *FreeIDs.begin();
        FreeIDs.erase(id);
        return id;
    }

    return uint8_t(pList.size() + 1);
}
