#include "game.h"
#include "config.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static Player player;
static char map[MAP_HEIGHT][MAP_WIDTH];

void initialize_game() {
    initscr();
    cbreak();
    noecho();

    initialize_player(&player, 50, 50);

    const char *filepath = "map.png";
    int width, height, channels;

    unsigned char *image = stbi_load(filepath, &width, &height, &channels, 3);
    if (image == NULL) {
        printf("Failed to load image\n");
        exit(1);
    }

    if (width != MAP_WIDTH || height != MAP_HEIGHT) {
        printf("Error: Image dimensions must be %dx%d\n", MAP_WIDTH, MAP_HEIGHT);
        stbi_image_free(image);
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char r = image[(y * width + x) * 3 + 0];
            unsigned char g = image[(y * width + x) * 3 + 1];
            unsigned char b = image[(y * width + x) * 3 + 2];

            // Place * on green pixels #00FF00
            if (r == 0 && g == 255 && b == 0) {
                map[y][x] = '*';
            // Place X on black pixels and . on white pixels
            } else if (r == g && g == b) {
                map[y][x] = (r < 128) ? 'X' : '.';
            } else {
                map[y][x] = '.';
            }
        }
    }
    draw_map();

    stbi_image_free(image);
}

void game_loop() {
    int input;
    while (1) {
        input = getch();

        if (input == 'q') {
            break;
        }

        int dx = 0, dy = 0;

        switch (input) {
            case 'w':
                dy = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'a':
                dx = -1;
                break;
            case 'd':
                dx = 1;
                break;
        }
        if (can_move(player, dx, dy, map)) {
            player.x += dx;
            player.y += dy;

            if (map[player.y][player.x] == '*') {
                player.score++;
                map[player.y][player.x] = '.';
            }
        }

        draw_map();
    }
}

void draw_map() {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int view_width = max_x - 2;
    int view_height = max_y - 3;

    int start_x = player.x - view_width / 2;
    int start_y = player.y - view_height / 2;

    clear();

    for (int y = 0; y < view_height; y++) {
        for (int x = 0; x < view_width; x++) {
            int map_x = start_x + x;
            int map_y = start_y + y;

            char tile = ' ';

            if (map_x >= 0 && map_x < MAP_WIDTH && map_y >= 0 && map_y < MAP_HEIGHT) {
                tile = map[map_y][map_x];
            }
            mvaddch(y + 1, x + 1, tile);
        }
    }

    mvaddch(view_height / 2 + 1, view_width / 2 + 1, '@');

    // Display player.x, player.y and player.score at the bottom
    char status_line[256];
    snprintf(status_line, sizeof(status_line), "player_x: %d, player_y: %d, score: %d", player.x, player.y, player.score);
    mvaddstr(max_y - 1, 1, status_line);

    refresh();
}
