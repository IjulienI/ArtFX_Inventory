#include <iostream>

#include "Inventory/Inventory.h"

Inventory* mInventory = new Inventory();

void Menu();

bool bExit;

int main()
{
    while (!bExit)
    {        
        Menu();
    }
    return -1;
}

void Menu()
{
    system("cls");
    std::cout << "----------------------------------\n";
    std::cout << "| 1- Inventory                   |\n";
    std::cout << "| 2- Drop Item                   |\n";
    std::cout << "| 3- Cook                        |\n";
    std::cout << "| 4- Exit                        |\n";
    std::cout << "----------------------------------\n";
    std::cout << "\nChoose your category : ";
    int choice;
    std::cin.clear();
    std::cin >> choice;
    std::cin.get();
    switch (choice)
    {
        case 1:
            mInventory->ShowInventory();
            break;
        case 2:
            mInventory->DropItem();
            break;
        case 3:
            break;
        case 4:
            bExit = true;
            break;
    }
}