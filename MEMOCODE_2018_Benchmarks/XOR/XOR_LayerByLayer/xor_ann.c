/* sscc : C CODE OF SORTED EQUATIONS xor_ann - INLINE MODE */

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
#define __xor_ann_GENERIC_TEST(TEST) return TEST;
typedef void (*__xor_ann_APF)();
static __xor_ann_APF *__xor_ann_PActionArray;

#include "xor_ann.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _run_XOR_ANN_l3_DEFINED
#ifndef run_XOR_ANN_l3
extern float run_XOR_ANN_l3();
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _run_XOR_ANN_l1_DEFINED
#ifndef run_XOR_ANN_l1
extern void run_XOR_ANN_l1(float ,float);
#endif
#endif
#ifndef _run_XOR_ANN_l2_DEFINED
#ifndef run_XOR_ANN_l2
extern void run_XOR_ANN_l2();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static float __xor_ann_V0;
static boolean __xor_ann_V1;
static float __xor_ann_V2;
static boolean __xor_ann_V3;
static float __xor_ann_V4;


/* INPUT FUNCTIONS */

void xor_ann_I_x1 (float __V) {
__xor_ann_V0 = __V;
__xor_ann_V1 = _true;
}
void xor_ann_I_x2 (float __V) {
__xor_ann_V2 = __V;
__xor_ann_V3 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __xor_ann_A1 \
__xor_ann_V1
#define __xor_ann_A2 \
__xor_ann_V3

/* OUTPUT ACTIONS */

#define __xor_ann_A3 \
xor_ann_O_y(__xor_ann_V4)

/* ASSIGNMENTS */

#define __xor_ann_A4 \
__xor_ann_V1 = _false
#define __xor_ann_A5 \
__xor_ann_V3 = _false
#define __xor_ann_A6 \
__xor_ann_V4 = run_XOR_ANN_l3()

/* PROCEDURE CALLS */

#define __xor_ann_A7 \
run_XOR_ANN_l1(__xor_ann_V0,__xor_ann_V2)
#define __xor_ann_A8 \
run_XOR_ANN_l2()

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __xor_ann_A9 \

#define __xor_ann_A10 \

#define __xor_ann_A11 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int xor_ann_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __xor_ann__reset_input () {
__xor_ann_V1 = _false;
__xor_ann_V3 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __xor_ann_R[4] = {_true,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int xor_ann () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[8];
E[0] = __xor_ann_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__xor_ann_A1));
if (E[0]) {
__xor_ann_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A9\n");
#endif
}
E[1] = __xor_ann_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__xor_ann_A2));
if (E[1]) {
__xor_ann_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A10\n");
#endif
}
if (__xor_ann_R[0]) {
__xor_ann_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A11\n");
#endif
}
E[2] = __xor_ann_R[2]&&!(__xor_ann_R[0]);
if (E[2]) {
__xor_ann_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A6\n");
#endif
}
if (E[2]) {
__xor_ann_A3;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A3\n");
#endif
}
E[3] = !(_true);
E[4] = (__xor_ann_R[3]&&!(__xor_ann_R[0]))||__xor_ann_R[0];
if (E[4]) {
__xor_ann_A7;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A7\n");
#endif
}
E[5] = __xor_ann_R[1]&&!(__xor_ann_R[0]);
if (E[5]) {
__xor_ann_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__xor_ann_A8\n");
#endif
}
E[6] = E[4]||E[5]||E[2];
E[7] = __xor_ann_R[1]||__xor_ann_R[2]||__xor_ann_R[3];
__xor_ann_R[0] = !(_true);
__xor_ann_R[1] = E[4];
__xor_ann_R[2] = E[5];
__xor_ann_R[3] = E[2];
__xor_ann__reset_input();
return E[6];
}

/* AUTOMATON RESET */

int xor_ann_reset () {
__xor_ann_R[0] = _true;
__xor_ann_R[1] = _false;
__xor_ann_R[2] = _false;
__xor_ann_R[3] = _false;
__xor_ann__reset_input();
return 0;
}
