/*
  Check do you can afford DECISION or PETITION

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "cash_advice.h"

int cash_advice(data* DATA)
{
  int y = 7 ;
  int cost = 10 * (DATA->cost - 'M');
  int monthly_cost = DATA->monthly_cost - 'M';
  if (cost == 0 && monthly_cost == 0) 	                           /* If DATA costs nothing */
    {
      mvprintw(11,24,"        NO MONEY INVOLVED       ");
      return 0;
    }
  	                                                           /* If DATA costs money */
  if ( (cost < 0 || monthly_cost < 0)
       && (treasury + cost < 0 || treasury + monthly_cost < 0) )   /* But you can't afford it */
    {
      if (DATA->author == NULL)                                    /* And this is a DECISION */
	{
	  mvprintw(11,24,"  The CASH for this decision is ");
	  mvprintw(12,24,"       NOT in the TREASURY      ");
	  y = 15;
	  if (! RUSSIAN_AID->used)
	    mvprintw(y++,24," Perhaps the RUSSIANS can help ?");
	  if (! AMERICAN_AID->used)
	    mvprintw(y++,24,"THE AMERICANS are generous folk ");
	}
      else			                                   /* Or this is a PETITION */
	{
	  mvprintw(11,24," You have INSUFFICIENT FUNDS to ");
	  mvprintw(12,24,"     PAY for this DECISION.     ");
	  mvprintw(13,24,"     Your answer MUST be NO     ");
	}
      return 1; 		                                   /* At any case */
    }
  else   			                                   /* You can afford this DATA */
    {
      mvprintw(y+=2,24,"       This decision would      ");
      if (cost != 0)
	{
	  mvprintw(y+=2,24," %s the TREASURY $%d,000",
		   (cost > 0 ) ? "ADD to" : "TAKE from",
		   abs(cost));
	}
      if (monthly_cost != 0)
	{
	  if (cost != 0)
	    mvprintw(y+=2,24,"               and              ");
	  mvprintw(y+=2,24," %s MONTHLY COSTS by $%d,000",
		   (monthly_cost < 0 ) ? "RAISE" : "LOWER",
		   abs(monthly_cost));
	}
      return 0;
    }
}
