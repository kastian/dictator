#ifndef CURSES_H
#define CURSES_H

#include <ncurses.h>

#define gety()	getcury(stdscr)
#define tab(A)	move(gety(),A)
                               /* ZX-SPECTRUM BASIC COLORS */
                               /* 0 - black */
#define BLUE	COLOR_PAIR(10) /* 1 - blue */
#define RED	COLOR_PAIR(20) /* 2 - red */
#define MAGENTA COLOR_PAIR(30) /* 3 - purple, or magenta */
#define GREEN	COLOR_PAIR(40) /* 4 - green */
#define CYAN	COLOR_PAIR(50) /* 5 - pale blue, technically called cyan */
#define YELLOW	COLOR_PAIR(60) /* 6 - yellow */
			       /* 7 - white */

#define REVERSE_YELLOW COLOR_PAIR(6)

void init_curses();
void finish_curses();
void init_colors();

#endif
