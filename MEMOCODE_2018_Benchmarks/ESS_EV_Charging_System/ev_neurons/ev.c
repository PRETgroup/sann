/* sscc : C CODE OF SORTED EQUATIONS ev - INLINE MODE */

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
#define __ev_GENERIC_TEST(TEST) return TEST;
typedef void (*__ev_APF)();
static __ev_APF *__ev_PActionArray;

#include "ev.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _systemUpdate_DEFINED
#ifndef systemUpdate
extern float systemUpdate();
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _predictPrice_DEFINED
#ifndef predictPrice
extern void predictPrice();
#endif
#endif
#ifndef _predictDemand_DEFINED
#ifndef predictDemand
extern void predictDemand();
#endif
#endif
#ifndef _runQValues_DEFINED
#ifndef runQValues
extern void runQValues(float ,float);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static float __ev_V0;
static boolean __ev_V1;
static float __ev_V2;
static boolean __ev_V3;
static float __ev_V4;


/* INPUT FUNCTIONS */

void ev_I_price (float __V) {
__ev_V0 = __V;
__ev_V1 = _true;
}
void ev_I_demand (float __V) {
__ev_V2 = __V;
__ev_V3 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __ev_A1 \
__ev_V1
#define __ev_A2 \
__ev_V3

/* OUTPUT ACTIONS */

#define __ev_A3 \
ev_O_watts(__ev_V4)

/* ASSIGNMENTS */

#define __ev_A4 \
__ev_V1 = _false
#define __ev_A5 \
__ev_V3 = _false
#define __ev_A6 \
__ev_V4 = systemUpdate()

/* PROCEDURE CALLS */

#define __ev_A7 \
predictPrice()
#define __ev_A8 \
predictDemand()
#define __ev_A9 \
runQValues(__ev_V0,__ev_V2)

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __ev_A10 \

#define __ev_A11 \

#define __ev_A12 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int ev_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __ev__reset_input () {
__ev_V1 = _false;
__ev_V3 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __ev_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int ev () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[5];
E[0] = __ev_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ev_A1));
if (E[0]) {
__ev_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A10\n");
#endif
}
E[1] = __ev_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ev_A2));
if (E[1]) {
__ev_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A11\n");
#endif
}
if (__ev_R[0]) {
__ev_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A12\n");
#endif
}
E[2] = __ev_R[1]&&!(__ev_R[0]);
if (E[2]) {
__ev_A7;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A7\n");
#endif
}
if (E[2]) {
__ev_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A8\n");
#endif
}
if (E[2]) {
__ev_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A9\n");
#endif
}
if (E[2]) {
__ev_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A6\n");
#endif
}
if (E[2]) {
__ev_A3;
#ifdef TRACE_ACTION
fprintf(stderr, "__ev_A3\n");
#endif
}
E[3] = !(_true);
__ev_R[1] = __ev_R[0]||E[2];
E[4] = __ev_R[1];
__ev_R[0] = !(_true);
__ev__reset_input();
return E[4];
}

/* AUTOMATON RESET */

int ev_reset () {
__ev_R[0] = _true;
__ev_R[1] = _false;
__ev__reset_input();
return 0;
}
