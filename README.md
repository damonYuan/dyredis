README
====

# Build Commands

```
cmake -S . -B build
cmake --build build --clean-first
cmake --build build --target test
cmake --install build --prefix ~/cbin
// or you can find the binary in build folder
dyredis
```