#pragma once
#include <string>
#include <memory>

#include "IWriter.hpp"
#include "IReader.hpp"
#include "FileWriter.hpp"
#include "StdInReader.hpp"

namespace tee
{
    class Endpoints
    {
    public:
        struct Args
        {
            std::string fileName;
            bool rewriteFile = false;
        };

        Endpoints()
        {
            m_fileWriter = std::make_shared<FileWriter>();
            m_stdInReader = std::make_shared<StdInReader>();
        }
        void start(const Args& args)
        {
            std::string in = m_stdInReader->read();
            m_fileWriter->write(args.fileName, in, !args.rewriteFile);
        }
    private:
        std::shared_ptr<IWriter> m_fileWriter;
        std::shared_ptr<IReader> m_stdInReader;
    };
}