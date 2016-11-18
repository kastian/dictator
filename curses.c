/*
  Screen routines
*/

#include "curses.h"

void init_curses()
{
  initscr();
  curs_set(0);
  noecho();
  keypad(stdscr, 1);
  start_color();
  init_colors();
}

void finish_curses()
{
  endwin();
}

void init_colors()
{
  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  init_pair(6, COLOR_BLACK, COLOR_YELLOW);
  init_pair(7, COLOR_BLACK, COLOR_WHITE);
  init_pair(10, COLOR_BLUE, COLOR_BLACK);
  init_pair(20, COLOR_RED, COLOR_BLACK);
  init_pair(30, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(40, COLOR_GREEN, COLOR_BLACK);
  init_pair(50, COLOR_CYAN, COLOR_BLACK);
  init_pair(60, COLOR_YELLOW, COLOR_BLACK);
  init_pair(70, COLOR_WHITE, COLOR_BLACK);
}
