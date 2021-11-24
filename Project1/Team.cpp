#include "Team.h"



Team::Team(std::string* p1, std::string* p2) : player_1(p1), player_2(p2)
{
    Wins = 0;
    Loses = 0;
    Score = 0;
}

Team::~Team()
{

}

void Team::CreateOponentList(std::set<Team*>& opList)
{
    oponentList = opList;
    RemoveTeamInOponentList(this);
}

void Team::RemoveTeamInOponentList(Team * team)
{
    oponentList.erase(team);
}

Team * Team::FindOponent()
{
    Team* op = nullptr;
    uint8_t opScore = 255;

    for (auto& itr : oponentList)
    {
        uint8_t curOpScore = itr->GetScore();

        if (curOpScore >= Score)
        {
            if (curOpScore < opScore)
            {
                opScore = curOpScore;
                op = itr;
            }
        }
    }

    return op;
}

bool Team::HasOponents() const
{
    return !oponentList.empty();
}

std::string * Team::GetPlayerName(uint8_t index)
{
    return index ? player_2 : player_1;
}

void Team::SetWin()
{
    Wins++;
    Score += 2;
}

void Team::SetLose()
{
    Loses++;
    Score++;
}

uint8_t Team::GetLoses() const
{
    return Loses;
}

uint8_t Team::GetWins() const
{
    return Wins;
}

uint8_t Team::GetScore() const
{
    return Score;
}
