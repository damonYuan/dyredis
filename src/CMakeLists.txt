project(dyr VERSION 1.0)
configure_file(Config.h.in Config.h)

add_subdirectory(common)
add_subdirectory(client)
add_subdirectory(server)

add_executable(dyr main.cpp)
target_link_libraries(dyr PUBLIC dyr_client_lib dyr_server_lib tutorial_compiler_flags)
target_include_directories(dyr PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS dyr DESTINATION bin)