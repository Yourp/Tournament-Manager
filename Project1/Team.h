#pragma once
//#include <iostream>
#include <set>

class Team
{

public:
    Team(std::string* p1, std::string* p2);

    void CreateOponentList(std::set<Team*>& opList, Team* exTeam);
    void RemoveTeamInOponentList(Team* team);

    uint8_t GetLoses() const;
    uint8_t GetWins() const;
    uint8_t GetGames() const;

private:

    std::string* player_1;
    std::string* player_2;
    std::set<Team*> oponentList;

    uint8_t Wins;
    uint8_t Loses;
};