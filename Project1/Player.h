#pragma once
#include <iostream>

enum PlayerSpecType
{
    SpecDamager,
    SpecHealer
};

class Player
{
public:
    Player(uint8_t specType, std::string name);

    std::string* GetName();
    void SetNewName(std::string newName);

    uint8_t GetSpecType();
private:

    uint8_t SpecType;
    std::string Name;
};

