/*
  Display how this decision can change groups strength and your
  popularity with them

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "advice.h"

void advice(data* DATA)
{
  int x;
  int y = 5;			/* Start position for text */
  int a;			/* For cycles */
  erase();
  for (a = 1; a < 20; a++)
    mvprintw(a, 24, "           ? ADVICE ?           ");
  if (key_y())
    {
      erase();
      mvprintw(1,24,"????????????????????????????????");
      attron(A_BOLD);
      mvprintw(3,24,"%s",DATA->text);
      attroff(A_BOLD);
      mvprintw(y++,24,"Your POPULARITY with ....");
      y++;
      for (a = 0; a < 8; a++)
	{
	  if (DATA->popularity[a] != 'M')
	    {
	      x = DATA->popularity[a] - 'M';
	      if (DATA->author == &GROUP[a] )
		attron(A_BOLD);
	      mvprintw(y++,24,"  %s", GROUP[a].name);
	      move(y-1,45);
	      (x > 0) ? attron(GREEN) : attron(RED);
	      (x > 0) ? printw("+%d",x) : printw("%d",x);
	      (x > 0) ? attroff(GREEN) : attroff(RED);
	      if (DATA->author == &GROUP[a])
		attroff(A_BOLD);
	    }
	}
      y++;
      mvprintw(y++,24,"The STRENGTH of ...");
      y++;
      for (a = 0; a < 6; a++)
	{
	  if (DATA->strength[a] != 'M')
	    {
	      x = DATA->strength[a] - 'M';
	      mvprintw(y++,24,"  %s", GROUP[a].name);
	      move(y-1,45);
	      (x > 0) ? attron(GREEN) : attron(RED);
	      (x > 0) ? printw("+%d",x) : printw("%d",x);
	      (x > 0) ? attroff(GREEN) : attroff(RED);
	    }
	}
      key();
    }
  erase();
}
