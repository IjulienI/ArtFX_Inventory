#include "Inventory.h"

#include "../CommandBase.h"
#include "../OverrideVector.h"
#include "../Item/FoodType.h"
#include "../Item/Childs/Food.h"

Inventory::Inventory()
{
    Food* Beef = new Food("Beef", ItemType::Type::Food, ItemType::Type::Rare,FoodType::Meat);
    mItems += Beef;
    Food* Salad = new Food("Salad", ItemType::Type::Food, ItemType::Type::Rare,FoodType::Vegetable);
    mItems += Salad;
    Item* Excalibur = new Item("Excalibur", ItemType::Type::Weapon, ItemType::Type::Legendary);
    mItems += Excalibur;
    Item* EldenRing = new Item("TheEldenRing", ItemType::Type::Ring, ItemType::Type::Legendary);
    mItems += EldenRing;
    Item* HaloRond = new Item("HaloRond", ItemType::Type::Ring, ItemType::Type::Common);
    mItems += HaloRond;

    Refresh();
}

void Inventory::AddItem(Item* pItem, bool bSilent)
{
    if(!bSilent) Clear();
    mItems += pItem;
    std::cout << "You put " << pItem->GetName().c_str() << " in your inventory\n";
    if(!bSilent) Continue();
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
    
    Item* tempItem = GetItem(pName);
    if(tempItem)
    {        
        mItems -= tempItem;
        std::cout << "You drop " << tempItem->GetName().c_str() << "\n";
        Continue();
        return;
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

void Inventory::DeleteItem(std::string pName)
{
    mItems -= GetItem(pName);
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

std::vector<Item*> Inventory::GetFood()
{
    return foods;
}

Item* Inventory::GetItem(std::string pName)
{
    for(Item* item : mItems)
    {
        if(item->GetName() == pName)
        {
            return item;
        }
    }
    return nullptr;
}
