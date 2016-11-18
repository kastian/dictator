/*
  Dictator - remake of old ZX-Basic game.

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "dictator.h"

#define PROGRAM "dictator"
#define VERSION "0.92"
#define URL     "https://github.com/kastian/dictator"
#define MAIL    "kastian@mail.ru"
#define YEAR	"2016"

int main(int argc, char *argv[])
{

  char *short_options = "hv";
  struct option long_options[] = {
    {"help", 0, NULL, 'h'},
    {"version", 0, NULL, 'v'},
    {0, 0, 0, 0},
  };
  int next_option;
  do
    {
      next_option = getopt_long (argc, argv, short_options,
				 long_options, NULL);
      switch (next_option)
	{
	case 'v':
	  printf("%s %s\n", PROGRAM, VERSION);
	  printf("Copyright (C) 1983 Don Priestley - original zx-basic code.\n"
		 "Copyright (C) 1983 DkTRONICS - original zx-basic code.\n"
		 "2015 #kstn - port to C.\n");
	  exit (0);
	case 'h':
	case '?':
	  printf("%s - remake of old ZX-Basic game.\n", PROGRAM);
	  printf("Usage: %s\n", PROGRAM);
	  printf("Report bugs to: %s\n", MAIL);
	  printf("%s home page: <%s>\n", PROGRAM, URL);
	  exit(0);
	case -1:
	  break;
	default:
	  abort ();
	}
    }
  while (next_option != -1);

  srand(time(NULL));
  init_curses();
  history = load();  /* Restore max rating or set it to 0 */
  while (1)
    {
      intro();	     /* Courtesy to author */
      title();	     /* Main game title*/
      restore();     /* Restore variables to default */
      welcome();     /* Welcome screen */
      account();     /* Financial account */
      erase();
      free_report(); /* Free first secret police report */
      while (1)      /* Main game loop */
	{
	  minimal = rand()%3 + 2; 	                          /* Random minimal popularity/strenght per turn */
	  revolution_strength = rand()%3 + 10;                    /* Random revolution strength per turn */
	  month += 1;		                                  /* Next month */
	  erase();
	  mvprintw(11,24,"            MONTH %-2d            ", month);
	  key();
	  plot();                                                 /* Recount chances to assasination/revolution */
	  (treasury > 0) ? treasury -= monthly_cost : bankrupt(); /* Monthly cost */
	  audience();		                                  /* Monthly audience */
	  plot();			                          /* Recount chances to assasination/revolution */
	  if (assasination() || war())                            /* Check for assasination, then for war, leave if any of them success */
	    {
	      end();
	      break;
	    }
	  plot();					          /* Recount chances to assasination/revolution */
	  police_report();	                                  /* Look at results  */
	  decision();		                                  /* Presidential decision */
	  police_report(); 		                          /* And look at the results if any */
	  news();             	                                  /* Try to get news*/
	  if (revolution())                                       /* Check for revolutioun, break if success */
	    {
	      end();
	      break;
	    }
	}
    }
  finish_curses();
  return 0;
}
