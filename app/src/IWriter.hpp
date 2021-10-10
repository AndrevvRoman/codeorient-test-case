#pragma once
#include <string>

namespace tee
{
    class IWriter
    {
        public:
        virtual void write(const std::string & fileName, const std::string & message, const bool rewriteFile = false) = 0;
        ~IWriter() = default;
    };
}