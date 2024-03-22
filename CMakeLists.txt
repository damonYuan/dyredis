cmake_minimum_required(VERSION 3.20.5)

# Set the C compiler to Clang
set(CMAKE_C_COMPILER "clang")

# Set the C++ compiler to Clang
set(CMAKE_CXX_COMPILER "clang++")

# Set the desired compiler flags
set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# https://stackoverflow.com/questions/47697761/cmake-run-time-error-dyld-library-not-loaded-for-dynamically-linked-resource
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)
set(MAIN_PROJECT_NAME dyredis)

project(${MAIN_PROJECT_NAME})

include_directories(src/client)
include_directories(src/server)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
message(CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
message(PROJECT_BINARY_DIR="${PROJECT_BINARY_DIR}")

