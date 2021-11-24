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

    SelectedWinner = 0;

    Game[0] = nullptr;
    Game[1] = nullptr;
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

    ClearAllTeams();

    healersCount = NULL;
    damagersCount = NULL;
}

void Players::ClearAllTeams()
{
    for (auto itr : tList)
        delete itr;

    tList.clear();
}

void Players::RemoveTeam(Team * team)
{
    for (auto itr : tList)
        itr->RemoveTeamInOponentList(team);

    tList.erase(team);
    delete team;
}

bool Players::SortTeams()
{
    std::vector<std::string*> healers;
    std::vector<std::string*> damagers;

    for (auto& itr : pList)
    {
        if (itr.second->GetSpecType() == SpecHealer)
        {
            healers.push_back(itr.second->GetName());
        }
        else
        {
            damagers.push_back(itr.second->GetName());
        }
    }

    std::random_shuffle(begin(healers), end(healers));
    std::random_shuffle(begin(damagers), end(damagers));

    uint8_t i = 0;

    for (; i < healers.size(); i++)
        tList.insert(new Team(healers[i], damagers[i]));

    for (; i < damagers.size(); i++)
        tList.insert(new Team(damagers[i++], damagers[i]));

    for (auto itr : tList)
        itr->CreateOponentList(tList);

    return false;
}

uint8_t Players::CanBegin() const
{
    size_t playerListSize = pList.size();

    if (playerListSize < MinPlayers)
        return BE_TeamsCount;

    if (!playerListSize || playerListSize % 2 != 0)
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

void Players::FindGame()
{
    uint8_t games = 255;

    for (auto& itr : tList)
    {
        if (itr->GetScore() < games)
        {
            games = itr->GetScore();
            Game[0] = itr;
        }
    }

    if (Game[0] != nullptr)
    {
        if (!Game[0]->HasOponents())
            Game[0]->CreateOponentList(tList);

        Game[1] = Game[0]->FindOponent();

        Game[0]->RemoveTeamInOponentList(Game[1]);
        Game[1]->RemoveTeamInOponentList(Game[0]);
    }
}

void Players::SetSelectedWinner(uint8_t index)
{
    SelectedWinner = index;
}

uint8_t Players::GetSelectedWinner() const
{
    return SelectedWinner;
}

Team * Players::GetTeam(uint8_t index)
{
    if (index < 0 || index > 1)
        return nullptr;

    return Game[index];
}

size_t Players::GetTeamsCount() const
{
    return tList.size();
}

void Players::ReplacePlayer(std::string* oldName, std::string* newName)
{
    auto itr = pList.find(*oldName);

    if (itr != pList.end())
    {
        if (Player* player = itr->second)
        {
            player->SetNewName(*newName);
            pList[*newName] = player;
            pList.erase(itr);
        }
    }
}
