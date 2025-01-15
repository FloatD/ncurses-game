#include "player.h"
#include "config.h"


void initialize_player(Player *player, int startX, int startY) {
    player->x = startX;
    player->y = startY;
}

bool can_move(Player player, int dx, int dy, char map[MAP_WIDTH][MAP_HEIGHT]) {
    int new_x = player.x + dx;
    int new_y = player.y + dy;

    if (new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT) {
        return false;
    }

    if (map[new_y][new_x] == 'X') {
        return false;
    }

    return true;
}
