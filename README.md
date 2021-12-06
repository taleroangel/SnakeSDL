# SnakeSDL 🐍
Snake Game using SDL2 in C++

## Compilation
SDL2 libraries are required and provided through vcpkg, if you don't have vcpkg you might have to modify the CMakeLists.txt list in order to link SDL2 dynamic libraries

Using vcpkg with Cmake, when using cmake alongside vcpkg the following flag is required:
> -DCMAKE_TOOLCHAIN_FILE=PATH TO VCPKG/scripts/buildsystems/vcpkg.cmake

Release version can be toggled by the flag:
> -DCMAKE_BUILD_TYPE="Release" 