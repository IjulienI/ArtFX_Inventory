#pragma once
#include "../Item.h"
#include "../../Interfaces/IBakable.h"

class Food : public Item, public IBakable
{
public:
    Food(std::string pName, std::uint8_t pType, std::uint8_t pRarity, std::uint8_t pFoodType);
    void Bake() override;
    uint8_t GetFoodType();

private:
    uint8_t mFoodType;
};
