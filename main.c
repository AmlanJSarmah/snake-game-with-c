#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"

WINDOW* win;

int main()
{
    initscr();
    raw();
    noecho();

    int x = 1;
    int y = 1;
    win = draw_window();
    game_loop(win, &x, &y);

    endwin();
    return 0;
}