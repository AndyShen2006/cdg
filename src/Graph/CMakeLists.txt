add_library(undigraph undigraph.cpp ../basic_lib.cpp ../ext_random.cpp)
target_include_directories(undigraph PUBLIC ${CMAKE_SOURCE_DIR}/include/Graph)
