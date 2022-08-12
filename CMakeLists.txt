cmake_minimum_required(VERSION 3.16.3)

project(cdg)

# Compile options
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-fno-asm -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Show message
message("cdg2.0dev-A data generator based on C++")
if(${CMAKE_BUILD_TYPE} STREQUAL DEBUG)
    message("Optional:-fno-asm -std=c++11 -Wall -stdlib=libstdc++ -g -Og, Type:Debug")
else(${CMAKE_BUILD_TYPE} STREQUAL RELEASE)
    message("Optional:-fno-asm -std=c++11 -Wall -stdlib=libstdc++ -O2, Type:Release")
endif(${CMAKE_BUILD_TYPE} STREQUAL DEBUG)

add_subdirectory(src)

# Install options

# Library
install(TARGETS ext_random basic_lib undigraph
        ARCHIVE DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include)

# Executable files
#install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
#        DESTINATION include)

add_executable(test test/test.cpp)
target_link_libraries(test ext_random basic_lib undigraph)