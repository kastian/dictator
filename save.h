#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>		/* getuid() */

char* savename();
int load();
void save(int);

#endif
