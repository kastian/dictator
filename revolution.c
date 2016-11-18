/*
  Revolution

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "revolution.h"

int revolution()
{
  int a;		     /* For cycles */
  int allies_flag = 0; 	     /* If player has any allies */
  int dictator_strength;     /* Dictator strength */
  int revolutionary_strenth; /* Revolution strength */
  int h;		     /* Player's ally group num */
  group* ALLIES = NULL;      /* Pointer player's allies group */
  group* rGROUP = NULL;      /* Pointer to revolt group */
  group* rALLIES = NULL;     /* Pointer to their allies*/

  for(a = 0; a < 3; a++)     /* Trying to guess revolt group three times */
    {
      rGROUP = &GROUP[rand()%3];        /* Set pointer to presumably revolt group */
      if (rGROUP->status == 'R')	/* Break if they are really revolt */
	break;
      if (a == 2)			/* Or leave if no after the third fail */
	return 0;
    }
  rALLIES = rGROUP->allies;  /* Set separate pointer to revolt group allies */
  erase();
  mvprintw(12,24,"           REVOLUTION           ");
  key();
  erase();
  mvprintw(12,24,"        ESCAPE ATTEMPT ?        ");
  if (key_y())
    {
      erase();
      if (HELICOPTER->used)  /* If you've take care to buy helicopter */
	{
	  if (rand()%3)	     /*    and you're lucky */
	    {
	      mvprintw(12,24,"   You ESCAPE by HELICOPTER !   ");
	      key();
	      return 1;
	    }
	  else               /* Oh, shit! */
	    {
	      mvprintw(12,24,"  The HELICOPTER won't START !  ");
	      key();
	      erase();
	    }
	}
      escape_to_leftoto();   /* Try to escape afoot */
      return 1;
    }
  /* No escape */
  erase();
  revolutionary_strenth = rGROUP->strength + rALLIES->strength; /* Count combine revolution strength */
  dictator_strength = your_strength;
  mvprintw(5,(24 + (32 - strlen(rGROUP->name) - 17) / 2),"%s have joined with", rGROUP->name); /* Centered */
  mvprintw(6,(24 + (32 - strlen(rALLIES->name)) / 2),"%s", rALLIES->name);                     /* Centered */
  mvprintw(7,24,"  Their combined STRENGTH is %-2d ", revolutionary_strenth);
  mvprintw(9,24,"  WHO are you ASKING for HELP ? ");
  for (a=0; a<6; a++)                                     /* Try to find allies for you */
    {
      if (GROUP[a].popularity <= minimal)                 /* Next group if this group's popularity too low */
	continue;
      mvprintw(gety()+1,30,"%d %s ?",a+1, GROUP[a].name); /* Display possible ally */
      allies_flag = 1;		                          /* You have allies ! */
    }
  if (allies_flag)		                          /* If there are any possible allies for you */
    {
      while (1)			                          /* Get key until it will not be between 0 and 6 */
	{
	  h = key() - '1';
	  if (h >= 0 && h < 6)                            /* Leave cycle if so */
	    break;
	}
      ALLIES = &GROUP[h];		                  /* Set separate pointer to your allies */
      if (ALLIES->popularity <= minimal)	          /* If player select not shown group with too low popularity */
	{
	  erase();
	  mvprintw(12,24,"      You must be JOKING !      ");
	  key();
	  erase();
	  escape_to_leftoto();
	  return 1;
	}
      dictator_strength += ALLIES->strength;              /* Else add allies strength to dictator strength */
    }
  else 			                                  /* If you haven't any possible allies */
    {
      erase();
      mvprintw(12,24,"      You're ON YOUR OWN !      ");
      key();
    }
  erase();
  mvprintw(8,24,"YOUR STRENGTH is %-2d              ", your_strength);
  if (ALLIES != NULL)
    mvprintw(9,24,"%s strength is %-2d", ALLIES->name, ALLIES->strength);
  mvprintw(10,24,"The REVOLUTIONARY'S is %-2d       ", revolutionary_strenth);
  key();
  erase();                                                /* OK, REVOLUTION! */
  mvprintw(12,24,"   The REVOLUTION has STARTED   ");
  key();
  erase();
  if (revolutionary_strenth > dictator_strength + rand()%3 - 1) /* You lose */
    {
      mvprintw(10,24,"    You have been OVERTHROWN    ");
      mvprintw(12,24,"         and LIQUIDATED         ");
      alive = 0;		/* Reset 'alive' flag */
      key();
      return 1;
    }
  else /* You WIN ! */
    {
      mvprintw(10,24,"  The REVOLT has been CRUSHED   ");
      mvprintw(12,24,"  PUNISH the REVOLUTIONARIES ?  ");
      if (key_y())
	{
	  rGROUP->strength = 0;    /* Set revolt group strength */
	  rGROUP->popularity = 0;  /*    and popularity to 0 */
	  rALLIES->strength = 0;   /* Set their allies strength */
	  rALLIES->popularity = 0; /*    and popularity to 0 */
	}
      if (ALLIES != NULL)          /* Set you allies popularity to maximum */
	ALLIES->popularity = 9;
      plot_bonus = month + 2;      /* And get two month without any revolutions */
      reset_plot();		   /* Reset army, peasants and landowners statuses and allies */
      police_report();		   /* And look at the results */
      return 0;
    }
}

void escape_to_leftoto()
{
  mvprintw(10,24,"   You have to get through the  ");
  mvprintw(12,24,"      MOUNTAINS to LEFTOTO      ");
  key();
  erase();
  mvprintw(11,24,"%s",
	   ( rand()%((GUERILLAS->strength / 3) + 2) ) ? /* Chanses 1/2..5 */
	   " The GUERILLAS are CELEBRATING  " :
	   " The GUERILLAS didn't catch you ");
  key();
}
