#ifndef DECISION_H
#define DECISION_H

#include "curses.h"
#include "data.h"
#include "key.h"
#include "transfer.h"
#include "aid.h"
#include "cash_advice.h"
#include "account.h"
#include "advice.h"

extern data DECISION[];
extern int your_strength;
extern int treasury;
extern int swiss_bank_account;

void decision();

#endif
