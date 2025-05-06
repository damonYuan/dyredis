add_library(dyr_common_lib STATIC common.cpp)
target_include_directories(dyr_common_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})