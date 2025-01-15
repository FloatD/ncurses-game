# ncurses-game

A basic text-based adventure game written in C with ncurses.

Features:

*   Map navigation using WASD keys.
*   Collision detection with walls.
*   Item collection (represented by '*').
*   Score tracking.

Uses [stb_image library](https://github.com/nothings/stb#stb_libs) for loading the map based on a .png image.


## Install ##

ncurses-game can be built from source.

### Dependency ###
* ncurses development libraries

**Note:** You might need to install additional libraries depending on your platform and compiler.

### From source ###

These instructions assume you have git and a C compiler (like GCC or Clang) installed.

```sh
git clone https://github.com/FloatD/ncurses-game
cd ncurses-game
mkdir build && cd build
cmake ..
make
cd ..
./build/ncurses-game
```
