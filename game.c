#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"
#include "headers/const.h"

void game_over_screen(WINDOW* win)
{
    wclear(win);
    box(win, 0, 0);
    int y, x;
    getmaxyx(win, y, x);
    wmove(win, y/2, x/2-5);
    wprintw(win, "GAME OVER");
    wrefresh(win);
    getch();
}

void game_loop(WINDOW *win, struct Snake *snake)
{
    int is_consume = 1;
    int food_x, food_y;
    while (true)
    {
        box(win, 0, 0);
        check_if_food_eaten(snake, &is_consume, &food_x, &food_y);
        draw_food(win, &is_consume, &food_x, &food_y);
        print_snake(win, snake);
        wrefresh(win);
        int c = getch();
        if (c == 'c' || c == 'C')
            break;
        if (c == KEY_RESIZE)
        {
            is_consume = 1;
            delwin(win);
            win = handle_window_resize();
        }
        handle_head_movement(win, c, snake);
        if(collision_detection(win, snake) == 0)
        {
            game_over_screen(win);
            break;
        }
        wclear(win);
    }
}
