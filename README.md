README
====

# Project Structure

```
.
├── CMakeLists.txt
├── README.md
├── lib
├── src
│   ├── CMakeLists.txt
│   ├── Config.h.in
│   ├── client
│   │   └── CMakeLists.txt
│   └── server
│       └── CMakeLists.txt
└── test
    └── CMakeLists.txt
```

[C++ project setup with CMake & unit tests (google test)](https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html)

# Build Commands

```
cmake -S . -B build; cmake --build build --clean-first; cmake --build build --target test
```
or
```
cmake -S . -B build
cmake --build build --clean-first
cmake --build build --target test
cmake --install build --prefix ~/cbin
// or you can find the binary in build folder
dyredis
```

# Test
[googletest](https://github.com/google/googletest) is used.
```
cmake -S . -B build; cmake --build build --target test
cd build
ctest
```

# TODO

1. using the [libev](https://github.com/enki/libev)

