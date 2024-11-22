#pragma once

class Item;

class IBakable
{
public:
    virtual ~IBakable() = default;
    virtual void Bake() = 0;
};
