#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"
#include "headers/const.h"

void game_loop()
{
    while(true)
    {
        int c = getch();
        if(c == 'c' || c == 'C')
            break;
        if(c == KEY_RESIZE)
            handle_window_resize();
    }
}