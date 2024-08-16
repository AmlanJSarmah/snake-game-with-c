#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"

void game_loop()
{
    while(true)
    {
        int c = getch();
        if(c == 'c' || c == 'C')
            break;
    }
}