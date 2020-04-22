#pragma once

#include <iostream>

namespace constants
{
    const int PICTURE_NUMS = 5; 
    class Number
    {
    public:
        Number()
        {
            std::cout << "Number constructed" << std::endl; 
        }
    };
    const Number price;
} // namespace constants