#pragma once
#include <iostream>

#include "IReader.hpp"

namespace tee
{
    class StdInReader : public IReader
    {
    public:
        std::string read() override
        {
            std::string result;
            std::string temp;
            while (std::getline(std::cin,temp)) 
            {
                result += temp;
                std::cout << temp << std::endl;
            }
            result += "\n";
            return result;
        }
    };
}