#pragma once
//#include <iostream>
#include <set>

enum TeamParam
{
    MaxLoses = 2,
};

class Team
{

public:
    Team(std::string* p1, std::string* p2);
    ~Team();

    void CreateOponentList(std::set<Team*>& opList);
    void RemoveTeamInOponentList(Team* team);
    Team* FindOponent();
    bool HasOponents() const;
    std::string* GetPlayerName(uint8_t index);
    void SetWin();
    void SetLose();

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