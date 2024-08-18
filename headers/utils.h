#ifndef __UTILS__
#define __UTILS__

WINDOW* draw_window();
WINDOW* handle_window_resize();
void handle_movement(WINDOW* win, int c, int* x, int* y);

#endif