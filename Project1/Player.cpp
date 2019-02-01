#include "Player.h"



Player::Player(uint8_t specType, std::string name) : SpecType(specType), Name(name)
{

}

std::string * Player::GetName()
{
    return &Name;
}

uint8_t Player::GetSpecType()
{
    return SpecType;
}
