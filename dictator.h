#ifndef DICTATOR_H
#define DICTATOR_H

#include <time.h>		/* srand() */
#include <getopt.h>

#include "curses.h"
#include "data.h"
#include "intro.h"
#include "title.h"
#include "welcome.h"
#include "account.h"
#include "police_report.h"
#include "key.h"
#include "save.h"
#include "restore.h"
#include "plot.h"
#include "bankrupt.h"
#include "audience.h"
#include "assasination.h"
#include "war.h"
#include "end.h"
#include "decision.h"
#include "news.h"
#include "revolution.h"

extern int history;
extern int minimal;
extern int revolution_strength;
extern int month;
extern int treasury;
extern int monthly_cost;

#endif
