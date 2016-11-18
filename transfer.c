/*
  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "transfer.h"

void transfer(data* DATA)
{
  int a;
  if (DATA->text[31] != '*')          /* Set data status to 'used' if it isn't reusable */
    DATA->used = 1;
  for (a = 0; a < 8; a++)     	      /* Set DATA popularity changes to all groups */
    {
      if (DATA->popularity[a] != 'M') /* Next group if DATA doesn't change this group */
	{
	  GROUP[a].popularity += DATA->popularity[a] - 'M';
	  limit(GROUP[a].popularity);
	}
    }
  for (a = 0; a < 6; a++)             /* Set DATA strength changes to all groups except russians and americans*/
    {
      if (DATA->strength[a] != 'M')   /* Next group if DATA doesn't change this group */
	{
	  GROUP[a].strength += DATA->strength[a] - 'M';
	  limit(GROUP[a].strength);
	}
    }
  treasury += 10 * (DATA->cost - 'M');
  monthly_cost -= DATA->monthly_cost - 'M';
  if (monthly_cost < 0)
    monthly_cost = 0;
}
