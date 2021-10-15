cmake_minimum_required(VERSION 3.0.0)
project(tee VERSION 0.1.0)

file(GLOB SOURCES
     "app/src/*.cpp"
     "app/src/*.hpp"
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory ("libs/args")

add_executable(${PROJECT_NAME} ${SOURCES} app/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/app/src>
    PRIVATE
    "libs"
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    args
)

add_library(lib${PROJECT_NAME} ${SOURCES})
set_target_properties(lib${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(lib${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/app/src>
    PRIVATE
    "libs"
)
target_link_libraries(lib${PROJECT_NAME}
    PUBLIC
    args
)

add_subdirectory("tests/integrationTests")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
