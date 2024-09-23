#include <curses.h>
#include "headers/game.h"
#include "headers/utils.h"
#include "headers/const.h"

void game_over_screen(WINDOW *win)
{
    wclear(win);
    wclear(stdscr);
    box(win, 0, 0);
    int y, x;
    getmaxyx(win, y, x);
    wmove(win, y / 2, x / 2 - 5);
    wprintw(win, "GAME OVER");
    wrefresh(stdscr);
    wrefresh(win);
    getch();
}

void print_score(int score)
{
    printw("Score %d", score);
}

void print_max_snake_length(struct Snake *snake)
{
    if (snake->pos_9[0] != -1 && snake->pos_9[1] != -1)
    {
        int x, y;
        getmaxyx(stdscr, y, x);
        mvprintw(1, (x / 2) - 5, "Max Snake Lenght");
    }
}

void game_loop(WINDOW *win, struct Snake *snake)
{
    // Game Variables
    int is_consume = 1;
    int is_grow = 0;
    int score = 0;
    int food_x, food_y;
    char direction;

    // Event Loop
    while (true)
    {
        box(win, 0, 0);

	// Game Functions
        check_if_food_eaten(snake, &is_consume, &food_x, &food_y, &is_grow, &score);
        increase_snake_size(snake, &is_grow, direction);
        draw_food(win, &is_consume, &food_x, &food_y);
        print_snake(win, snake);
        print_score(score);
        print_max_snake_length(snake);

	// Refreshing the screen after all the calculations
        wrefresh(stdscr);
        wrefresh(win);

	// Key Detection
        int c = getch();
        if (c == 'c' || c == 'C')
            break;
        if (c == KEY_RESIZE)
        {
            is_consume = 1;
            delwin(win);
            win = handle_window_resize();
        }

	// Head Moments and Collision Detection
        handle_head_movement(win, c, snake, &direction);
        if (collision_detection(win, snake) == 0)
        {
            game_over_screen(win);
            break;
        }

	//Clear screen after loop iteration to recalculate
        wclear(win);
        wclear(stdscr);
    }
}
