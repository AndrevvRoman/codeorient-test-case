#pragma once
#include <fstream>
#include <string>

#include "IWriter.hpp"

namespace tee
{
    class FileWriter : public IWriter
    {
        public:
        void write(const std::string & fileName, const std::string & fileMessage, const bool rewriteFile = false) override
        {
            std::ofstream output;
            if (rewriteFile)
            {
                output.open(fileName, std::ios::out); 
            }
            else
            {
                output.open(fileName, std::ios::out | std::ios::app); 
            }
            
            if (output.is_open()) 
            {
                output << fileMessage;
            }
            else
            {
                throw std::runtime_error("Can't open file");
            }
            output.close();
        }
    };
}