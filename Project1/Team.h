#pragma once
#include <iostream>

class Team
{

public:
    Team(std::string* p1, std::string* p2);

private:

    std::string* player_1;
    std::string* player_2;
};

