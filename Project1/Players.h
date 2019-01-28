#pragma once
#include <map>
#include <set>
#include "Player.h"
#include "Team.h"

typedef std::map<std::string, Player*> PlayerList;
typedef std::set<Team*> TeamList;
//typedef std::set<uint8_t> FreeIDList;


class Players
{

public:
    Players();
    ~Players();

    void AddPlayerInList(std::string name, Player* player);
    void DeletePlayer(std::string name);
    void ClearAllPlayers();
    void ClearAllTeams();
    bool SortTeams();
    uint8_t CanBegin() const;
    void HandleSpecCounts(uint8_t specType, bool remove = false);


    //uint8_t CreatePlayerID();
    

private:

    PlayerList pList;
    TeamList tList;
    uint8_t healersCount;
    uint8_t damagersCount;
    //FreeIDList FreeIDs;
};

