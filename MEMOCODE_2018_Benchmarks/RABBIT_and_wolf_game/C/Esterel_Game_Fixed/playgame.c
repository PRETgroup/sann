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



/* INPUT FUNCTIONS */


/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

/* OUTPUT ACTIONS */

/* ASSIGNMENTS */

/* PROCEDURE CALLS */

#define __playgame_A1 \
rabbit_decide()
#define __playgame_A2 \
wolf1_decide()
#define __playgame_A3 \
wolf2_decide()
#define __playgame_A4 \
rabbit_move()
#define __playgame_A5 \
wolf1_move()
#define __playgame_A6 \
wolf2_move()

/* CONDITIONS */

#define __playgame_A7 \
check_score()
#define __playgame_A8 \
check_score()
#define __playgame_A9 \
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
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __playgame_R[3] = {_true,
 _false,
 _false};

/* AUTOMATON ENGINE */

int playgame () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[10];
E[0] = __playgame_R[2]&&!(__playgame_R[0]);
if (E[0]) {
__playgame_A4;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A4\n");
#endif
}
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__playgame_A7);
E[2] = E[0]&&!(E[1]);
if (E[2]) {
__playgame_A5;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A5\n");
#endif
}
E[3] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__playgame_A8);
E[4] = E[2]&&!(E[3]);
if (E[4]) {
__playgame_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A6\n");
#endif
}
E[5] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__playgame_A9);
E[6] = E[4]&&!(E[5]);
E[7] = E[2]||E[4]||E[6];
E[8] = E[1]||E[3]||E[5];
E[5] = E[1]||E[3]||E[5];
E[6] = __playgame_R[0]||E[6];
E[3] = __playgame_R[1]&&!(__playgame_R[0]);
if (E[3]) {
__playgame_A1;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A1\n");
#endif
}
if (E[3]) {
__playgame_A2;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A2\n");
#endif
}
if (E[3]) {
__playgame_A3;
#ifdef TRACE_ACTION
fprintf(stderr, "__playgame_A3\n");
#endif
}
E[1] = E[6]||E[3];
E[9] = __playgame_R[1]||__playgame_R[2];
__playgame_R[0] = !(_true);
__playgame_R[1] = E[6];
__playgame_R[2] = E[3];
__playgame__reset_input();
return E[1];
}

/* AUTOMATON RESET */

int playgame_reset () {
__playgame_R[0] = _true;
__playgame_R[1] = _false;
__playgame_R[2] = _false;
__playgame__reset_input();
return 0;
}
