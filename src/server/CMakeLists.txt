add_library(dyr_server_lib STATIC server.cpp)
target_link_libraries(dyr_server_lib PUBLIC dyr_common_lib dyredis_compiler_flags)
target_include_directories(dyr_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

