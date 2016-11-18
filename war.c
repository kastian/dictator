/*
  War with Leftoto

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "war.h"

int war()
{
  int a;
  int ritumban_strength = 0;
  int leftotan_strength = 0;
  if (LEFTOTANS->popularity > minimal                       /* If you Lefoto likes you */
      || LEFTOTANS->strength < minimal )		    /*  or if Leftoto is too weak */
    return 0;						    /* No war! */
  erase();
  /* Just threat (chances 2/3) */
  if (rand()%3)
    {
      mvprintw( 6,24,"   THREAT of WAR with LEFTOTO   ");
      mvprintw(11,24,"   Your POPULARITY in RITIMBA   ");
      mvprintw(12,24,"            will RISE           ");
      for (a = 0; a < 3; a++)                               /* Raise popularity in ARMY, PEASANTS and LANDOWNERS */
	increase(GROUP[a].popularity);
      increase(POLICE->popularity);                         /* Raise popularity in SECRET POLICE */
      key();
      return 0;
    }
  /* Else WAR (chances 1/3) */
  ritumban_strength += your_strength;	  		    /* Add your strength to Ritumban strength */
  for (a = 0; a < 3; a++)                                   /* Add army, peasants and landowners strength to Ritumban strength */
    {
      if (GROUP[a].popularity > minimal)
	ritumban_strength += GROUP[a].strength;
    }
  if (POLICE->popularity > minimal)                         /* Add secret police strength to Ritumban strength */
    ritumban_strength += POLICE->strength;
  for (a = 0; a < 6; a++)                                   /* Count leftoto strength */
    {
      if (GROUP[a].popularity <= minimal)
	leftotan_strength += GROUP[a].strength;
    }

  mvprintw( 8,24,"        LEFTOTO  INVADES        ");
  mvprintw(12,24,"     Ritimban Strength is %d    ", ritumban_strength);
  mvprintw(14,24,"     Leftotan Strength is %d    ", leftotan_strength);
  mvprintw(18,24,"      A SHORT DECISIVE WAR      ");
  key();
  erase();
  if (ritumban_strength > leftotan_strength + rand()%3 - 1) /* You win */
    {
      mvprintw(11,24,"        LEFTOTANS ROUTED        ");
      LEFTOTANS->strength = 0;		                    /* Set leftotans strength to 0 */
      key();
      return 0;
    }
  else                                                      /* You lose */
    {
      mvprintw(7,24,"        LEFTOTAN VICTORY        ");
      key();
      if (HELICOPTER->used && rand()%3 )                    /* Chances 2/3 */
	{
	  erase();
	  mvprintw(11,24,"   You ESCAPE by HELICOPTER !   ");
	}
      else			/* Helicopter nicht! */
	{
	  alive = 0; 			                    /* Set dead flag */
	  if (HELICOPTER->used)
	    mvprintw(9,24,"    Helicopter ENGINE FAILURE   ");
	  mvprintw(11,24,"     YOU are judged to be an    ");
	  mvprintw(13,24,"   ENEMY of the PEOPLE and ...  ");
	  mvprintw(15,24,"       Summarily EXECUTED       ");
	}
      key();
      return 1;
    }
}
