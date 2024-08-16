#include <curses.h>
#include "headers/utils.h"
#include "const.h"

WINDOW* draw_window()
{
    int y, x, height, width, start_y, start_x;
    getmaxyx(stdscr, y, x);
    height = y/2;
    width = x/2;
    start_y = y/4;
    start_x = x/4;
    WINDOW* window = newwin(height, width, start_y, start_x);
    refresh();
    box(window, 0, 0);
    wrefresh(window);
    return window;
}

void handle_window_resize()
{
    clear();
    win = draw_window();
}