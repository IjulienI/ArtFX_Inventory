#pragma once
#include <vector>

#include "../Item/Item.h"

class Inventory
{
public:
    Inventory();

    void AddItem(Item* pItem, bool bSilent = false);
    void AddItems(std::vector<Item*> pItems);
    void ShowInventory(bool bContinue = true);

    void DeleteItem(std::string pName);
    void DropItem();
    std::vector<Item*> GetFood();
    Item* GetItem(std::string pItemName);

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
