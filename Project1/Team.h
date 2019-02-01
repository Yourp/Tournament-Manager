#pragma once
//#include <iostream>
#include <set>

class Team
{

public:
    Team(std::string* p1, std::string* p2);
    ~Team();

    void CreateOponentList(std::set<Team*>& opList, Team* exTeam);
    void RemoveTeamInOponentList(Team* team);
    Team* FindOponent();
    std::string* GetPlayerName(uint8_t index);

    uint8_t GetLoses() const;
    uint8_t GetWins() const;
    uint8_t GetScore() const;

private:

    std::string* player_1;
    std::string* player_2;
    std::set<Team*> oponentList;

    uint8_t Wins;
    uint8_t Loses;
    uint8_t Score;
};