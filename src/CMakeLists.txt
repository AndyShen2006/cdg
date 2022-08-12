add_subdirectory(Graph)
add_subdirectory(cdg)

add_library(ext_random ext_random.cpp basic_lib.cpp)
target_include_directories(ext_random PUBLIC ${CMAKE_SOURCE_DIR}../include)

add_library(basic_lib basic_lib.cpp ext_random.cpp)
target_include_directories(basic_lib PUBLIC ${CMAKE_SOURCE_DIR}../include)