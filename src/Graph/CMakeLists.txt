add_library(graph graph.cpp ../basic_lib.cpp ../ext_random.cpp)
target_include_directories(graph PUBLIC ${CMAKE_SOURCE_DIR}/include/Graph)
add_library(digraph digraph.cpp graph.cpp ../basic_lib.cpp ../ext_random.cpp)
target_include_directories(digraph PUBLIC ${CMAKE_SOURCE_DIR}/include/Graph)
