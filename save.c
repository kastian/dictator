/*
  Load previous record and save new

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "save.h"

#define SAVEFILE ".dictator"

char* savedir()        /* Define savedir */
{
  struct passwd* pw = getpwuid(getuid());
  return pw->pw_dir;
}

int load()              /* Load history */
{
  FILE* fp;
  int history = 0;

  if (chdir(savedir()) == 0)
    {
      fp = fopen(SAVEFILE, "r");
      if (fp != NULL)
	{
	  if (fscanf(fp, "%d", &history) == EOF)
	    history = 0;
	  fclose(fp);
	}
    }
  return history;
}

void save(int history)   /* Save history */
{
  FILE *fp;

  if (chdir(savedir()) == 0)
    {
      fp = fopen(SAVEFILE, "w");
      if (fp != NULL)
	{
	  fprintf(fp, "%d", history);
	  fclose(fp);
	}
    }
}
