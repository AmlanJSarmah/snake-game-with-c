#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"
#include "headers/const.h"

void game_loop(WINDOW* win, struct Snake *snake)
{
    while(true)
    {
        box(win, 0, 0);
        wrefresh(win);
        mvwprintw(win, snake->pos_0[1], snake->pos_0[0], "@");
        wrefresh(win);
        int c = getch();
        if(c == 'c' || c == 'C')
            break;
        if(c == KEY_RESIZE)
            win = handle_window_resize();
        handle_movement(win, c, &snake->pos_0[0], &snake->pos_0[1]);
        wclear(win);
    }
}