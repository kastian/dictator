/*
  Count and display total rating

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "end.h"

void end()
{
  int a;		  /* For cycles */
  int total = 0;     	  /* Rating */
  for (a = 0; a < 8; a++) /* Add all groups popularity to rating */
    total += GROUP[a].popularity;
  erase();
  mvprintw( 3, 24, "    Your RATING as PRESIDENT    ");
  mvprintw( 5, 24, " Total POPULARITY         - %d  ", total);
  mvprintw( 7, 24, " MONTHS in OFFICE (%dx3)", month);
  mvprintw(50, 24, "                          - %d  ", month * 3);
  total += month * 3;
  if (alive)
    {
      mvprintw(gety()+2, 24, " For staying ALIVE        - 10  ");
      mvprintw(gety()+2, 24, " For MONEYGRABBING              ");
      mvprintw(gety()+1, 24, "     ($%d,000 /10,000)", swiss_bank_account);
      mvprintw(gety(), 50, "- %d", swiss_bank_account / 10);
      total += 10 + (swiss_bank_account / 10);
    }
  mvprintw(gety()+3, 24, " Your TOTAL is            - %d  ", total);
  if (total > history)
    {
      history = total;
      save(history);
    }
  mvprintw(gety()+2, 24, " [ Highest Score so far is %d ] ", history);
  key();
  erase();
  mvprintw(1,38,"             FINAL              ");
  free_report();
}
