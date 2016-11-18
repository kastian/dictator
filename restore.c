/*
  Restore game variables to default

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "restore.h"

void restore()
{
  int a;
  for (a = 0; a < 24; a++)     /* Restore all PETITIONS status to unused */
    PETITION[a].used = 0;
  for (a = 0; a < 6; a++)      /* Restore all NEWS status to unused */
    NEWS[a].used = 0 ;
  for (a = 0; a < 19; a++)     /* Restore all DECISIONS status to unused */
    DECISION[a].used = 0;
  for (a = 0; a < 8; a++)      /* Restore all GROUPS */
    {
      GROUP[a].popularity = 7; /*  popularity */
      GROUP[a].strength = 6;   /*  strength */
      GROUP[a].status = ' ';   /*  status */
      GROUP[a].allies = NULL;  /*  and allies */
    }
  GROUP[3].popularity = 0;     /* fix GUERILLAS popularity */
  GROUP[6].strength = 0;       /* fix RUSSIAN strength */
  GROUP[7].strength = 0;       /* fix AMERICANS strength */

  treasury = 1000;             /* Set default money */
  monthly_cost = 60;           /* Set default montly cost */
  your_strength = 4;	       /* Set default player's strength */
  swiss_bank_account = 0;      /* Set swiss bank account */
  alive = 1;		       /* Set 'alive' flag */
  month = 0;                   /* Set month */
  plot_bonus = 0;	       /* Set plot bonus */
  revolution_strength = 10;    /* Set default revolution strenght (for first SECRET POLICE report) */
  minimal = 0;       	       /* Set default minimal popularity/strenght (for first SECRET POLICE report) */
}
