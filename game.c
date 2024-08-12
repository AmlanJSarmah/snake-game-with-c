#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"

void game_loop()
{
    while(true)
    {
        clear();
        draw_window();
        int c = getch();
        if(c == 'c' || c == 'C')
            break;
    }
}