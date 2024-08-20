#ifndef __UTILS__
#define __UTILS__

#include "const.h"

WINDOW *draw_window();
WINDOW *handle_window_resize();
void handle_head_movement(WINDOW *win, int c, struct Snake *snake);
void print_snake(WINDOW *win, struct Snake *snake);

#endif
