#pragma once
#include <cstdint>

namespace ItemType
{    
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
}

inline uint8_t operator +(uint8_t a, ItemType::Type b)
{
    return a | b;
}

inline uint8_t operator -(uint8_t a, ItemType::Type b)
{
    return a ^ b;
}

inline void operator +=(uint8_t& a, ItemType::Type b)
{
    a |= b;
}

inline void operator -=(uint8_t& a, ItemType::Type b)
{
    a ^= b;
}

inline bool operator ==(uint8_t a, ItemType::Type b)
{
    return a & b;
}