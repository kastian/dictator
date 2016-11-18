/*
  Try to get money from RUSSIANS or AMERICANS, and add it to treasury if success

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "aid.h"

void aid(data* DATA)
{
  erase();
  attron(GREEN);
  mvprintw( 1,24,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
  attroff(GREEN);
  mvprintw( 3,24,"  APPLICATION for FOREIGN AID   ");
  mvprintw(12,24,"              WAIT              ");
  key();
  if (month <= rand()%5 + 3)
    mvprintw(12,24,"   It's TOO EARLY to give AID   ");
  else if (DATA->used)
    mvprintw(12,24,"    Very sorry, NO MORE LOANS   ");
  else if (DATA->author->popularity <= minimal)
    {
      if (DATA->author == RUSSIANS)
	mvprintw(12,24,"             NIET !             ");
      else
	mvprintw(12,24,"            \"nuts !\"            ");
    }
  else
    {
      mvprintw(12, 24,"%s will let you have", DATA->author->name);
      int loan = DATA->author->popularity * 30 + rand()%200;
      mvprintw(14,31,"%d,000 DOLLARS", loan);
      treasury += loan ;
      DATA->used = 1;
    }
  key();
}
