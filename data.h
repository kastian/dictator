#ifndef DATA_H
#define DATA_H

#include <stdio.h>		/* NULL */

#define increase(A) ((A) < 9) ? (A++) : (A) ; /* increase A but no more than 9 */
#define decrease(A) ((A) > 0) ? (A--) : (A) ; /* decrease A but no less than 0 */
#define limit(A)    ((A) < 0) ? (A = 0) : (A) ; (A > 9) ? (A = 9) : (A) ;

typedef struct t_group {
  short int       popularity;    /* Popularity 0-9 */
  short int       strength;	 /* Strength 0-9 */
  char            status;	 /* Status - (char, ':' - default, 'A' - assasination ,'R' - revolution) */
  struct t_group* allies;	 /* Allies to revolute */
  char*           name;		 /* Title */
  char*           fname;	 /* Centered 10 char name */
} group;

typedef struct t_data {
  unsigned short int used;	 /* 0 - no, 1 - yes */
  char   cost;			 /* Cost */
  char   monthly_cost;		 /* Montly cost */
  char*  popularity;		 /* Popularity to group 1-8 */
  char*  strength;		 /* Strength to group 1-6 */
  char*  text;			 /* Text */
  group* author;	         /* Which group invented, NULL for news */
} data;

#endif
