# Only reason this CMakeFile exists is so IntelliSense doesn't complain
# This headers are not compiled, they are directly included inside main

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)

add_library(Textures STATIC)
set_target_properties(Textures PROPERTIES LINKER_LANGUAGE CXX)
target_sources(
    Textures
    PUBLIC Texture.cpp
    PUBLIC Scenario.cpp
    PUBLIC Fruit.cpp
    PUBLIC Snake.cpp
)

target_link_libraries(Textures PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(Textures PRIVATE SDL2::SDL2_image)
target_link_libraries(Textures PRIVATE SDL2::SDL2_ttf)