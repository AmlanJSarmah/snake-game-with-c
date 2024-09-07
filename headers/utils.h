#ifndef __UTILS__
#define __UTILS__

#include "const.h"

WINDOW *draw_window();
WINDOW *handle_window_resize();
void handle_head_movement(WINDOW *win, int c, struct Snake *snake, char *direction);
void print_snake(WINDOW *win, struct Snake *snake);
void move_snake_body(struct Snake *snake, int temp_x, int temp_y);
int collision_detection(WINDOW *win, struct Snake *snake);
int generate_random_number(int min, int max);
void draw_food(WINDOW *win, int *is_consume, int *food_x, int *food_y);
void check_if_food_eaten(struct Snake *snake, int *is_consume, int *food_x, int *food_y, int *is_grow, int *score);
void increase_snake_size(struct Snake *snake, int *is_grow, char direction);
void add_snake_element(int *next_x, int *next_y, int *prev_x, int *prev_y, char direction);

#endif
