#include <iostream>
#include <memory>

#include "args.hxx"

#include "Endpoints.hpp"

tee::Endpoints::Args parseArgs(int argc, char* argv[])
{
    tee::Endpoints::Args result;
    args::ArgumentParser parser("Tee application for writting files.", "");
    args::HelpFlag help(parser, "help", "Display this help menu", { 'h', "help" });
    args::ValueFlag<std::string> fileName(parser, "NAME", "Input file name", { 'n', "fileName" });
    args::Flag rewriteFile(parser, "APPEND", "Set appending to end of file", { 'a' });

    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch(const args::RequiredError&)
    {
        std::cerr << "File name and text reqired" << std::endl;
        std::cout << parser;
        std::exit(1);
    }
    catch (const args::Help&)
    {
        std::cout << parser;
        std::exit(0);
    }
    catch (const args::ParseError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        std::exit(1);
    }
    result.fileName = args::get(fileName);
    result.rewriteFile = args::get(rewriteFile);

    return result;
}

int main(int argc, char** argv) 
{
    tee::Endpoints endpoints;
    endpoints.start(parseArgs(argc, argv));
    return 0;
}
