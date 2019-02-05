#pragma once
#include <map>
#include <set>
#include "Player.h"
#include "Team.h"

class Team;

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
    void RemoveTeam(Team* team);
    bool SortTeams();
    uint8_t CanBegin() const;
    void HandleSpecCounts(uint8_t specType, bool remove = false);
    void FindGame();
    void SetSelectedWinner(uint8_t index);
    uint8_t GetSelectedWinner() const;
    Team* GetTeam(uint8_t index);
    uint8_t GetTeamsCount() const;


    //uint8_t CreatePlayerID();
    

private:

    PlayerList pList;
    TeamList tList;
    uint8_t healersCount;
    uint8_t damagersCount;
    uint8_t SelectedWinner;

    Team* Game[2];
    //FreeIDList FreeIDs;
};

