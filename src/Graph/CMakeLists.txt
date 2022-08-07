add_library(digraph SHARED digraph.cpp ../basic_lib.cpp ../ext_random.cpp)
target_include_directories(digraph PUBLIC ${CMAKE_SOURCE_DIR}/include/Graph)
