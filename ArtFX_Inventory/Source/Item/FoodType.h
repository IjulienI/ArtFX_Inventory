#pragma once
#include <cstdint>

namespace FoodType
{    
    enum Type
    {
        Meat = 1 << 0,
        Vegetable = 1 << 1,
        Condiment = 1 << 2,
        Mushroom = 1 << 3
    };
}

inline uint8_t operator +(uint8_t a, FoodType::Type b)
{
    return a | b;
}

inline uint8_t operator -(uint8_t a, FoodType::Type b)
{
    return a ^ b;
}

inline void operator +=(uint8_t& a, FoodType::Type b)
{
    a |= b;
}

inline void operator -=(uint8_t& a, FoodType::Type b)
{
    a ^= b;
}

inline bool operator ==(uint8_t a, FoodType::Type b)
{
    return a & b;
}