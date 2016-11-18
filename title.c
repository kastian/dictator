/*
  Main game title

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "title.h"

void title()
{
  erase();
  mvprintw( 3,24,"Press any key to become DICTATOR");
  mvprintw( 5,24,"             of the             ");
  attron(GREEN);
  mvprintw( 8,24,"            RITIMBAN            ");
  mvprintw(14,24,"            REPUBLIC            ");
  attron(YELLOW);
  mvprintw(10,24,"             ******             ");
  mvprintw(11,24,"               **               ");
  mvprintw(12,24,"             ******             ");
  attroff(YELLOW);
  getch();
}
