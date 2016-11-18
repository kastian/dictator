/*
  Display news and apply their consequencies

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "news.h"

void news()
{
  if (rand()%3) 	      /* Try to get news (chances 1/3) */
    return;
  int a; 		      /* For cycle */
  int r = rand() % NEWS_SIZE; /* Define random news */
  for (a = 0; a < NEWS_SIZE; a++)
    {
      if (! NEWS[r].used)     /* Take news if it is unused */
	break;
      r++; 		      /* Or try next */
      if (r == NEWS_SIZE)     /* If it is the last news in list */
	r = 0;                /*  then start from the beginning */
      if (a == NEWS_SIZE - 1) /* If there are no unused news */
	return;
    }
  erase();
  mvprintw(1, 24, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  mvprintw(3, 35, "NEWSFLASH\n");
  attron(A_BOLD);
  mvprintw(12, 24, "%s\n", NEWS[r].text);
  attroff(A_BOLD);
  key();
  transfer(&NEWS[r]);         /* Apply news consequences */
  plot();                     /* Recount chances to assasination/revolution */
  police_report();	      /* And look at results */
}
