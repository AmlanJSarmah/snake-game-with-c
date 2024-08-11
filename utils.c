#include <curses.h>
#include "headers/utils.h"

void draw_window()
{
    int y, x, height, width, start_y, start_x;
    getmaxyx(stdscr, y, x);
    height = y/2;
    width = x/2;
    start_y = y/4;
    start_x = x/4;
    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
}