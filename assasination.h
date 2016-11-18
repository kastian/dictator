#ifndef ASSASINATION_H
#define ASSASINATION_H

#include <string.h>
#include <stdlib.h>		/* rand() */

#include "curses.h"
#include "data.h"
#include "key.h"

extern group  GROUP[];
extern group* ARMY;
extern group* PEASANTS;
extern group* LANDOWNERS;
extern group* POLICE;
extern int    alive;
extern int    minimal;

int assasination();

#endif
