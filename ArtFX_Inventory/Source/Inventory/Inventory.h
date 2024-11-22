#pragma once
#include <vector>

#include "../Item/Item.h"

class Inventory
{
public:
    Inventory();

    void AddItem(Item* pItem);
    void AddItems(std::vector<Item*> pItems);
    void RemoveItem(std::string pName);
    void ShowInventory();

private:
    std::vector<Item*> mItems;    
};
