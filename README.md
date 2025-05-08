README
====

[Build Your Own Redis with C/C++](https://build-your-own.org/redis/)

# Project Structure

```
.
├── CMakeLists.txt
├── compose.yml
├── Dockerfile
├── lib
│   ├── boost
│   ├── googletest
│   └── libev
├── README.md
├── src
│   ├── client
│   │   ├── client.cpp
│   │   ├── client.h
│   │   └── CMakeLists.txt
│   ├── CMakeLists.txt
│   ├── common
│   │   ├── CMakeLists.txt
│   │   ├── common.cpp
│   │   └── common.h
│   ├── Config.h.in
│   ├── main.cpp
│   └── server
│       ├── CMakeLists.txt
│       ├── server.cpp
│       └── server.h
└── test
    ├── client_test.cpp
    ├── CMakeLists.txt
    ├── main.cpp
    ├── main_test.cpp
    └── server_test.cpp
```

# Build Commands

```
cmake -S . -B build; cmake --build build --clean-first; cmake --build build --target test
```
or
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
cmake --build build --clean-first
cmake --build build --target test
cmake --install build --config Debug --prefix ~/cbin
cmake --install build --config Release --prefix ~/cbin
// or you can find the binary in build folder
dyr
```

# Test
[googletest](https://github.com/google/googletest) is used following [C++ project setup with CMake & unit tests (google test)](https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html).
```
cmake -S . -B build; cmake --build build --target test
cd build/test
./dyr_test
```

# TODO

1. using the [libev](https://github.com/enki/libev)
2. integrate with boost [std::string to lowercase or uppercase in C++](https://raymii.org/s/snippets/std_string_to_lowercase_or_uppercase_in_cpp.html)
3. dynamic libs
4. how to debug using gdb
5. [how to debug in vscode](Configure C/C++ debugging)
6. how to link to SHARED lib
7. automate the google test
