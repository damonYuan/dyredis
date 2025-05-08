add_executable(dyr_test main.cpp main_test.cpp server_test.cpp client_test.cpp common_test.cpp)
add_test(NAME dyr_test COMMAND dyr_test)
target_link_libraries(dyr_test PUBLIC dyr_server_lib dyr_client_lib gtest dyredis_compiler_flags)
target_include_directories(dyr_test PRIVATE ${PROJECT_BINARY_DIR})


