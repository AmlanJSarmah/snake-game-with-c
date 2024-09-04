#ifndef __UTILS__
#define __UTILS__

#include "const.h"

WINDOW *draw_window();
WINDOW *handle_window_resize();
void handle_head_movement(WINDOW *win, int c, struct Snake *snake);
void print_snake(WINDOW *win, struct Snake *snake);
void move_snake_body(struct Snake *snake, int temp_x, int temp_y);
int collision_detection(WINDOW* win, struct Snake* snake);
int print_randoms(int min, int max);
void draw_food(WINDOW* win);

#endif
