#pragma once
#include <map>
#include <set>
#include "Player.h"
#include "Team.h"

typedef std::map<std::string, Player*> PlayerList;
typedef std::map<uint8_t, Team*> TeamList;
typedef std::set<uint8_t> FreeIDList;


class Players
{

public:
    Players();
    ~Players();

    void AddPlayerInList(std::string name, Player* player);
    void DeletePlayer(std::string name);
    void ClearAllPlayers();

    uint8_t CreatePlayerID();
    

private:

    PlayerList pList;
    TeamList tList;
    FreeIDList FreeIDs;
};

