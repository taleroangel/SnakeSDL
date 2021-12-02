# Project setup
cmake_minimum_required(VERSION 3.20)
project(SnakeSDL)

# Remember to use for release/debug compilation
# cmake -DCMAKE_BUILD_TYPE="Release" 
# cmake -DCMAKE_BUILD_TYPE="Debug"  *default

# Wrong directory check
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR
    "Do not build in root directory, remove 'CMakeCache.txt' and re-build in 'build' directory")
endif()

# C++ 11 Required Standard
set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED True)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECFT_BINARY_DIR}/bin")
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${PROJECT_BINARY_DIR}/bin" )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# Search libraries
# Libraries are imported using VCPKG, you might need to search libraries on your own
# if you're using VCPKG make sure to use the  -DCMAKE_TOOLCHAIN_FILE=PATH TO VCPKG/scripts/buildsystems/vcpkg.cmake flag on cmake configuration

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)

# Add SRC subdirectory
add_subdirectory("./src")

# Link libraries
target_link_libraries(SnakeSDL PUBLIC SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(SnakeSDL PUBLIC SDL2::SDL2_image)
target_link_libraries(SnakeSDL PUBLIC SDL2::SDL2_ttf)

# Copy resources and textures
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/textures" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/fonts" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Notification
message(STATUS "Executable will be found at: ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")