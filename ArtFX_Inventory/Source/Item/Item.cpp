#include "Item.h"

Item::Item(std::string pName): mName(pName)
{
}

std::string Item::GetName()
{
    return mName;
}
