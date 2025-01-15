#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "player.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_game();
void game_loop();
void draw_map();

#endif
