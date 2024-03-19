# gtest
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
#FetchContent_MakeAvailable(googletest)

set(MAIN_TEST_PROJECT_NAME dyr_test)
set(MAIN_TEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/test)
set(MAIN_TEST_COMPILER_FLAGS ${MAIN_TEST_PROJECT_NAME}_compiler_flags)

add_library(${MAIN_TEST_COMPILER_FLAGS} INTERFACE)
target_compile_features(${MAIN_TEST_COMPILER_FLAGS} INTERFACE cxx_std_20)

target_link_libraries(dyr_test gtest)
include_directories(${PROJECT_SOURCE_DIR}/libs/googletest/googletest/include)

add_executable(${MAIN_TEST_PROJECT_NAME}
        ${MAIN_TEST_SOURCE_DIR}/main_test.cpp
        ${MAIN_TEST_SOURCE_DIR}/server_test.cpp
        ${MAIN_TEST_SOURCE_DIR}/client_test.cpp
        )
target_link_libraries(${MAIN_TEST_PROJECT_NAME}
        ${MAIN_APP_COMPILER_FLAGS}
        dyr_client
        dyr_server
        gtest_main
        )
target_include_directories(${MAIN_TEST_PROJECT_NAME} PRIVATE
        ${PROJECT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/server
        ${PROJECT_SOURCE_DIR}/src/client
        )

gtest_discover_tests(${MAIN_TEST_PROJECT_NAME})