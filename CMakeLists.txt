# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language (Renamed project)
project(ncurses-game LANGUAGES C)

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add the source files for the project
set(SOURCE_FILES
    main.c
    game.c
    player.c
)

# Add the executable and link source files (Renamed executable)
add_executable(ncurses-game ${SOURCE_FILES})

# Include the directory containing stb_image.h
target_include_directories(ncurses-game PRIVATE ${CMAKE_SOURCE_DIR})

# Ensure math library is linked (sometimes needed for stb_image)
target_link_libraries(ncurses-game PRIVATE m)

# Link ncurses library using keyword signature
find_package(Curses REQUIRED)
target_link_libraries(ncurses-game PRIVATE ${CURSES_LIBRARIES})
target_include_directories(ncurses-game PRIVATE ${CURSES_INCLUDE_DIRS})

# Set the output name of the executable (Optional but recommended)
set_target_properties(ncurses-game PROPERTIES OUTPUT_NAME "ncurses-game")
