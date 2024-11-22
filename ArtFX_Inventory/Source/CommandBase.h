#pragma once
#include <iostream>

#include "Item/ItemType.h"

inline void Clear()
{
    system("cls");
}

inline void Continue()
{
    std::cout << "\nPress enter to continue : \n";    
    std::cin.get();    
    std::cin.clear();
}

inline void PrintLine(std::string pText, bool bIsItem = false, uint8_t pRarity = 0)
{
    if(!bIsItem) std::cout << "----------------------------------\n";
    
    std::cout << "|";    
    int textSize = static_cast<int>(pText.size());
    int loop = 31 - textSize;
    std::string rarityText = "Legendary";
    if(bIsItem)
    {
        if(pRarity == ItemType::Type::Common) rarityText = "Common";
        else if(pRarity == ItemType::Type::Rare) rarityText = "Rare";
        else if(pRarity == ItemType::Type::Legendary) rarityText = "Legendary";
    }
    int raritySize =  static_cast<int>(rarityText.size());
    std::cout << pText.c_str();
    for(int i = 0; i <= (bIsItem? loop - raritySize : loop) ; i++)
    {
        std::cout << " ";
    }
    if(bIsItem) std::cout << rarityText.c_str();
    std::cout << "|\n";

    if(!bIsItem) std::cout << "----------------------------------\n";
}

inline void PrintCategory(std::string pCategoryName,std::vector<Item*> pItems)
{
    if(pItems.empty()) return;
    PrintLine(pCategoryName);    
    for(Item* item : pItems)
    {
        PrintLine(item->GetName(), true, item->GetType());
    }
    std::cout << "----------------------------------\n";
}
