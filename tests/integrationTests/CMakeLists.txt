cmake_minimum_required(VERSION 3.6)

project(tee-integration-tests LANGUAGES CXX)

set(TEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FileWriter.cpp
   )

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${TEST_SOURCES}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} libtee)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    "libs/Catch/single_include/"
    "src"
)
