#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"
#include "const.h"

int main()
{
    initscr();
    raw();
    noecho();

    int x = 1;
    int y = 1;
    win = draw_window();
    game_loop(&x, &y);

    endwin();
    return 0;
}