/*
  Financial account

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "account.h"

void account()
{
  erase();
  attron(GREEN);
  mvprintw( 1, 24, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
  attroff(GREEN);
  mvprintw( 3, 24, "         TREASURY REPORT        ");
  mvprintw(10, 24, "  The TREASURY %s $%d,000",
	   (treasury > 0 ) ? "holds" : "OWES",
	   abs(treasury));
  mvprintw(12, 24, "   MONTHLY COSTS are $%d,000 ", monthly_cost);
  if (swiss_bank_account)
    mvprintw(14, 24, "  [SWISS Acct holds $%d,000]", swiss_bank_account);
  key();
}
