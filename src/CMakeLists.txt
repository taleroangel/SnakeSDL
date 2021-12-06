# Add classes
add_subdirectory("Logging")
add_subdirectory("Utils")
add_subdirectory("Textures")

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)

# Add main
add_executable(SnakeSDL main.cpp)

target_link_libraries(SnakeSDL PUBLIC SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(SnakeSDL PUBLIC SDL2::SDL2_image)
target_link_libraries(SnakeSDL PUBLIC SDL2::SDL2_ttf)

# Link objects
target_link_libraries(SnakeSDL PUBLIC Logging)
target_link_libraries(SnakeSDL PUBLIC Utils)
target_link_libraries(SnakeSDL PUBLIC Textures)