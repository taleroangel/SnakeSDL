# Add classes
add_subdirectory("./Logging")
add_subdirectory("./Utils")

# Add main
add_executable(SnakeSDL main.cpp)

# Link objects
target_link_libraries(SnakeSDL PUBLIC Logging)
target_link_libraries(SnakeSDL PUBLIC Utils)