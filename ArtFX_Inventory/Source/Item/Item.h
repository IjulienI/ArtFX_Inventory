#pragma once
#include <string>

class Item
{
public:
    Item(std::string pName);
    std::string GetName();

private:
    std::string mName = "";
};
