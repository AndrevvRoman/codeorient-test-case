#include "catch.hpp"
#include "FileWriter.hpp"

using namespace tee;

TEST_CASE("Rewrite_to_file")
{
    FileWriter sut;
    std::string fileName = "test1.txt";
    std::string fileMsg = "Hello world!\n";
    REQUIRE_NOTHROW(sut.write(fileName,fileMsg,true));
    
}

TEST_CASE("Write_to_end_file_exist_file")
{
    FileWriter sut;
    std::string fileName = "test1.txt";
    std::string fileMsg = "Hello world!!";
    REQUIRE_NOTHROW(sut.write(fileName,fileMsg));
}

TEST_CASE("Write_to_end_file_new_file")
{
    FileWriter sut;
    std::string fileName = "test2.txt";
    std::string fileMsg = "Hello world";
    REQUIRE_NOTHROW(sut.write(fileName,fileMsg));
}