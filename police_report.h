#ifndef POLICE_REPORT_H
#define POLICE_REPORT_H

#include "curses.h"
#include "data.h"
#include "key.h"

extern group GROUP[];
extern group* POLICE;
extern int treasury;
extern int minimal;
extern int month;
extern int your_strength;
extern int revolution_strength;

void free_report();
void police_report();

#endif
