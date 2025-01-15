#include "game.h"

int main() {
    initialize_game();
    game_loop();

    endwin();
    return 0;
}
