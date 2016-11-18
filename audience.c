/*
  Monthly audience

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "audience.h"

void audience()
{
  int a;			                         /* For cycles */
  int r = rand()%24;		                         /* Define PETITION */
  for (a = 0; a < 24; a++)
    {
      if (! PETITION[r].used)                            /* Break if PETITION is unused or try next */
	break;
      (r == 23) ? r = 0 :  r++;	                         /* If this is last petition let continue from the first */
      if (a == 23)                                       /* If all PETITIONs are used */
	{
	  for (a = 0; a < 24; a++)
	    PETITION[a].used = 0;                        /* Reset their status to 'unused' */
	  a = 0;			                 /* And start from PETITION[r] */
	}
    }
  data* AUDIENCE_PETITION = &PETITION[r];            /* Audience petition */
  group* AUDIENCE_GROUP = AUDIENCE_PETITION->author; /* Audience group */
  AUDIENCE_PETITION->used = 1;			     /* Set petition status to 'used' */
  erase();
  mvprintw( 3,24,"           AN AUDIENCE          ");
  mvprintw( 5,(24 + (32 - strlen(AUDIENCE_GROUP->name) - 15)/2),"A request from %s", AUDIENCE_GROUP->name); /* Centered */
  mvprintw( 9,24,"  Will YOUR EXCELLENCY agree to ");
  attron(A_BOLD);
  mvprintw(11,24,"%s",AUDIENCE_PETITION->text);
  attroff(A_BOLD);
  key();
  advice(AUDIENCE_PETITION);
  erase();
  mvprintw(3,24,"            DECISION            ");
  mvprintw(5,(24 + (32 - strlen(AUDIENCE_GROUP->name) - 11)/2),"%s ask you to", AUDIENCE_GROUP->name); /* Centered */
  attron(A_BOLD);
  mvprintw(7,24,"%s",AUDIENCE_PETITION->text);
  attroff(A_BOLD);
  if (cash_advice(AUDIENCE_PETITION))                                             /* If you have no money for this PETITION */
    key();
  else if (key_y()) 	                                                          /* If you have money and pass PETITION */
    {
      if (AUDIENCE_PETITION->cost != 'M'
	  || AUDIENCE_PETITION->monthly_cost != 'M')
	account();                                                                /* Do not show account changes if 'no money involved' */
      transfer(AUDIENCE_PETITION);
      account();
      return;
    }
  for (a = 0; a < 3; a++)                                                         /* Or you just refuse PETITION */
    {
      if (AUDIENCE_PETITION->author == &GROUP[a])                                 /* Find PETITION's group NUM */
	{
	  AUDIENCE_GROUP->popularity -= (AUDIENCE_PETITION->popularity[a] - 'M'); /* Decrease your popularity with petitioners */
	  limit(AUDIENCE_GROUP->popularity); 	                                  /* But no less than 0 */
	}
    }
  account();
}
