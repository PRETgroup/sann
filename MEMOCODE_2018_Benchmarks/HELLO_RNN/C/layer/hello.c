/* sscc : C CODE OF SORTED EQUATIONS hello - INLINE MODE */

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
#define __hello_GENERIC_TEST(TEST) return TEST;
typedef void (*__hello_APF)();
static __hello_APF *__hello_PActionArray;

#include "hello.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _getLetter_DEFINED
#ifndef getLetter
extern integer getLetter();
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _runLetterLayer1_DEFINED
#ifndef runLetterLayer1
extern void runLetterLayer1(integer ,integer ,integer ,integer);
#endif
#endif
#ifndef _runLetterLayer2_DEFINED
#ifndef runLetterLayer2
extern void runLetterLayer2();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static integer __hello_V0;
static boolean __hello_V1;
static integer __hello_V2;
static boolean __hello_V3;
static integer __hello_V4;
static boolean __hello_V5;
static integer __hello_V6;
static boolean __hello_V7;
static integer __hello_V8;
static integer __hello_V9;


/* INPUT FUNCTIONS */

void hello_I_bit1 (integer __V) {
__hello_V0 = __V;
__hello_V1 = _true;
}
void hello_I_bit2 (integer __V) {
__hello_V2 = __V;
__hello_V3 = _true;
}
void hello_I_bit3 (integer __V) {
__hello_V4 = __V;
__hello_V5 = _true;
}
void hello_I_bit4 (integer __V) {
__hello_V6 = __V;
__hello_V7 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __hello_A1 \
__hello_V1
#define __hello_A2 \
__hello_V3
#define __hello_A3 \
__hello_V5
#define __hello_A4 \
__hello_V7

/* OUTPUT ACTIONS */

#define __hello_A5 \
hello_O_letter(__hello_V8)

/* ASSIGNMENTS */

#define __hello_A6 \
__hello_V1 = _false
#define __hello_A7 \
__hello_V3 = _false
#define __hello_A8 \
__hello_V5 = _false
#define __hello_A9 \
__hello_V7 = _false
#define __hello_A10 \
__hello_V8 = getLetter()

/* PROCEDURE CALLS */

#define __hello_A11 \
runLetterLayer1(__hello_V0,__hello_V2,__hello_V4,__hello_V6)
#define __hello_A12 \
runLetterLayer2()

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __hello_A13 \

#define __hello_A14 \

#define __hello_A15 \

#define __hello_A16 \

#define __hello_A17 \

#define __hello_A18 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int hello_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __hello__reset_input () {
__hello_V1 = _false;
__hello_V3 = _false;
__hello_V5 = _false;
__hello_V7 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __hello_R[7] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int hello () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[20];
E[0] = __hello_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__hello_A1));
if (E[0]) {
__hello_A13;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A13\n");
#endif
}
E[1] = __hello_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__hello_A2));
if (E[1]) {
__hello_A14;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A14\n");
#endif
}
E[2] = __hello_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__hello_A3));
if (E[2]) {
__hello_A15;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A15\n");
#endif
}
E[3] = __hello_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__hello_A4));
if (E[3]) {
__hello_A16;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A16\n");
#endif
}
if (__hello_R[0]) {
__hello_A17;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A17\n");
#endif
}
E[4] = __hello_R[6]&&!(__hello_R[0]);
if (E[4]) {
__hello_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A12\n");
#endif
}
if (E[4]) {
__hello_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A10\n");
#endif
}
if (E[4]) {
__hello_A5;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A5\n");
#endif
}
E[5] = !(_true);
if (__hello_R[0]) {
__hello_A18;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A18\n");
#endif
}
E[6] = __hello_R[0]||E[4];
E[7] = __hello_R[1]&&!(__hello_R[0]);
E[8] = __hello_R[2]&&!(__hello_R[0]);
E[9] = E[8]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__hello_A1));
E[9] = E[7]||(__hello_R[2]&&E[9]);
E[10] = __hello_R[3]&&!(__hello_R[0]);
E[11] = E[10]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__hello_A2));
E[11] = E[7]||(__hello_R[3]&&E[11]);
E[12] = __hello_R[4]&&!(__hello_R[0]);
E[13] = E[12]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__hello_A3));
E[13] = E[7]||(__hello_R[4]&&E[13]);
E[14] = __hello_R[5]&&!(__hello_R[0]);
E[15] = E[14]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__hello_A4));
E[15] = E[7]||(__hello_R[5]&&E[15]);
E[7] = __hello_R[2]||__hello_R[3]||__hello_R[4]||__hello_R[5];
E[8] = E[8]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__hello_A1);
E[16] = (E[7]&&!(__hello_R[2]))||E[8];
E[10] = E[10]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__hello_A2);
E[17] = (E[7]&&!(__hello_R[3]))||E[10];
E[12] = E[12]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__hello_A3);
E[18] = (E[7]&&!(__hello_R[4]))||E[12];
E[14] = E[14]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__hello_A4);
E[19] = (E[7]&&!(__hello_R[5]))||E[14];
E[14] = (E[8]||E[10]||E[12]||E[14])&&E[16]&&E[17]&&E[18]&&E[19];
if (E[14]) {
__hello_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__hello_A11\n");
#endif
}
E[19] = E[6]||((E[9]||E[11]||E[13]||E[15])&&(E[16]||E[9])&&(E[17]||E[11])&&(E[18]||E[13])&&(E[19]||E[15]))||E[14];
E[7] = __hello_R[1]||__hello_R[6]||E[7];
__hello_R[0] = !(_true);
__hello_R[1] = E[6];
__hello_R[2] = E[9];
__hello_R[3] = E[11];
__hello_R[4] = E[13];
__hello_R[5] = E[15];
__hello_R[6] = E[14];
__hello__reset_input();
return E[19];
}

/* AUTOMATON RESET */

int hello_reset () {
__hello_R[0] = _true;
__hello_R[1] = _false;
__hello_R[2] = _false;
__hello_R[3] = _false;
__hello_R[4] = _false;
__hello_R[5] = _false;
__hello_R[6] = _false;
__hello__reset_input();
return 0;
}
