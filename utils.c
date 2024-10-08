#include <curses.h>
#include <stdlib.h>
#include <time.h>
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

void handle_head_movement(WINDOW *win, int c, struct Snake *snake, char *direction)
{
    int max_x, max_y;
    getmaxyx(win, max_y, max_x);

    switch (c)
    {
    case 'w':
        *direction = 'N';
        if (snake->pos_0[1] > 1)
        {
            int temp_x = snake->pos_0[0];
            int temp_y = snake->pos_0[1];
            // if the snake head is moving DOWN and yet the user press W, it cannot move.
            if (snake->pos_0[1] - 1 == snake->pos_1[1])
                break;
            snake->pos_0[1] = snake->pos_0[1] - 1;
            move_snake_body(snake, temp_x, temp_y);
        }
        break;
    case 's':
        *direction = 'S';
        if (snake->pos_0[1] < (max_y - 2))
        {
            int temp_x = snake->pos_0[0];
            int temp_y = snake->pos_0[1];
            // if the snake head is moving UP and yet the user press S, it cannot move.
            if (snake->pos_0[1] + 1 == snake->pos_1[1])
                break;
            snake->pos_0[1] = snake->pos_0[1] + 1;
            move_snake_body(snake, temp_x, temp_y);
        }
        break;
    case 'a':
        *direction = 'W';
        if (snake->pos_0[0] > 1)
        {
            int temp_x = snake->pos_0[0];
            int temp_y = snake->pos_0[1];
            // if the snake head is moving LEFT and yet the user press A, it cannot move.
            if (snake->pos_0[0] - 1 == snake->pos_1[0])
                break;
            snake->pos_0[0] = snake->pos_0[0] - 1;
            move_snake_body(snake, temp_x, temp_y);
        }
        break;
    case 'd':
        *direction = 'E';
        if (snake->pos_0[0] < (max_x - 2))
        {
            int temp_x = snake->pos_0[0];
            int temp_y = snake->pos_0[1];
            // if the snake head is moving RIGHT and yet the user press D, it cannot move.
            if (snake->pos_0[0] + 1 == snake->pos_1[0])
                break;
            snake->pos_0[0] = snake->pos_0[0] + 1;
            move_snake_body(snake, temp_x, temp_y);
        }
        break;
    default:
        break;
    }
}

void move_snake_body(struct Snake *snake, int temp_x, int temp_y)
{
    int _temp_x, _temp_y;
    for (int i = 1; i < SNAKE_LENGTH; i++)
    {
        switch (i)
        {
        case 1:
            if (snake->pos_1[0] < 0)
                break;
            _temp_x = snake->pos_1[0];
            _temp_y = snake->pos_1[1];
            snake->pos_1[0] = temp_x;
            snake->pos_1[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 2:
            if (snake->pos_2[0] < 0)
                break;
            _temp_x = snake->pos_2[0];
            _temp_y = snake->pos_2[1];
            snake->pos_2[0] = temp_x;
            snake->pos_2[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 3:
            if (snake->pos_3[0] < 0)
                break;
            _temp_x = snake->pos_3[0];
            _temp_y = snake->pos_3[1];
            snake->pos_3[0] = temp_x;
            snake->pos_3[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 4:
            if (snake->pos_4[0] < 0)
                break;
            _temp_x = snake->pos_4[0];
            _temp_y = snake->pos_4[1];
            snake->pos_4[0] = temp_x;
            snake->pos_4[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 5:
            if (snake->pos_5[0] < 0)
                break;
            _temp_x = snake->pos_5[0];
            _temp_y = snake->pos_5[1];
            snake->pos_5[0] = temp_x;
            snake->pos_5[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 6:
            if (snake->pos_6[0] < 0)
                break;
            _temp_x = snake->pos_6[0];
            _temp_y = snake->pos_6[1];
            snake->pos_6[0] = temp_x;
            snake->pos_6[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 7:
            if (snake->pos_7[0] < 0)
                break;
            _temp_x = snake->pos_7[0];
            _temp_y = snake->pos_7[1];
            snake->pos_7[0] = temp_x;
            snake->pos_7[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 8:
            if (snake->pos_8[0] < 0)
                break;
            _temp_x = snake->pos_8[0];
            _temp_y = snake->pos_8[1];
            snake->pos_8[0] = temp_x;
            snake->pos_8[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        case 9:
            if (snake->pos_9[0] < 0)
                break;
            _temp_x = snake->pos_9[0];
            _temp_y = snake->pos_9[1];
            snake->pos_9[0] = temp_x;
            snake->pos_9[1] = temp_y;
            temp_x = _temp_x;
            temp_y = _temp_y;
            break;

        default:
            break;
        }
    }
}

void print_snake(WINDOW *win, struct Snake *snake)
{
    // We use a reverse for loop to keep our cursor at the snake head
    // We also check if the snake postiton is valid or not.
    // -1 means the position isn't used yet. A positve value is a valid position
    for (int i = 0; i < SNAKE_LENGTH; i++)
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
    // Moves cursor back to head at the end of rendering
    wmove(win, snake->pos_0[1], snake->pos_0[0]);
}

int collision_detection(WINDOW *win, struct Snake *snake)
{
    int head_x = snake->pos_0[0];
    int head_y = snake->pos_0[1];

    for (int i = 1; i < SNAKE_LENGTH; i++)
    {
        switch (i)
        {
        case 1:
            if (head_x == snake->pos_1[0] && head_y == snake->pos_1[1])
                return 0;
            break;
        case 2:
            if (head_x == snake->pos_2[0] && head_y == snake->pos_2[1])
                return 0;
            break;
        case 3:
            if (head_x == snake->pos_3[0] && head_y == snake->pos_3[1])
                return 0;
            break;
        case 4:
            if (head_x == snake->pos_4[0] && head_y == snake->pos_4[1])
                return 0;
            break;
        case 5:
            if (head_x == snake->pos_5[0] && head_y == snake->pos_5[1])
                return 0;
            break;
        case 6:
            if (head_x == snake->pos_6[0] && head_y == snake->pos_6[1])
                return 0;
            break;
        case 7:
            if (head_x == snake->pos_7[0] && head_y == snake->pos_7[1])
                return 0;
            break;
        case 8:
            if (head_x == snake->pos_8[0] && head_y == snake->pos_8[1])
                return 0;
            break;
        case 9:
            if (head_x == snake->pos_9[0] && head_y == snake->pos_9[1])
                return 0;
            break;
        }
    }
    return -1;
}

int generate_random_number(int min, int max)
{
    int rd_num = rand() % (max - min + 1) + min;
    return rd_num;
}

void draw_food(WINDOW *win, int *is_consume, int *food_x, int *food_y)
{
    if (*is_consume == 1)
    {
        int min_x = 1;
        int min_y = 2;
        int max_x, max_y;
        getmaxyx(win, max_y, max_x);
        *food_x = generate_random_number(min_x, max_x - 2);
        *food_y = generate_random_number(min_y, max_y - 2);
        *is_consume = 0;
    }
    wmove(win, *food_y, *food_x);
    wprintw(win, "X");
}

void check_if_food_eaten(struct Snake *snake, int *is_consume, int *food_x, int *food_y, int *is_grow, int *score)
{
    if (snake->pos_0[0] == *food_x && snake->pos_0[1] == *food_y)
    {
        *is_consume = 1;
        *is_grow = 1;
        *score = *score + 1;
    }
}

void increase_snake_size(struct Snake *snake, int *is_grow, char direction)
{
    if (snake->pos_1[0] == -1 && snake->pos_1[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_1[0], &snake->pos_1[1], &snake->pos_0[0], &snake->pos_0[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_2[0] == -1 && snake->pos_2[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_2[0], &snake->pos_2[1], &snake->pos_1[0], &snake->pos_1[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_3[0] == -1 && snake->pos_3[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_3[0], &snake->pos_3[1], &snake->pos_2[0], &snake->pos_2[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_4[0] == -1 && snake->pos_4[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_4[0], &snake->pos_4[1], &snake->pos_3[0], &snake->pos_3[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_5[0] == -1 && snake->pos_5[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_5[0], &snake->pos_5[1], &snake->pos_4[0], &snake->pos_4[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_6[0] == -1 && snake->pos_6[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_6[0], &snake->pos_6[1], &snake->pos_5[0], &snake->pos_5[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_7[0] == -1 && snake->pos_7[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_7[0], &snake->pos_7[1], &snake->pos_6[0], &snake->pos_6[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_8[0] == -1 && snake->pos_8[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_8[0], &snake->pos_8[1], &snake->pos_7[0], &snake->pos_7[1], direction);
        *is_grow = 0;
    }

    else if (snake->pos_9[0] == -1 && snake->pos_9[1] == -1 && *is_grow == 1)
    {
        add_snake_element(&snake->pos_9[0], &snake->pos_9[1], &snake->pos_8[0], &snake->pos_8[1], direction);
        *is_grow = 0;
    }

    else
    {
    }
}

void add_snake_element(int *next_x, int *next_y, int *prev_x, int *prev_y, char direction)
{
    switch (direction)
    {
    case 'N':
        *next_x = *prev_x;
        *next_y = *prev_y - 1;
        break;
    case 'S':
        *next_x = *prev_x;
        *next_y = *prev_y + 1;
        break;
    case 'E':
        *next_x = *prev_x - 1;
        *next_y = *prev_y;
        break;
    case 'W':
        *next_x = *prev_x + 1;
        *next_y = *prev_y;
        break;
    default:
        break;
    }
}