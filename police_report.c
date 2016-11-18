/*
  SECRET POLICE report

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "police_report.h"

void police_report()
{
  erase();
  mvprintw(1, 24,"################################");
  mvprintw(3, 24,"      SECRET POLICE REPORT      ");
  if (treasury > 0		      /* If you have money   */
      && POLICE->popularity > minimal /*  and didn't neglect */
      && POLICE->strength > minimal)  /*  your secret police */
    {
      mvprintw(3, 51, "?");
      mvprintw(12, 24, "         ( costs $1000 )        ");
      if (key_y())
	{
	  treasury -= 1;
	  erase();
	  free_report();
	}
    }
  else
    {
      mvprintw(10, 24, "          NOT AVAILABLE         ");
      if (POLICE->popularity <= minimal)
	mvprintw(gety()+2, 24, "  Your POPULARITY with us is %d  ", POLICE->popularity);
      if (POLICE->strength   <= minimal)
	mvprintw(gety()+2, 24, "      POLICE strength is %d      ", POLICE->strength);
      if (treasury < 1)
	mvprintw(gety()+2, 24, "    You can't AFFORD a REPORT    ");
      key();
      erase();
    }
}

/*
   FREE secret police report (for start and final)
*/

void free_report()
{
  int i, a;
  mvprintw(0, 24, "MONTH %d                       ", month);
  mvprintw(3, 24, "         POLICE  REPORT        ");
  mvprintw(6, 24, " POPULARITY          STRENGTHS ");
  for (a = 0; a < 8; a++) 		        /* For all groups */
    {
      move(8+a, 24 + 10 - GROUP[a].popularity);
      attron(GREEN);
      for (i = GROUP[a].popularity; i > 0; i--) /* Print group popularity 9->1 */
	printw("%d", i);
      (GROUP[a].status == ' ') ? attron(YELLOW) : attron(REVERSE_YELLOW) ;
      mvprintw(8+a, 35, "%s", GROUP[a].fname);  /* Print group formatted name */
      attron(RED|A_BOLD);
      printw("%c", GROUP[a].status);            /* Print group status */
      attroff(A_BOLD);
      for (i = 1; i <= GROUP[a].strength; i++)  /* Print group strength 1->9 */
	printw("%d", i);
      attroff(RED);
    }
  mvprintw(17, 24, "  Your STRENGTH is %d           ", your_strength);
  mvprintw(19, 24, "  STRENGTH for REVOLUTION is %d ", revolution_strength);
  key();
  erase();
}
