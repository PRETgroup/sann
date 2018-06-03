/* sscc : C CODE OF SORTED EQUATIONS playgame - INLINE MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define _true 1
#define _false 0
#define __playgame_GENERIC_TEST(TEST) return TEST;
typedef void (*__playgame_APF)();
static __playgame_APF *__playgame_PActionArray;

#include "playgame.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _check_score_DEFINED
#ifndef check_score
extern boolean check_score();
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _init_DEFINED
#ifndef init
extern void init();
#endif
#endif
#ifndef _rabbit_decide_DEFINED
#ifndef rabbit_decide
extern void rabbit_decide();
#endif
#endif
#ifndef _wolf1_decide_DEFINED
#ifndef wolf1_decide
extern void wolf1_decide();
#endif
#endif
#ifndef _wolf2_decide_DEFINED
#ifndef wolf2_decide
extern void wolf2_decide();
#endif
#endif
#ifndef _rabbit_move_DEFINED
#ifndef rabbit_move
extern void rabbit_move();
#endif
#endif
#ifndef _wolf1_move_DEFINED
#ifndef wolf1_move
extern void wolf1_move();
#endif
#endif
#ifndef _wolf2_move_DEFINED
#ifndef wolf2_move
extern void wolf2_move();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __playgame_V0;


/* INPUT FUNCTIONS */

void playgame_I_start () {
__playgame_V0 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __playgame_A1 \
__playgame_V0

/* OUTPUT ACTIONS */

/* ASSIGNMENTS */

#define __playgame_A2 \
__playgame_V0 = _false

/* PROCEDURE CALLS */

#define __playgame_A3 \
init()
#define __playgame_A4 \
rabbit_decide()
#define __playgame_A5 \
wolf1_decide()
#define __playgame_A6 \
wolf2_decide()
#define __playgame_A7 \
rabbit_move()
#define __playgame_A8 \
wolf1_move()
#define __playgame_A9 \
wolf2_move()

/* CONDITIONS */

#define __playgame_A10 \
check_score()
#define __playgame_A11 \
check_score()
#define __playgame_A12 \
check_score()

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int playgame_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __playgame__reset_input () {
__playgame_V0 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __playgame_R[16] = {_false,
 _false,
 _true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int playgame () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[37];
E[0] = __playgame_R[3]&&!(__playgame_R[2]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__playgame_A1);
if (E[1]) {
__playgame_A3;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A3\n");
#endif
}
E[2] = __playgame_R[15]&&!(__playgame_R[2]);
E[3] = __playgame_R[12]&&!(__playgame_R[2]);
E[4] = __playgame_R[14]&&!(__playgame_R[2]);
E[5] = __playgame_R[11]&&!(__playgame_R[2]);
E[6] = __playgame_R[13]&&!(__playgame_R[2]);
E[7] = __playgame_R[10]&&!(__playgame_R[2]);
E[8] = E[7]&&__playgame_R[1];
if (E[8]) {
__playgame_A7;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A7\n");
#endif
}
E[9] = E[6]&&E[8];
E[10] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__playgame_A10);
E[9] = E[9]&&!(E[10]);
E[11] = E[5]&&E[9];
if (E[11]) {
__playgame_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A8\n");
#endif
}
E[12] = E[4]&&E[11];
E[13] = E[12]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 11\n"),
#endif
__playgame_A11);
E[12] = E[12]&&!(E[13]);
E[14] = E[3]&&E[12];
if (E[14]) {
__playgame_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A9\n");
#endif
}
E[15] = E[2]&&E[14];
E[16] = E[15]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 12\n"),
#endif
__playgame_A12);
E[15] = E[15]&&!(E[16]);
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__playgame_A1));
E[17] = __playgame_R[4]&&!(__playgame_R[2]);
E[18] = E[17]&&__playgame_R[0];
if (E[18]) {
__playgame_A4;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A4\n");
#endif
}
E[17] = E[18]||(__playgame_R[4]&&E[17]&&!(__playgame_R[0]));
E[19] = __playgame_R[5]&&!(__playgame_R[2]);
E[20] = E[19]&&__playgame_R[0];
if (E[20]) {
__playgame_A5;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A5\n");
#endif
}
E[19] = E[20]||(__playgame_R[5]&&E[19]&&!(__playgame_R[0]));
E[21] = __playgame_R[6]&&!(__playgame_R[2]);
E[22] = E[21]&&__playgame_R[0];
if (E[22]) {
__playgame_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A6\n");
#endif
}
E[21] = E[22]||(__playgame_R[6]&&E[21]&&!(__playgame_R[0]));
E[23] = __playgame_R[7]&&!(__playgame_R[2]);
E[24] = E[23]&&E[18];
E[25] = __playgame_R[8]&&!(__playgame_R[2]);
E[26] = E[25]&&E[20];
E[27] = __playgame_R[9]&&!(__playgame_R[2]);
E[28] = E[27]&&E[22];
E[29] = __playgame_R[7]||__playgame_R[8]||__playgame_R[9];
E[30] = (E[29]&&!(__playgame_R[7]))||E[24];
E[31] = (E[29]&&!(__playgame_R[8]))||E[26];
E[32] = (E[29]&&!(__playgame_R[9]))||E[28];
E[28] = (E[24]||E[26]||E[28])&&E[30]&&E[31]&&E[32];
E[23] = __playgame_R[7]&&E[23]&&!(E[18]);
E[25] = __playgame_R[8]&&E[25]&&!(E[20]);
E[27] = __playgame_R[9]&&E[27]&&!(E[22]);
E[32] = (E[23]||E[25]||E[27])&&(E[30]||E[23])&&(E[31]||E[25])&&(E[32]||E[27]);
E[7] = E[8]||(__playgame_R[10]&&E[7]&&!(__playgame_R[1]));
E[5] = E[11]||(__playgame_R[11]&&E[5]&&!(E[9]));
E[3] = E[14]||(__playgame_R[12]&&E[3]&&!(E[12]));
E[6] = E[9]||(__playgame_R[13]&&E[6]&&!(E[8]));
E[4] = E[12]||(__playgame_R[14]&&E[4]&&!(E[11]));
E[2] = E[15]||(__playgame_R[15]&&E[2]&&!(E[14]));
E[12] = __playgame_R[3]||__playgame_R[4]||__playgame_R[5]||__playgame_R[6]||E[29]||__playgame_R[10]||__playgame_R[11]||__playgame_R[12]||__playgame_R[13]||__playgame_R[14]||__playgame_R[15];
E[9] = (E[12]&&!(__playgame_R[3]))||E[1]||E[0];
E[31] = (E[12]&&!(__playgame_R[4]))||E[17];
E[30] = (E[12]&&!(__playgame_R[5]))||E[19];
E[26] = (E[12]&&!(__playgame_R[6]))||E[21];
E[29] = (E[12]&&!(E[29]))||E[28]||E[32];
E[24] = (E[12]&&!(__playgame_R[10]))||E[7];
E[33] = (E[12]&&!(__playgame_R[11]))||E[5];
E[34] = (E[12]&&!(__playgame_R[12]))||E[3];
E[35] = (E[12]&&!(__playgame_R[13]))||E[6];
E[36] = (E[12]&&!(__playgame_R[14]))||E[4];
E[12] = (E[12]&&!(__playgame_R[15]))||E[2];
E[32] = (E[0]||E[17]||E[19]||E[21]||E[28]||E[32]||E[7]||E[5]||E[3]||E[6]||E[4]||E[2])&&E[9]&&E[31]&&E[30]&&E[26]&&E[29]&&E[24]&&E[33]&&E[34]&&E[35]&&E[36]&&E[12];
__playgame_R[0] = (E[1]||E[15])&&E[32];
__playgame_R[1] = E[28]&&E[32];
E[15] = E[10]||E[13]||E[16];
E[16] = (E[10]||E[13]||E[16])&&E[9]&&E[31]&&E[30]&&E[26]&&E[29]&&E[24]&&E[33]&&E[34]&&(E[35]||E[10])&&(E[36]||E[13])&&(E[12]||E[16]);
E[12] = E[16];
E[32] = __playgame_R[2]||E[32];
__playgame_R[3] = __playgame_R[2]||(E[0]&&!(E[16]));
__playgame_R[4] = __playgame_R[2]||(E[17]&&!(E[16]));
__playgame_R[5] = __playgame_R[2]||(E[19]&&!(E[16]));
__playgame_R[6] = __playgame_R[2]||(E[21]&&!(E[16]));
__playgame_R[7] = __playgame_R[2]||(E[23]&&!(E[16]))||(E[28]&&!(E[16]));
__playgame_R[8] = __playgame_R[2]||(E[25]&&!(E[16]))||(E[28]&&!(E[16]));
__playgame_R[9] = __playgame_R[2]||(E[27]&&!(E[16]))||(E[28]&&!(E[16]));
__playgame_R[10] = __playgame_R[2]||(E[7]&&!(E[16]));
__playgame_R[11] = __playgame_R[2]||(E[5]&&!(E[16]));
__playgame_R[12] = __playgame_R[2]||(E[3]&&!(E[16]));
__playgame_R[13] = __playgame_R[2]||(E[6]&&!(E[16]));
__playgame_R[14] = __playgame_R[2]||(E[4]&&!(E[16]));
__playgame_R[15] = __playgame_R[2]||(E[2]&&!(E[16]));
__playgame_R[2] = !(_true);
__playgame__reset_input();
return E[32];
}

/* AUTOMATON RESET */

int playgame_reset () {
__playgame_R[0] = _false;
__playgame_R[1] = _false;
__playgame_R[2] = _true;
__playgame_R[3] = _false;
__playgame_R[4] = _false;
__playgame_R[5] = _false;
__playgame_R[6] = _false;
__playgame_R[7] = _false;
__playgame_R[8] = _false;
__playgame_R[9] = _false;
__playgame_R[10] = _false;
__playgame_R[11] = _false;
__playgame_R[12] = _false;
__playgame_R[13] = _false;
__playgame_R[14] = _false;
__playgame_R[15] = _false;
__playgame__reset_input();
return 0;
}
