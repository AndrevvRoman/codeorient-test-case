#pragma once
#include <string>

namespace tee
{
    class IReader
    {
        public:
        virtual std::string read() = 0;
        ~IReader() = default;
    };
}