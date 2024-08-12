#include <curses.h>
#include "headers/utils.h"
#include "headers/game.h"

int main()
{
    initscr();

    game_loop();

    endwin();
    return 0;
}