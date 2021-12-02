find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)

add_library(Utils STATIC Utils.cpp)

target_link_libraries(Utils PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(Utils PRIVATE SDL2::SDL2_image)
target_link_libraries(Utils PRIVATE SDL2::SDL2_ttf)