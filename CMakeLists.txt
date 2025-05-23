cmake_minimum_required(VERSION 3.20.5)

# Set the C compiler to Clang
set(CMAKE_C_COMPILER "clang")

# Set the C++ compiler to Clang
set(CMAKE_CXX_COMPILER "clang++")

# # Set the desired compiler flags
# set(CMAKE_C_FLAGS "-Wall -Wextra -Og -g")
# set(CMAKE_CXX_FLAGS "-Wall -Wextra -Og -g")

# # Set the C++ standard to C++20
# set(CMAKE_CXX_STANDARD 20)

# # https://stackoverflow.com/questions/47697761/cmake-run-time-error-dyld-library-not-loaded-for-dynamically-linked-resource
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(dyredis_compiler_flags INTERFACE)
target_compile_features(dyredis_compiler_flags INTERFACE cxx_std_20)
target_compile_options(dyredis_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

project(dyredis)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
message(CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
message(CMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
message(PROJECT_BINARY_DIR="${PROJECT_BINARY_DIR}")

