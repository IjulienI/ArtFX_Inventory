#pragma once

class IBakable
{
public:
    virtual ~IBakable() = default;
    virtual void Bake() = 0;    
};
