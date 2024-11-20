#pragma once
#include <cstdint>

enum Type
{
    Weapon = 1 << 0,
    Armor = 1 << 1,
    Ring = 1 << 2,
    Potion = 1 << 3,
    Food = 1 << 4,
    
    Common = 1 << 5,
    Rare = 1 << 6,
    Legendary = 1 << 7
};
