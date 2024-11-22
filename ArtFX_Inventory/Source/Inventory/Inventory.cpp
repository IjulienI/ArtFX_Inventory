#include "Inventory.h"

#include "../CommandBase.h"

Inventory::Inventory()
{
}

void Inventory::AddItem(Item* pItem)
{
    Clear();
    mItems.insert(mItems.begin(), pItem);
    std::cout << "You put " << pItem->GetName().c_str() << " in your inventory\n";
    Continue();
}

void Inventory::AddItems(std::vector<Item*> pItems)
{
    Clear();
    for(Item* item : pItems)
    {
        mItems.insert(mItems.begin(),item);
        std::cout << "You put " << item->GetName().c_str() << " in your inventory\n";
    }
    Continue();
}

void Inventory::RemoveItem(std::string pName)
{
    Clear();
    for(Item* item : mItems)
    {
        if(item->GetName() == pName)
        {
            mItems.erase(find(mItems.begin(),mItems.end(),item));
            std::cout << "You drop " << item->GetName().c_str() << "\n";
            Continue();
            return;
        }
    }
    std::cout << "You don't have this item in your inventory \n";
    Continue();
}

void Inventory::ShowInventory()
{
    Item* hello = new Item("MangeCulCaca");
    mItems.push_back(hello);
    Clear();
    //Weapons
    PrintCategory("WEAPON",mItems);
    
    Continue();
}
