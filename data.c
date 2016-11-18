/*
  All global variables

  Copyright (C) 1983 Don Priestley - original zx-basic code.
  Copyright (C) 1983 DkTRONICS - original zx-basic code.

  2015 #kstn - port to C.
*/

#include "data.h"

int history; 			/* Top rating */
int treasury;			/* Money */
int monthly_cost;		/* Monthly cost */
int your_strength;		/* Your strength */
int swiss_bank_account;		/* Swiss bank account */
int month;			/* Month */
int plot_bonus;			/* Plot bonus*/
int revolution_strength;	/* Revolution strength */
int alive; 			/* 1 - alive, 0 - dead */
int minimal;                    /* Minimal revolution strength */

group GROUP[] = {
  { 7, 6, ' ', NULL, "The ARMY"         , "   ARMY   " },
  { 7, 6, ' ', NULL, "The PEASANTS"     , " PEASANTS " },
  { 7, 6, ' ', NULL, "The LANDOWNERS"   , "LANDOWNERS" },
  { 0, 6, ' ', NULL, "The GUERILLAS"    , "GUERILLAS " },
  { 7, 6, ' ', NULL, "The LEFTOTANS"    , "LEFTOTANS " },
  { 7, 6, ' ', NULL, "The SECRET POLICE", " S.POLICE " },
  { 7, 0, ' ', NULL, "The RUSSIANS"     , " RUSSIANS " },
  { 7, 0, ' ', NULL, "The AMERICANS"    , "AMERICANS " },
};

/* Named poiners to groups - mostly for readability in functions */
group* ARMY       = &GROUP[0];
group* PEASANTS   = &GROUP[1];
group* LANDOWNERS = &GROUP[2];
group* GUERILLAS  = &GROUP[3];
group* LEFTOTANS  = &GROUP[4];
group* POLICE     = &GROUP[5];
group* RUSSIANS   = &GROUP[6];
group* AMERICANS  = &GROUP[7];

data PETITION[] = {
  { 0, 'M', 'H', "QJLMMMMM", "PKLMMM", "     INTRODUCE CONSCRIPTION     ", &GROUP[0], }, /* The ARMY */
  { 0, 'M', 'M', "PMJMMMMM", "NMLMMM", " REQUISITION LAND for TRAINING  ", &GROUP[0], },
  { 0, 'C', 'M', "PLNMLMLM", "NMNIMM", "   ATTACK ALL GUERILLA BASES    ", &GROUP[0], },
  { 0, 'E', 'M', "PLMMIMLM", "NMNKMM", "ATTACK GUERILLA BASES in LEFTOTO", &GROUP[0], },
  { 0, 'M', 'M', "QONMMIMM", "NMNMMJ", "  SACK the SECRET POLICE CHIEF  ", &GROUP[0], },
  { 0, 'M', 'M', "PMMMLMIO", "MMMMMM", "EXPEL RUSSIAN MILITARY ADVISORS ", &GROUP[0], },
  { 0, 'M', 'D', "QMLMMMMM", "OLLLMM", " INCREASE the PAY of the TROOPS ", &GROUP[0], },
  { 0, 'A', 'M', "QLLMLLMM", "PLLKLM", "  BUY MORE ARMS and AMMUNITION  ", &GROUP[0], },
  { 0, 'M', 'M', "LONMMMMM", "LMMLMM", "   STOP ARMY SIGN-UP COERCION   ", &GROUP[1], }, /* The PEASANTS */
  { 0, 'M', 'M', "MQIMNMMM", "MOLMMM", "INCREASE the BASIC MINIMUM WAGE ", &GROUP[1], },
  { 0, 'M', 'P', "NQOMMIMM", "NNNNMJ", " CUT the POWERS of the S.POLICE ", &GROUP[1], },
  { 0, 'M', 'M', "MPKMKMMM", "MOKMMM", "STOP LEFTOTAN IMMIGRANT WORKERS ", &GROUP[1], },
  { 0, 'C', 'E', "LQKMOLNM", "MNLLMM", "INTRODUCE FREE EDUCATION for ALL", &GROUP[1], },
  { 0, 'M', 'M', "MQJMNLNM", "MPJMML", "LEGALISE the FORMATION of UNIONS", &GROUP[1], },
  { 0, 'M', 'M', "LQKMNLMM", "MOLLMM", "  FREE their IMPRISONED LEADER  ", &GROUP[1], },
  { 0, 'M', 'S', "MPLMMMMM", "MMMLMM", "     START a PUBLIC LOTTERY     ", &GROUP[1], },
  { 0, 'M', 'M', "KMPMMMMM", "LMMMMM", "STOP MILITARY USE of THEIR LAND ", &GROUP[2], }, /* The LANDOWNERS */
  { 0, 'M', 'M', "MIQMLMLM", "MKONMM", "  LOWER the BASIC MINIMUM WAGE  ", &GROUP[2], },
  { 0, 'W', 'H', "MMPMNMOI", "MMNMMM", "NATIONALISE AMERICAN BUSINESSES ", &GROUP[2], },
  { 0, 'M', 'R', "MMPMJMLM", "MNOMLM", "LEVY DUTY on ALL LEFTOTO IMPORTS", &GROUP[2], },
  { 0, 'M', 'Q', "NNPMMIMM", "NMNNMK", " CUT SPENDING on the S. POLICE  ", &GROUP[2], },
  { 0, 'M', 'H', "MMQMMMMM", "MMOMMM", "  DECREASE HEAVY LAND TAXATION  ", &GROUP[2], },
  { 0, 'M', 'M', "KLPMMMMM", "LLNNMM", "RELEASE TROOPS to WORK the LAND ", &GROUP[2], },
  { 0, 'A', 'C', "NNPMJMON", "MMPMKM", "BUILD a LARGE IRRIGATION SYSTEM ", &GROUP[2], },
};

int NEWS_SIZE = 6; /* For news(). Change it if you add any new news */
data NEWS[] = {
  { 0, 'M', 'M', "MMMMMIMM", "MMMQMI", " PRESIDENT LOSES S.POLICE FILES ", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "LMMVMM", " CUBANS ARM and TRAIN GUERILLAS ", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "IMMOMN", "ACCIDENT. ARMY BARRACKS BLOWS UP", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "MMJMKM", "   BANANA PRICES FALL by 98%    ", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "MMOMIM", "  MAJOR EARTHQUAKE in LEFTOTO   ", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "MILKMM", "A PLAGUE SWEEPS through PEASANTS", NULL, },
};

data DECISION[] = {
  { 0, 'M', 'M', "QLLMMLMM", "NMMLML", "MAKE ARMY CHIEF \"VICE-PRESIDENT\" ", NULL, },     /* 1. PLEASE a GROUP */
  { 0, 'L', 'I', "LQNMOMNM", "MMMLMM", "SET UP FREE CLINICS for WORKERS ", NULL, },
  { 0, 'M', 'M', "LKQMMLLM", "LLOMML", "GIVE LANDOWNERS REGIONAL POWERS ", NULL, },
  { 0, 'R', 'M', "KMMMQMKN", "LMMLPM", "SELL AMERICAN ARMS to LEFTOTO   ", NULL, },
  { 0, 'Y', 'M', "MMLMLMKP", "MMMMMM", "SELL MINING RIGHTS to U.S. FIRMS", NULL, },
  { 0, 'M', 'W', "KMMMMMPJ", "MMMMNM", "RENT the RUSSIANS a NAVAL BASE  ", NULL, },
  { 0, 'M', 'E', "NPPMMMMM", "LMMLMM", "DECREASE GENERAL TAXATION LEVEL ", NULL, },     /* 2. PLEASE ALL GROUPS  */
  { 0, 'E', 'M', "PPPMMMMM", "MMMLMM", "STAGE a BIG POPULARITY CAMPAIGN ", NULL, },
  { 0, 'M', 'U', "PPPMMDMM", "ONNNMD", "CUT S.POLICE POWERS COMPLETELY  ", NULL, },
  { 0, 'M', 'G', "JJJMMUMM", "LLLLMU", "INCREASE S.POLICE POWERS a LOT  ", NULL, },       /* 3. IMPROVE your CHANCES */
  { 0, 'I', 'M', "KLLMMLMM", "KMMMML", "INCREASE YOUR BODYGUARD        *", NULL, },
  { 0, 'A', 'M', "IIJMMKMM", "MMMMMM", "BUY an ESCAPE HELICOPTER        ", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "MMMMMM", "SEE TO YOUR SWISS BANK ACCOUNT *", NULL, },
  { 0, 'M', 'M', "MMMMMMMM", "MMMMMM", "ASK the RUSSIANS for a \"LOAN\"  *", &GROUP[6], }, /* 4.RAISE some CASH */
  { 0, 'M', 'M', "MMMMMMMM", "MMMMMM", "ASK AMERICANS for FOREIGN \"AID\"*", &GROUP[7], },
  { 0, 'Z', 'M', "NNPMGMKM", "MMMMMM", "NATIONALISE LEFTOTAN BUSINESSES ", NULL, },
  { 0, 'H', 'M', "PMMMJMLM", "RMMKKL", "BUY HEAVY ARTILLERY for THE ARMY", NULL, },       /* 5.STRENGTHEN a GROUP */
  { 0, 'M', 'M', "MPLMMLMM", "MRLPML", "ALLOW PEASANTS FREE MOVEMENT    ", NULL, },
  { 0, 'M', 'M', "LLPMMLMM", "LLRLML", "ALLOW LANDOWNERS PRIVATE MILITIA", NULL, },
};

/* Named poiners to decisions - mostly for readability in functions */
data* HELICOPTER   = &DECISION[11];
//data* SWISS_BANK   = &DECISION[12];
data* RUSSIAN_AID  = &DECISION[13];
data* AMERICAN_AID = &DECISION[14];
