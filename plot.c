/*
  Plot

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "plot.h"

void plot()
{
  int a, p;
  if (month < 3)                                                            /* Do not assatinations or revolutions as first two month */
    return;
  reset_plot();                                                             /* Reset army, peasants and landowners statuses and allies */
  if (month < plot_bonus)                                                   /* Do not assatinations or revolutions two month after failed revolution */
    return;
  for (a = 0; a < 3; a++)
    {
      if (GROUP[a].popularity > minimal)                                    /* Next group if this group popularity > minimal */
	continue;
      for (p = 0; p < 6; p++) 	                                            /* Try to find allies for revolution */
	{
	  if (a == p || GROUP[p].popularity > minimal)                      /* Next group if it is the same group or popularity > minimal */
	    continue;
	  if (GROUP[a].strength + GROUP[p].strength >= revolution_strength) /* If their combined strength > minimal revolution strength */
	    {
	      GROUP[a].status = 'R';	                                    /* Set status */
	      GROUP[a].allies = &GROUP[p];                                  /* Set pointer to ally group */
	      break;
	    }
	}
      if (GROUP[a].status == ' ')                                           /* Or set group status to assasination if group couldn't find allies */
	GROUP[a].status = 'A';
    }
}

/*
   Reset army, peasants and landowners statuses and allies
*/
void reset_plot()
{
  int a;
  for (a = 0; a < 3; a++)
    {
      GROUP[a].status = ' ';
      GROUP[a].allies = NULL;
    }
}
