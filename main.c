#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"
#include "headers/const.h"

WINDOW *win;

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
