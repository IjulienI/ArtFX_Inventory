#pragma once
#include <vector>

#include "../Item/Item.h"

class Inventory
{
public:
    Inventory();

    void AddItem(Item* pItem);
    void AddItems(std::vector<Item*> pItems);
    void ShowInventory(bool bContinue = true);

    void DropItem();

private:
    std::vector<Item*> mItems;

    std::vector<Item*> weapons;
    std::vector<Item*> armors;
    std::vector<Item*> rings;
    std::vector<Item*> potions;
    std::vector<Item*> foods;
    
    void RemoveItem(std::string pName);
    void Refresh();
};
