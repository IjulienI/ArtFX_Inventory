#pragma once
#include <iostream>

inline void Clear()
{
    std::cin.clear();
}

inline void Continue()
{
    std::cout << "\nPress enter to continue : \n";
    std::cin.get();
}

inline void PrintLine(std::string pText, bool bIsItem = false)
{    
    if(!bIsItem) std::cout << "----------------------------------\n";
    
    std::cout << "|";    
    int textSize = static_cast<int>(pText.size());
    int loop = 31 - textSize;
    std::cout << pText.c_str();
    for(int i = 0; i <= loop; i++)
    {
        std::cout << " ";
    }    
    std::cout << "|\n";

    if(!bIsItem) std::cout << "----------------------------------\n";
}

inline void PrintCategory(std::string pCategoryName,std::vector<Item*> pItems)
{
    PrintLine(pCategoryName);    
    for(Item* item : pItems)
    {
        PrintLine(item->GetName(), true);
    }
    std::cout << "----------------------------------\n";
}
