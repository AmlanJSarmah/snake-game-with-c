#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"
#include "headers/const.h"

WINDOW *win;

int main()
{
    initscr();
    raw();
    noecho();

    struct Snake snake = {
        {1, 1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
    };

    win = draw_window();
    game_loop(win, &snake);

    endwin();
    return 0;
}