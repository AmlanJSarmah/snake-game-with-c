#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"

#define SNAKE_LENGTH 11

int main()
{
    initscr();
    raw();
    noecho();

    int length_of_snake = 1;
    char snake[SNAKE_LENGTH] = "@";
    WINDOW* win = draw_window();
    game_loop();

    endwin();
    return 0;
}