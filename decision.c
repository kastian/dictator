/*
  Presidential decision

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "decision.h"

void decision()
{
  int y;			/* Number decision in group */
  int available_desisions;     	/* 'Available desicisions' flag */
  int r;			/* Decision number */
  int stolen;			/* Transfer to swiss bank account */

  char ch;
  int start;
  int end;
  int a;

  while(1)
    {
      erase();
      attron(YELLOW);
      mvprintw( 1, 24, "********************************");
      attroff(YELLOW);
      mvprintw( 3, 24, "     PRESIDENTIAL DECISION      ");
      mvprintw( 6, 24, " Try to ...                     ");
      mvprintw( 8, 24, "    1. PLEASE a GROUP           ");
      mvprintw(10, 24, "    2. PLEASE ALL GROUPS        ");
      mvprintw(12, 24, "    3. IMPROVE your CHANCES     ");
      mvprintw(14, 24, "    4. RAISE some CASH          ");
      mvprintw(16, 24, "    5. STRENGTHEN a GROUP       ");

      switch( key() )
	{
	case '1' : start = 0;  end = 5;  break;
	case '2' : start = 6;  end = 8;  break;
	case '3' : start = 9;  end = 12; break;
	case '4' : start = 13; end = 15; break;
	case '5' : start = 16; end = 18; break;
	default  : return;
	}
      erase();
      y = 1;
      available_desisions = 0;	                           /* Reset 'available desisons' flag */
      move(5, 24);
      for (a = start; a <= end; a++)                       /* For all DECISIONs in subgroup */
	{
	  if (! DECISION[a].used)
	    {
	      available_desisions = 1;                     /* Set flag, than you have at least one unused DECISION */
	      mvprintw(gety()+1,24,"%d.",y);		   /* Display DECISION num */
	      mvprintw(gety()+1,24,"%s",DECISION[a].text); /*    and text */
	    }
	  y++;			                           /* Increase DECISION number */
	}
      if (! available_desisions)                           /* If there isn't any unused DECISION in group */
	{
	  mvprintw(12, 24, "   ALL of this section USED UP  ");
	  key();
	  continue;
	}
      ch = key(); 		                           /* Select DECISION */
      if (ch < '1' || ch > ('1' + end - start) )
	continue;
      r = start + ch - '0' - 1;	                           /* Determine DECISION nubmer in DECISION[] */
      if (DECISION[r].used)                                /* Do not use already used but not shown decision */
	continue;
      if (r == 12 || r == 13 || r == 14)		   /* If DECISION is swiss bank or get loan */
	break;
      advice(&DECISION[r]);
      attron(A_BOLD);
      mvprintw(3, 24, "%s", DECISION[r].text);
      attroff(A_BOLD);
      if (cash_advice(&DECISION[r]) && key())              /* Check for money for this DECISION */
	continue;
      if (key_y())		                           /* Run DECISION or select another */
	break;
    }

  switch(r)		/* Run decision */
    {
    case 10 :		/* Increase bodyguard */
      your_strength += 2;
      account();
      transfer(&DECISION[r]);
      break;
    case 12 : 		/* Transfer to swiss bank */
      erase();
      mvprintw(3, 24, "TRANSFER to a SWISS BANK ACCOUNT");
      stolen = treasury/2;
      if (stolen > 0) 	/* If there is anything to steal in treasury */
	{
	  mvprintw(11, 24, "The TREASURY held $%d, 000",  treasury);
	  swiss_bank_account += stolen;
	  treasury -= stolen;
	  mvprintw(13, 24, "$%d, 000 has been TRANSFERRED",  stolen);
	}
      else
	mvprintw(11, 31, "NO TRANSFER made");
      key();
      break;
    case 13 : case 14 : /* Try to get money from russian or americans */
      aid(&DECISION[r]);
      break;
    default :		/* Or just run usual decision */
      account();
      transfer(&DECISION[r]);
    }
  if (DECISION[r].cost != 'M' || DECISION[r].monthly_cost != 'M') /* If DECISION costed any money */
    account();                                                    /* Post financial account - show changes */
}
