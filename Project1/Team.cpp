#include "Team.h"



Team::Team(std::string* p1, std::string* p2) : player_1(p1), player_2(p2)
{

}

void Team::CreateOponentList(std::set<Team*>& opList, Team* exTeam)
{
    oponentList = opList;
    RemoveTeamInOponentList(exTeam);
}

void Team::RemoveTeamInOponentList(Team * team)
{
    oponentList.erase(team);
}

uint8_t Team::GetLoses() const
{
    return Loses;
}

uint8_t Team::GetWins() const
{
    return Wins;
}

uint8_t Team::GetGames() const
{
    return Wins + Loses;
}
