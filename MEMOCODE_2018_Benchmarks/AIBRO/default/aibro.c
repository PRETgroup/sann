/* sscc : C CODE OF SORTED EQUATIONS aibro - INLINE MODE */

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
#define __aibro_GENERIC_TEST(TEST) return TEST;
typedef void (*__aibro_APF)();
static __aibro_APF *__aibro_PActionArray;

#include "aibro.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _getAction_DEFINED
#ifndef getAction
extern integer getAction();
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _processFrontSensors_DEFINED
#ifndef processFrontSensors
extern void processFrontSensors(integer ,integer ,integer);
#endif
#endif
#ifndef _processSideSensors_DEFINED
#ifndef processSideSensors
extern void processSideSensors(integer ,integer ,integer ,integer);
#endif
#endif
#ifndef _runDecision_DEFINED
#ifndef runDecision
extern void runDecision();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __aibro_V0;
static boolean __aibro_V1;
static boolean __aibro_V2;
static boolean __aibro_V3;
static integer __aibro_V4;
static boolean __aibro_V5;
static integer __aibro_V6;
static boolean __aibro_V7;
static integer __aibro_V8;
static boolean __aibro_V9;
static integer __aibro_V10;
static boolean __aibro_V11;
static integer __aibro_V12;
static boolean __aibro_V13;
static integer __aibro_V14;
static boolean __aibro_V15;
static integer __aibro_V16;
static boolean __aibro_V17;
static integer __aibro_V18;
static integer __aibro_V19;


/* INPUT FUNCTIONS */

void aibro_I_start () {
__aibro_V0 = _true;
}
void aibro_I_A () {
__aibro_V1 = _true;
}
void aibro_I_B () {
__aibro_V2 = _true;
}
void aibro_I_R () {
__aibro_V3 = _true;
}
void aibro_I_front1 (integer __V) {
__aibro_V4 = __V;
__aibro_V5 = _true;
}
void aibro_I_front2 (integer __V) {
__aibro_V6 = __V;
__aibro_V7 = _true;
}
void aibro_I_front3 (integer __V) {
__aibro_V8 = __V;
__aibro_V9 = _true;
}
void aibro_I_side1 (integer __V) {
__aibro_V10 = __V;
__aibro_V11 = _true;
}
void aibro_I_side2 (integer __V) {
__aibro_V12 = __V;
__aibro_V13 = _true;
}
void aibro_I_side3 (integer __V) {
__aibro_V14 = __V;
__aibro_V15 = _true;
}
void aibro_I_side4 (integer __V) {
__aibro_V16 = __V;
__aibro_V17 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __aibro_A1 \
__aibro_V0
#define __aibro_A2 \
__aibro_V1
#define __aibro_A3 \
__aibro_V2
#define __aibro_A4 \
__aibro_V3
#define __aibro_A5 \
__aibro_V5
#define __aibro_A6 \
__aibro_V7
#define __aibro_A7 \
__aibro_V9
#define __aibro_A8 \
__aibro_V11
#define __aibro_A9 \
__aibro_V13
#define __aibro_A10 \
__aibro_V15
#define __aibro_A11 \
__aibro_V17

/* OUTPUT ACTIONS */

#define __aibro_A12 \
aibro_O_O(__aibro_V18)

/* ASSIGNMENTS */

#define __aibro_A13 \
__aibro_V0 = _false
#define __aibro_A14 \
__aibro_V1 = _false
#define __aibro_A15 \
__aibro_V2 = _false
#define __aibro_A16 \
__aibro_V3 = _false
#define __aibro_A17 \
__aibro_V5 = _false
#define __aibro_A18 \
__aibro_V7 = _false
#define __aibro_A19 \
__aibro_V9 = _false
#define __aibro_A20 \
__aibro_V11 = _false
#define __aibro_A21 \
__aibro_V13 = _false
#define __aibro_A22 \
__aibro_V15 = _false
#define __aibro_A23 \
__aibro_V17 = _false
#define __aibro_A24 \
__aibro_V18 = getAction()

/* PROCEDURE CALLS */

#define __aibro_A25 \
processFrontSensors(__aibro_V4,__aibro_V6,__aibro_V8)
#define __aibro_A26 \
processSideSensors(__aibro_V10,__aibro_V12,__aibro_V14,__aibro_V16)
#define __aibro_A27 \
runDecision()

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __aibro_A28 \

#define __aibro_A29 \

#define __aibro_A30 \

#define __aibro_A31 \

#define __aibro_A32 \

#define __aibro_A33 \

#define __aibro_A34 \

#define __aibro_A35 \

#define __aibro_A36 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int aibro_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __aibro__reset_input () {
__aibro_V0 = _false;
__aibro_V1 = _false;
__aibro_V2 = _false;
__aibro_V3 = _false;
__aibro_V5 = _false;
__aibro_V7 = _false;
__aibro_V9 = _false;
__aibro_V11 = _false;
__aibro_V13 = _false;
__aibro_V15 = _false;
__aibro_V17 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __aibro_R[5] = {_true,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int aibro () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[18];
E[0] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__aibro_A5));
if (E[0]) {
__aibro_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A28\n");
#endif
}
E[1] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__aibro_A6));
if (E[1]) {
__aibro_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A29\n");
#endif
}
E[2] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__aibro_A7));
if (E[2]) {
__aibro_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A30\n");
#endif
}
E[3] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__aibro_A8));
if (E[3]) {
__aibro_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A31\n");
#endif
}
E[4] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__aibro_A9));
if (E[4]) {
__aibro_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A32\n");
#endif
}
E[5] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__aibro_A10));
if (E[5]) {
__aibro_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A33\n");
#endif
}
E[6] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 11\n"),
#endif
__aibro_A11));
if (E[6]) {
__aibro_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A34\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A35\n");
#endif
}
E[7] = __aibro_R[2]||__aibro_R[3];
E[8] = (__aibro_R[1]||__aibro_R[4]||E[7])&&!(__aibro_R[0]);
E[9] = E[8]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__aibro_A4));
E[10] = __aibro_R[2]&&E[9];
E[11] = E[10]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__aibro_A2);
E[12] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__aibro_A5)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__aibro_A6)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__aibro_A7);
E[13] = E[11]&&E[12];
if (E[13]) {
__aibro_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A25\n");
#endif
}
E[12] = E[11]&&!(E[12]);
E[11] = __aibro_R[3]&&E[9];
E[14] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__aibro_A3);
E[15] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__aibro_A8)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__aibro_A9)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__aibro_A10)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 11\n"),
#endif
__aibro_A11);
E[16] = E[14]&&E[15];
if (E[16]) {
__aibro_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A26\n");
#endif
}
E[15] = E[14]&&!(E[15]);
E[14] = (E[7]&&!(__aibro_R[2]))||E[13]||E[12];
E[7] = (E[7]&&!(__aibro_R[3]))||E[16]||E[15];
E[15] = (E[13]||E[12]||E[16]||E[15])&&E[14]&&E[7];
if (E[15]) {
__aibro_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A27\n");
#endif
}
if (E[15]) {
__aibro_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A24\n");
#endif
}
if (E[15]) {
__aibro_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A12\n");
#endif
}
E[12] = !(_true);
if (__aibro_R[0]) {
__aibro_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A36\n");
#endif
}
E[8] = E[8]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__aibro_A4);
E[8] = __aibro_R[0]||E[8];
E[17] = __aibro_R[1]&&E[9];
E[10] = E[10]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__aibro_A2));
__aibro_R[2] = E[17]||(__aibro_R[2]&&E[10]);
E[11] = E[11]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__aibro_A3));
__aibro_R[3] = E[17]||(__aibro_R[3]&&E[11]);
__aibro_R[4] = E[15]||(__aibro_R[4]&&E[9]);
E[7] = E[8]||((__aibro_R[2]||__aibro_R[3])&&(E[14]||__aibro_R[2])&&(E[7]||__aibro_R[3]))||__aibro_R[4];
__aibro_R[0] = !(_true);
__aibro_R[1] = E[8];
__aibro__reset_input();
return E[7];
}

/* AUTOMATON RESET */

int aibro_reset () {
__aibro_R[0] = _true;
__aibro_R[1] = _false;
__aibro_R[2] = _false;
__aibro_R[3] = _false;
__aibro_R[4] = _false;
__aibro__reset_input();
return 0;
}
