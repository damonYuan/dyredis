# gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

set(MAIN_APP_TEST_PROJECT_NAME dyredis_test)
set(MAIN_APP_TEST_SOURCE_DIR ${CMAKE_SOURCE_DIR}/test)
include(GoogleTest)

add_executable(${MAIN_APP_TEST_PROJECT_NAME}
        ${MAIN_APP_TEST_SOURCE_DIR}/main_test.cpp
        ${MAIN_APP_TEST_SOURCE_DIR}/server_test.cpp
        ${MAIN_APP_TEST_SOURCE_DIR}/client_test.cpp
        )
target_link_libraries(${MAIN_APP_TEST_PROJECT_NAME} gtest_main)
target_include_directories(${MAIN_APP_TEST_PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

gtest_discover_tests(${MAIN_APP_TEST_PROJECT_NAME})