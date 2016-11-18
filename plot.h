#ifndef PLOT_H
#define PLOT_H

#include <stdio.h>

#include "data.h"

extern group GROUP[];
extern int month;
extern int plot_bonus;
extern int minimal;
extern int revolution_strength;

void plot();
void reset_plot();

#endif
