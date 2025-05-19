add_library(dyr_client_lib client.cpp)
target_link_libraries(dyr_client_lib PUBLIC dyr_common_lib dyredis_compiler_flags)
target_include_directories(dyr_client_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(dyr_client_lib PRIVATE "EXPORTING_DYREDIS")

# install libs
set(installable_libs dyr_client_lib dyredis_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
# install include headers
install(FILES client.h DESTINATION include)