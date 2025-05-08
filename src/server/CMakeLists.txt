add_library(dyr_server_lib STATIC server.cpp)
target_link_libraries(dyr_server_lib PUBLIC dyr_common_lib dyredis_compiler_flags)
target_include_directories(dyr_server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# install libs
set(installable_libs dyr_server_lib dyredis_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
# install include headers
install(FILES server.h DESTINATION include)

