#ifndef WAR_H
#define WAR_H

#include <stdlib.h>		/* rand() */

#include "curses.h"
#include "data.h"
#include "key.h"

extern group GROUP[];
extern group* POLICE;
extern group* LEFTOTANS;
extern data* HELICOPTER;
extern int minimal;
extern int your_strength;
extern int alive;

int war();

#endif
