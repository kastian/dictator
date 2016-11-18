#ifndef AID_H
#define AID_H

#include <stdlib.h>		/* rand() */

#include "curses.h"
#include "data.h"
#include "key.h"

extern data DECISION[];
extern group* RUSSIANS;

extern int month;
extern int minimal;
extern int treasury;

void aid(data*);

#endif
