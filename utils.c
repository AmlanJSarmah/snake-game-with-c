#include <curses.h>
#include "headers/utils.h"

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
    return window;
}

WINDOW* handle_window_resize()
{
    clear();  
    return draw_window();
}

void handle_movement(WINDOW* win, int c, int* x, int* y)
{
    int max_x, max_y;
    getmaxyx(win, max_y, max_x);

    switch(c)
    {
        case ('w'):
            if(*y > 1)
                *y = *y - 1;
            break;
        case ('s'):
            if(*y < (max_y-2))
                *y = *y + 1;
            break;
        case ('a'):
            if(*x > 1)
                *x = *x - 1;
            break;
        case ('d'):
            if(*x < (max_x-2))
                *x = *x + 1;
            break;
        default:
            break;
    }
}