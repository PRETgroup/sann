/* sscc : C CODE OF SORTED EQUATIONS adder - INLINE MODE */

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
#define __adder_GENERIC_TEST(TEST) return TEST;
typedef void (*__adder_APF)();
static __adder_APF *__adder_PActionArray;

#include "adder.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _addLayer2_DEFINED
#ifndef addLayer2
extern integer addLayer2();
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _addLayer1_DEFINED
#ifndef addLayer1
extern void addLayer1(integer ,integer);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __adder_V0;
static integer __adder_V1;
static boolean __adder_V2;
static integer __adder_V3;
static boolean __adder_V4;
static integer __adder_V5;


/* INPUT FUNCTIONS */

void adder_I_add () {
__adder_V0 = _true;
}
void adder_I_num1 (integer __V) {
__adder_V1 = __V;
__adder_V2 = _true;
}
void adder_I_num2 (integer __V) {
__adder_V3 = __V;
__adder_V4 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __adder_A1 \
__adder_V0
#define __adder_A2 \
__adder_V2
#define __adder_A3 \
__adder_V4

/* OUTPUT ACTIONS */

#define __adder_A4 \
adder_O_sum(__adder_V5)

/* ASSIGNMENTS */

#define __adder_A5 \
__adder_V0 = _false
#define __adder_A6 \
__adder_V2 = _false
#define __adder_A7 \
__adder_V4 = _false
#define __adder_A8 \
__adder_V5 = addLayer2()

/* PROCEDURE CALLS */

#define __adder_A9 \
addLayer1(__adder_V1,__adder_V3)

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __adder_A10 \

#define __adder_A11 \

#define __adder_A12 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int adder_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __adder__reset_input () {
__adder_V0 = _false;
__adder_V2 = _false;
__adder_V4 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __adder_R[3] = {_true,
 _false,
 _false};

/* AUTOMATON ENGINE */

int adder () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[8];
E[0] = __adder_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__adder_A2));
if (E[0]) {
__adder_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__adder_A10\n");
#endif
}
E[1] = __adder_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__adder_A3));
if (E[1]) {
__adder_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__adder_A11\n");
#endif
}
if (__adder_R[0]) {
__adder_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__adder_A12\n");
#endif
}
E[2] = __adder_R[2]&&!(__adder_R[0]);
if (E[2]) {
__adder_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__adder_A8\n");
#endif
}
if (E[2]) {
__adder_A4;
#ifdef TRACE_ACTION
fprintf(stderr, "__adder_A4\n");
#endif
}
E[3] = !(_true);
E[4] = __adder_R[1]&&!(__adder_R[0]);
E[5] = E[4]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__adder_A1));
E[5] = __adder_R[0]||E[2]||(__adder_R[1]&&E[5]);
E[4] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__adder_A1);
if (E[4]) {
__adder_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__adder_A9\n");
#endif
}
E[6] = E[5]||E[4];
E[7] = __adder_R[1]||__adder_R[2];
__adder_R[0] = !(_true);
__adder_R[1] = E[5];
__adder_R[2] = E[4];
__adder__reset_input();
return E[6];
}

/* AUTOMATON RESET */

int adder_reset () {
__adder_R[0] = _true;
__adder_R[1] = _false;
__adder_R[2] = _false;
__adder__reset_input();
return 0;
}
