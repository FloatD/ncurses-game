#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "config.h"

typedef struct {
    int x;
    int y;
    int score;
} Player;

void initialize_player(Player *player, int startX, int startY);

bool can_move(Player player, int dx, int dy, char map[MAP_WIDTH][MAP_HEIGHT]);

#endif
