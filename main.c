#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"

int main()
{
    initscr();
    raw();

    game_loop();

    endwin();
    return 0;
}