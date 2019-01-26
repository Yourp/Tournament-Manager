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
    Player(uint8_t specType, uint8_t id);

    uint8_t GetID();

private:

    uint8_t SpecType;
    uint8_t ID;
};

