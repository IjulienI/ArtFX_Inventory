#include "Food.h"

Food::Food(std::string pName, std::uint8_t pType, std::uint8_t pRarity, uint8_t pFoodType) : Item(pName,pType,pRarity), mFoodType(pFoodType)
{
}

void Food::Bake()
{
}

uint8_t Food::GetFoodType()
{
    return mFoodType;
}
