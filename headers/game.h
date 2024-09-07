#ifndef __GAME__
#define __GAME__

#include "const.h"

void game_loop(WINDOW *win, struct Snake *snake);
void game_over_screen(WINDOW *win);
void print_score(int score);

#endif
