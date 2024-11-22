#include "Item.h"

Item::Item(std::string pName, std::uint8_t pType, std::uint8_t pRarity): mName(pName), mType(pType)
{
    mType += pRarity;
}

std::string Item::GetName()
{
    return mName;
}

std::uint8_t Item::GetType()
{
    return mType;
}

bool Item::HasTag(ItemType::Type tag) const
{
    return mType == tag;
}
