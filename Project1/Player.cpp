#include "Player.h"



Player::Player(uint8_t specType, uint8_t id) : SpecType(specType), ID(id)
{

}

uint8_t Player::GetID()
{
    return ID;
}
