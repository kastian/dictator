/*
  Welcome screen

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "welcome.h"

void welcome()
{
  erase();
  mvprintw(3, 24, "        WELCOME to OFFICE       ");
  mvprintw(5, 24, "The best DICTATOR of our beloved");
  mvprintw(6, 24, " country of RITIMBA had a final ");
  mvprintw(7, 24, "          rating of %-4d        ", history);
  if (history)
    mvprintw(gety()+2, 24, "  You can always try for %d !", history+1);
  else
    {
      mvprintw(gety()+2, 24, "  As this is your first attempt ");
      mvprintw(gety()+1, 24, "  you will no doubt do BETTER ! ");
    }
  mvprintw(gety()+2, 24, "  Start with a TREASURY REPORT  ");
  mvprintw(gety()+1, 24, "  and a POLICE Report. (FREE)   ");
  key();
}
