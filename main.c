#include <curses.h>

int main()
{
    initscr();

    // print something to screen
    printw("Hello World");
    refresh();

    getch();
    endwin();
    return 0;
}