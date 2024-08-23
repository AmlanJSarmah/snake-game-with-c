#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"
#include "headers/const.h"

WINDOW *win;

struct Snake snake = {
    {10, 1},
    {9, 1},
    {8, 1},
    {7, 1},
    {6, 1},
    {5, 1},
    {4, 1},
    {3, 1},
    {2, 1},
    {1, 1},
};

int main()
{
    initscr();
    raw();
    noecho();

    win = draw_window();
    game_loop(win, &snake);

    delwin(win);
    endwin();
    return 0;
}
