#pragma once
#include <string>

#include "ItemType.h"

class Item
{
public:
    Item(std::string pName, std::uint8_t pType, std::uint8_t pRarity);
    std::string GetName();
    std::uint8_t GetType();
    bool HasTag(ItemType::Type tag) const;

private:
    std::string mName;
    std::uint8_t mType;
};
