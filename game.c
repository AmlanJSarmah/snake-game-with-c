#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"
#include "headers/const.h"

void game_loop(int* x, int* y)
{
    while(true)
    {
        box(win, 0, 0);
        wrefresh(win);
        mvwprintw(win, *y, *x, "@");
        wrefresh(win);
        int c = getch();
        if(c == 'c' || c == 'C')
            break;
        if(c == KEY_RESIZE)
            handle_window_resize();
        handle_movement(c, x, y);
        wclear(win);
    }
}