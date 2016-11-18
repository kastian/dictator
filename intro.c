/*
  Display intro screen

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "intro.h"

void intro()
{
  erase();
  mvprintw( 4, 24, "  DICTATOR                      ");
  mvprintw( 6, 24, "  Remake of old SPECTRUM Game   ");
  mvprintw( 8, 24, "  Devised and Written by        ");
  mvprintw(10, 24, "  Don PRIESTLEY                 ");
  mvprintw(14, 24, "  Copyright  ");

  addch('D');
  addch('k' | YELLOW);
  addch('T');
  addch('R' | GREEN);
  addch('O' | CYAN);
  addch('N' | GREEN);
  addch('I' | CYAN);
  addch('C' | GREEN);
  addch('S' | CYAN);

  printw("  1983");
  mvprintw(16, 24, "  Rewritten in C by #kstn (2015)");
  mvprintw(18, 24, "  Press any key to play         ");
  mvprintw(20, 24, "  Or Ctrl-C to exit             ");
  getch();
}
