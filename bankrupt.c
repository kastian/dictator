/*
  If there is nothing in treasury

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "bankrupt.h"

void bankrupt()
{
  erase();
  mvprintw( 5,24,"   The TREASURY is BANKRUPT    ");
  mvprintw( 9,24,"Your POPULARITY with the ARMY &");
  mvprintw(11,24," the SECRET POLICE will DROP ! ");
  mvprintw(13,24,"    POLICE STRENGTH will drop  ");
  mvprintw(15,24,"and YOUR own STRENGTH will DROP");
  decrease(ARMY->popularity);   /* Decrease popularity with ARMY */
  decrease(POLICE->popularity); /* Decrease popularity with SECRET POLICE */
  decrease(POLICE->strength);   /* Decrease SECRET POLICE strength */
  decrease(your_strength);      /* And your own strength */
  key();
  plot();                       /* Recount chances to assasination/revolution */
  police_report();		/* And look at results */
}
