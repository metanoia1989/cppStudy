#pragma once

#include "constants.h"
#include <iostream>

namespace util1
{
    void print() 
    {
        std::cout <<"util1::print: " << constants::PICTURE_NUMS << std::endl;
    }
} // namespace util
