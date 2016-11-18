#ifndef CASH_ADVICE_H
#define CASH_ADVICE_H

#include <stdio.h>
#include <stdlib.h>             /* abs() */

#include "curses.h"
#include "data.h"

extern int treasury;
extern data* RUSSIAN_AID;
extern data* AMERICAN_AID;

int cash_advice(data*);

#endif
