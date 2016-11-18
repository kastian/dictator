#ifndef NEWS_H
#define NEWS_H

#include <stdlib.h>		/* rand() */

#include "curses.h"
#include "data.h"
#include "key.h"
#include "transfer.h"
#include "police_report.h"
#include "plot.h"

extern data NEWS[];
extern int NEWS_SIZE;

void news();

#endif
