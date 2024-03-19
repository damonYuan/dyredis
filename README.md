README
====

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
```
cmake -S . -B build; cmake --build build --target test
cd build
ctest
```

# TODO

1. using the [libev](https://github.com/enki/libev)

