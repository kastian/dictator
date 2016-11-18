/*
  Trying to assasinate dictator

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "assasination.h"

int assasination()
{
  group* ASASSINS = &GROUP[rand()%3];                                      /* Check random group 0-3 for assatination */
  if (ASASSINS->status != 'A')
    return 0;                                                              /* Return if they don't want assasination */
  erase();
  mvprintw(11,24,"      ASSASSINATION ATTEMPT     ");
  mvprintw(12,(24 + (32 - strlen(ASASSINS->name) - 10)/2),"by one of %s", ASASSINS->name); /* Centered */
  key();
  erase();
  if ( (ARMY->status == PEASANTS->status == LANDOWNERS->status == 'A')     /* If all ritumbans people dislike you */
       || (POLICE->popularity <= minimal || POLICE->strength <= minimal)   /*  or your secret police can't or don't want to guard you */
       || rand()%2)				                           /*  or you're just unlucky */
    {
      mvprintw(11,24,"          You're DEAD !         ");                  /* then you're DEAD! */
      alive = 0;
      key();
      return 1;
    }
  else
    {                                                                      /* You're ALIVE! */
      mvprintw(11,24,"         Attempt FAILED         ");
      key();
      return 0;
    }
}
