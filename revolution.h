#ifndef REVOLUTION_H
#define REVOLUTION_H

#include <string.h>
#include <stdlib.h>		/* rand() */

#include "curses.h"
#include "data.h"
#include "key.h"
#include "police_report.h"
#include "plot.h"

extern group GROUP[];
extern group* GUERILLAS;
extern data* HELICOPTER;
extern int alive;
extern int minimal;
extern int plot_bonus;
extern int month;
extern int your_strength;

int revolution();
void escape_to_leftoto();

#endif
