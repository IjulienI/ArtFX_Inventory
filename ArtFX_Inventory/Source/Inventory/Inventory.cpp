#include "Inventory.h"

#include "../CommandBase.h"
#include "../OverrideVector.h"

Inventory::Inventory()
{
    Item* hello = new Item("oui", ItemType::Type::Armor, ItemType::Type::Rare);
    mItems += hello;
    Item* hello1 = new Item("Excalibur", ItemType::Type::Weapon, ItemType::Type::Legendary);
    mItems += hello1;

    Refresh();
}

void Inventory::AddItem(Item* pItem)
{
    Clear();
    mItems += pItem;
    std::cout << "You put " << pItem->GetName().c_str() << " in your inventory\n";
    Continue();
}

void Inventory::AddItems(std::vector<Item*> pItems)
{
    Clear();
    for(Item* item : pItems)
    {
        mItems += pItems;
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
            mItems -= item;
            std::cout << "You drop " << item->GetName().c_str() << "\n";
            Continue();
            return;
        }
    }
    std::cout << "You don't have this item in your inventory \n";
    Continue();
}

void Inventory::Refresh()
{
    //Sort Items

    weapons.clear();
    armors.clear();
    rings.clear();
    potions.clear();
    foods.clear();
    
    for(Item* item : mItems)
    {
        if(item->HasTag(ItemType::Type::Weapon) ) weapons += item;
        if(item->HasTag(ItemType::Type::Armor) ) armors += item;
        if(item->HasTag(ItemType::Type::Ring) ) rings += item;
        if(item->HasTag(ItemType::Type::Potion) ) potions += item;
        if(item->HasTag(ItemType::Type::Food) ) foods += item;
    }
}

void Inventory::ShowInventory(bool bContinue)
{
    Refresh();
    Clear();
    //Weapons
    PrintCategory("WEAPON",weapons);
    //Armor
    PrintCategory("ARMOR",armors);
    //Ring
    PrintCategory("RING",rings);
    //Potion
    PrintCategory("POTION",potions);
    //Food
    PrintCategory("FOOD",foods);
    
    if(bContinue) Continue();
}

void Inventory::DropItem()
{
    ShowInventory(false);
    std::cout << "\nWhich item do you want to drop (enter item name) :\n";
    std::string choice;
    std::cin.clear();
    getline(std::cin, choice);
    RemoveItem(choice);
}
