#include <curses.h>
#include "headers/utils.h"

int main()
{
    initscr();

    draw_window();

    getch();
    endwin();
    return 0;
}