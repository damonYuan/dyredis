cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# https://stackoverflow.com/questions/47697761/cmake-run-time-error-dyld-library-not-loaded-for-dynamically-linked-resource
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

project(dyredis_main)
add_subdirectory(src)
add_subdirectory(test)
enable_testing()

message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
message(CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
