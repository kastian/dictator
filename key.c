/*
  Buttons

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "curses.h"
#include "key.h"

int key()
{
  mvprintw(22, 24, "              KEY               ");
  return getch();
}

int key_y()
{
  char ch;
  mvprintw(21, 24, "            Y = YES             ");
  mvprintw(22, 24, "              KEY               ");
  ch = getch();
  if (ch == 'y' || ch == 'Y')
    return 1;
  else
    return 0;
}
