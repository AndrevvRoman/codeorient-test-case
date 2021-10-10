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
            char temp;
            temp = getchar();
            while(temp != EOF)
            {
                result += temp;
                temp = getchar();
            }
            return result;
        }
    };
}