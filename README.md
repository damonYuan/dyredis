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

# Build Commands

```
cmake -S . -B build; cmake --build build --clean-first; cmake --build build --target test
```
or
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
cmake --build build --clean-first
cmake --build build --target test
cmake --install build --prefix ~/cbin
// or you can find the binary in build folder
dyr
```

# Test
[googletest](https://github.com/google/googletest) is used following [C++ project setup with CMake & unit tests (google test)](https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html).
```
cmake -S . -B build; cmake --build build --target test
cd build
ctest
```

# TODO

1. using the [libev](https://github.com/enki/libev)
2. integrate with boost [std::string to lowercase or uppercase in C++](https://raymii.org/s/snippets/std_string_to_lowercase_or_uppercase_in_cpp.html)

