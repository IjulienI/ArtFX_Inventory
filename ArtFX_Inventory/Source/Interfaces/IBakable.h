#pragma once

class Item;

class IBakable
{
public:
    virtual ~IBakable() = default;
    virtual Item* Bake() = 0;
};
