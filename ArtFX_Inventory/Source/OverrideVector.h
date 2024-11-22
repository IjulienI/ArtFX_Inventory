#pragma once
#include <vector>

class Item;

inline std::vector<Item*> operator + (std::vector<Item*> itemsVector, Item* item)
{
    itemsVector.push_back(item);
    return itemsVector;
}

inline void operator += (std::vector<Item*>& itemsVector, Item* item)
{
    itemsVector.push_back(item);
}

inline std::vector<Item*> operator + (std::vector<Item*> a, std::vector<Item*> b)
{
    for(Item* item : b)
    {
        a + item;
    }
    return a;
}

inline void operator += (std::vector<Item*>& a, std::vector<Item*> b)
{
    for(Item* item : b)
    {
        a += item;
    }
}

inline std::vector<Item*> operator - (std::vector<Item*> itemsVector, Item* item)
{
    itemsVector.erase(find(itemsVector.begin(),itemsVector.end(),item));
    return itemsVector;
}

inline void operator -= (std::vector<Item*>& itemsVector, Item* item)
{
    itemsVector.erase(find(itemsVector.begin(),itemsVector.end(),item));
}