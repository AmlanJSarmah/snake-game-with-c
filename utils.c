#include <curses.h>
#include "headers/utils.h"
#include "headers/const.h"

WINDOW *draw_window()
{
    int y, x, height, width, start_y, start_x;
    getmaxyx(stdscr, y, x);
    height = y / 2;
    width = x / 2;
    start_y = y / 4;
    start_x = x / 4;
    WINDOW *window = newwin(height, width, start_y, start_x);
    refresh();
    return window;
}

WINDOW *handle_window_resize()
{
    clear();
    return draw_window();
}

void handle_head_movement(WINDOW *win, int c, struct Snake *snake)
{
    int max_x, max_y;
    getmaxyx(win, max_y, max_x);

    switch (c)
    {
    case ('w'):
        if (snake->pos_0[1] > 1)
            snake->pos_0[1] = snake->pos_0[1] - 1;
        break;
    case ('s'):
        if (snake->pos_0[1] < (max_y - 2))
            snake->pos_0[1] = snake->pos_0[1] + 1;
        break;
    case ('a'):
        if (snake->pos_0[0] > 1)
            snake->pos_0[0] = snake->pos_0[0] - 1;
        break;
    case ('d'):
        if (snake->pos_0[0] < (max_x - 2))
            snake->pos_0[0] = snake->pos_0[0] + 1;
        break;
    default:
        break;
    }
}

void print_snake(WINDOW *win, struct Snake *snake)
{
    // We use a reverse for loop to keep our cursor at the snake head
    // We also check if the snake postiton is valid or not.
    // -1 means the position isn't used yet. A positve value is a valid position
    for (int i = SNAKE_LENGTH - 1; i > -1; i--)
    {
        switch (i)
        {
        case 0:
            if (snake->pos_0[0] > -1)
                mvwprintw(win, snake->pos_0[1], snake->pos_0[0], "@");
            break;
        case 1:
            if (snake->pos_1[0] > -1)
                mvwprintw(win, snake->pos_1[1], snake->pos_1[0], "@");
            break;
        case 2:
            if (snake->pos_2[0] > -1)
                mvwprintw(win, snake->pos_2[1], snake->pos_2[0], "@");
            break;
        case 3:
            if (snake->pos_3[0] > -1)
                mvwprintw(win, snake->pos_3[1], snake->pos_3[0], "@");
            break;
        case 4:
            if (snake->pos_4[0] > -1)
                mvwprintw(win, snake->pos_4[1], snake->pos_4[0], "@");
            break;
        case 5:
            if (snake->pos_5[0] > -1)
                mvwprintw(win, snake->pos_5[1], snake->pos_5[0], "@");
            break;
        case 6:
            if (snake->pos_6[0] > -1)
                mvwprintw(win, snake->pos_6[1], snake->pos_6[0], "@");
            break;
        case 7:
            if (snake->pos_7[0] > -1)
                mvwprintw(win, snake->pos_7[1], snake->pos_7[0], "@");
            break;
        case 8:
            if (snake->pos_8[0] > -1)
                mvwprintw(win, snake->pos_8[1], snake->pos_8[0], "@");
            break;
        case 9:
            if (snake->pos_9[0] > -1)
                mvwprintw(win, snake->pos_9[1], snake->pos_9[0], "@");
            break;
        default:
            break;
        }
    }
}
