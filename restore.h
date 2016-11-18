#ifndef RESTORE_H
#define RESTORE_H

#include <stdio.h>

#include "data.h"

extern data PETITION[];
extern data NEWS[];
extern data DECISION[];
extern group GROUP[];
extern int treasury;
extern int monthly_cost;
extern int your_strength;
extern int swiss_bank_account;
extern int alive;
extern int month;
extern int plot_bonus;
extern int revolution_strength;
extern int minimal;

void restore();

#endif
