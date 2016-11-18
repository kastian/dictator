#ifndef AUDIENCE_H
#define AUDIENCE_H

#include <stdlib.h>		/* rand() */
#include <string.h>

#include "data.h"
#include "curses.h"
#include "key.h"
#include "transfer.h"
#include "advice.h"
#include "cash_advice.h"
#include "account.h"

extern group GROUP[];
extern data PETITION[];

void audience();

#endif
