#pragma once
#include "../CommandBase.h"
#include "../Interfaces/IBakable.h"
#include "../Inventory/Inventory.h"
#include "../Item/FoodType.h"
#include "Item/Childs/Food.h"

Item* MixFood(Food* a, Food* b);

inline void Cook(Inventory* inventory)
{
    Clear();
    PrintCategory("FOOD", inventory->GetFood());
    bool bHaveFood = !(inventory->GetFood().size() < 2);
    std::cout << (bHaveFood? "\nWhich item do you want to add to pot (enter item name) :\n" : "\nNot enough food...\n");
    if(!bHaveFood)
    {
        Continue();
        return;
    }

    Item* a = nullptr;
    Item* b = nullptr;
    
    std::string choice1;
    std::cin.clear();
    getline(std::cin, choice1);    
    a = inventory->GetItem(choice1);
    std::cout << "Choose an other item (again item name pleaaassseeee!)\n";
    std::string choice2;
    std::cin.clear();
    getline(std::cin, choice2);
    b = inventory->GetItem(choice2);
    if(a == b)
    {
        while(a == b)
        {
            std::cout << "You can't cook an item with himself (again item name pleaaassseeee!)\n";
            std::cin.clear();
            getline(std::cin, choice2);
            b = inventory->GetItem(choice2);
        }
    }
    inventory->DeleteItem(a->GetName());
    inventory->DeleteItem(b->GetName());
    
    Item* newItem = MixFood(static_cast<Food*>(a),static_cast<Food*>(b));
    inventory->AddItem(newItem, true);

    uint8_t itemRarity = newItem->GetType();
    std::string rarity;
    if(itemRarity == ItemType::Common) rarity = "Common";
    if(itemRarity == ItemType::Rare) rarity = "Rare";
    if(itemRarity == ItemType::Legendary) rarity = "Legendary";

    Clear();
    std::cout << "You get : " << newItem->GetName().c_str() << "\n";
    std::cout << "Rarity : " << rarity.c_str() << "\n";
    Continue();
}

inline Item* MixFood(Food* a, Food* b)
{
    auto* i = a;
    auto* j = b;
    
    if(i->GetFoodType() == FoodType::Meat && j->GetFoodType() == FoodType::Vegetable)
    {
        return new Item("Soup",ItemType::Food,ItemType::Common);
    }
    if(j->GetFoodType() == FoodType::Meat && i->GetFoodType() == FoodType::Vegetable)
    {
        return new Item("CesarSalad",ItemType::Food,ItemType::Legendary);
    }
    
    if(i->GetFoodType() == FoodType::Mushroom && j->GetFoodType() == FoodType::Vegetable)
    {
        return new Item("MushroomSoup",ItemType::Food,ItemType::Common);
    }
    if(j->GetFoodType() == FoodType::Mushroom && i->GetFoodType() == FoodType::Vegetable)
    {
        return new Item("VegetarianLasagna",ItemType::Food,ItemType::Legendary);
    }

    if(i->GetFoodType() == FoodType::Mushroom && j->GetFoodType() == FoodType::Meat)
    {
        return new Item("SteakPorcini",ItemType::Food,ItemType::Rare);
    }
    if(j->GetFoodType() == FoodType::Mushroom && i->GetFoodType() == FoodType::Meat)
    {
        return new Item("VealBlanquette",ItemType::Food,ItemType::Legendary);
    }

    if(i->GetFoodType() == FoodType::Condiment && j->GetFoodType() == FoodType::Meat)
    {
        return new Item("MustardRoastPork",ItemType::Food,ItemType::Rare);
    }
    if(j->GetFoodType() == FoodType::Condiment && i->GetFoodType() == FoodType::Meat)
    {
        return new Item("BurgerBBQ",ItemType::Food,ItemType::Common);
    }

    if(i->GetFoodType() == FoodType::Condiment && j->GetFoodType() == FoodType::Vegetable)
    {
        return new Item("SaladVinaigrette",ItemType::Food,ItemType::Common);
    }
    if(j->GetFoodType() == FoodType::Condiment && i->GetFoodType() == FoodType::Vegetable)
    {
        return new Item("GrilledVegetablesPesto",ItemType::Food,ItemType::Rare);
    }

    if(i->GetFoodType() == FoodType::Condiment && j->GetFoodType() == FoodType::Mushroom)
    {
        return new Item("CreamyMushrooms",ItemType::Food,ItemType::Common);
    }
    if(j->GetFoodType() == FoodType::Condiment && i->GetFoodType() == FoodType::Mushroom)
    {
        return new Item("MushroomPizza",ItemType::Food,ItemType::Legendary);
    }
    return nullptr;
}
