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
#ifndef _runFrontSensorsLayer1_DEFINED
#ifndef runFrontSensorsLayer1
extern void runFrontSensorsLayer1(integer ,integer ,integer);
#endif
#endif
#ifndef _runFrontSensorsLayer2_DEFINED
#ifndef runFrontSensorsLayer2
extern void runFrontSensorsLayer2();
#endif
#endif
#ifndef _runSideSensorsLayer1_DEFINED
#ifndef runSideSensorsLayer1
extern void runSideSensorsLayer1(integer ,integer ,integer ,integer);
#endif
#endif
#ifndef _runSideSensorsLayer2_DEFINED
#ifndef runSideSensorsLayer2
extern void runSideSensorsLayer2();
#endif
#endif
#ifndef _runDecisionLayer1_DEFINED
#ifndef runDecisionLayer1
extern void runDecisionLayer1();
#endif
#endif
#ifndef _runDecisionLayer2_DEFINED
#ifndef runDecisionLayer2
extern void runDecisionLayer2();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __aibro_V0;
static boolean __aibro_V1;
static boolean __aibro_V2;
static integer __aibro_V3;
static boolean __aibro_V4;
static integer __aibro_V5;
static boolean __aibro_V6;
static integer __aibro_V7;
static boolean __aibro_V8;
static integer __aibro_V9;
static boolean __aibro_V10;
static integer __aibro_V11;
static boolean __aibro_V12;
static integer __aibro_V13;
static boolean __aibro_V14;
static integer __aibro_V15;
static boolean __aibro_V16;
static integer __aibro_V17;
static integer __aibro_V18;


/* INPUT FUNCTIONS */

void aibro_I_A () {
__aibro_V0 = _true;
}
void aibro_I_B () {
__aibro_V1 = _true;
}
void aibro_I_R () {
__aibro_V2 = _true;
}
void aibro_I_front1 (integer __V) {
__aibro_V3 = __V;
__aibro_V4 = _true;
}
void aibro_I_front2 (integer __V) {
__aibro_V5 = __V;
__aibro_V6 = _true;
}
void aibro_I_front3 (integer __V) {
__aibro_V7 = __V;
__aibro_V8 = _true;
}
void aibro_I_side1 (integer __V) {
__aibro_V9 = __V;
__aibro_V10 = _true;
}
void aibro_I_side2 (integer __V) {
__aibro_V11 = __V;
__aibro_V12 = _true;
}
void aibro_I_side3 (integer __V) {
__aibro_V13 = __V;
__aibro_V14 = _true;
}
void aibro_I_side4 (integer __V) {
__aibro_V15 = __V;
__aibro_V16 = _true;
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
__aibro_V4
#define __aibro_A5 \
__aibro_V6
#define __aibro_A6 \
__aibro_V8
#define __aibro_A7 \
__aibro_V10
#define __aibro_A8 \
__aibro_V12
#define __aibro_A9 \
__aibro_V14
#define __aibro_A10 \
__aibro_V16

/* OUTPUT ACTIONS */

#define __aibro_A11 \
aibro_O_O(__aibro_V17)

/* ASSIGNMENTS */

#define __aibro_A12 \
__aibro_V0 = _false
#define __aibro_A13 \
__aibro_V1 = _false
#define __aibro_A14 \
__aibro_V2 = _false
#define __aibro_A15 \
__aibro_V4 = _false
#define __aibro_A16 \
__aibro_V6 = _false
#define __aibro_A17 \
__aibro_V8 = _false
#define __aibro_A18 \
__aibro_V10 = _false
#define __aibro_A19 \
__aibro_V12 = _false
#define __aibro_A20 \
__aibro_V14 = _false
#define __aibro_A21 \
__aibro_V16 = _false
#define __aibro_A22 \
__aibro_V18 = getAction()
#define __aibro_A23 \
__aibro_V17 = __aibro_V18

/* PROCEDURE CALLS */

#define __aibro_A24 \
runFrontSensorsLayer1(__aibro_V3,__aibro_V5,__aibro_V7)
#define __aibro_A25 \
runFrontSensorsLayer2()
#define __aibro_A26 \
runSideSensorsLayer1(__aibro_V9,__aibro_V11,__aibro_V13,__aibro_V15)
#define __aibro_A27 \
runSideSensorsLayer2()
#define __aibro_A28 \
runDecisionLayer1()
#define __aibro_A29 \
runDecisionLayer2()

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __aibro_A30 \

#define __aibro_A31 \

#define __aibro_A32 \

#define __aibro_A33 \

#define __aibro_A34 \

#define __aibro_A35 \

#define __aibro_A36 \

#define __aibro_A37 \

#define __aibro_A38 \


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
__aibro_V4 = _false;
__aibro_V6 = _false;
__aibro_V8 = _false;
__aibro_V10 = _false;
__aibro_V12 = _false;
__aibro_V14 = _false;
__aibro_V16 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __aibro_R[10] = {_false,
 _false,
 _true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int aibro () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[22];
E[0] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__aibro_A4));
if (E[0]) {
__aibro_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A30\n");
#endif
}
E[1] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__aibro_A5));
if (E[1]) {
__aibro_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A31\n");
#endif
}
E[2] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__aibro_A6));
if (E[2]) {
__aibro_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A32\n");
#endif
}
E[3] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__aibro_A7));
if (E[3]) {
__aibro_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A33\n");
#endif
}
E[4] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__aibro_A8));
if (E[4]) {
__aibro_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A34\n");
#endif
}
E[5] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__aibro_A9));
if (E[5]) {
__aibro_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A35\n");
#endif
}
E[6] = __aibro_R[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__aibro_A10));
if (E[6]) {
__aibro_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A36\n");
#endif
}
if (__aibro_R[2]) {
__aibro_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A37\n");
#endif
}
E[7] = __aibro_R[4]||__aibro_R[5]||__aibro_R[6]||__aibro_R[7];
E[8] = (__aibro_R[3]||__aibro_R[8]||__aibro_R[9]||E[7])&&!(__aibro_R[2]);
E[9] = E[8]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__aibro_A3));
E[10] = __aibro_R[8]&&E[9];
if (E[10]) {
__aibro_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A29\n");
#endif
}
if (E[10]) {
__aibro_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A22\n");
#endif
}
if (E[10]) {
__aibro_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A23\n");
#endif
}
if (E[10]) {
__aibro_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A11\n");
#endif
}
E[11] = __aibro_R[4]&&E[9];
E[12] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__aibro_A1);
if (E[12]) {
__aibro_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A24\n");
#endif
}
E[8] = E[8]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__aibro_A3);
E[13] = __aibro_R[3]&&E[9];
E[11] = E[11]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__aibro_A1));
E[11] = E[13]||(__aibro_R[4]&&E[11]);
E[14] = __aibro_R[5]&&E[9];
E[15] = E[13]||(__aibro_R[5]&&E[14]&&!(__aibro_R[0]));
E[16] = __aibro_R[6]&&E[9];
E[17] = E[16]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__aibro_A2));
E[17] = E[13]||(__aibro_R[6]&&E[17]);
E[18] = __aibro_R[7]&&E[9];
E[13] = E[13]||(__aibro_R[7]&&E[18]&&!(__aibro_R[1]));
E[19] = (E[7]&&!(__aibro_R[4]))||E[12];
E[14] = E[14]&&__aibro_R[0];
if (E[14]) {
__aibro_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A25\n");
#endif
}
E[20] = (E[7]&&!(__aibro_R[5]))||E[14];
E[16] = E[16]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__aibro_A2);
if (E[16]) {
__aibro_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A26\n");
#endif
}
E[21] = (E[7]&&!(__aibro_R[6]))||E[16];
E[18] = E[18]&&__aibro_R[1];
if (E[18]) {
__aibro_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A27\n");
#endif
}
E[7] = (E[7]&&!(__aibro_R[7]))||E[18];
__aibro_R[8] = (E[12]||E[14]||E[16]||E[18])&&E[19]&&E[20]&&E[21]&&E[7];
if (__aibro_R[8]) {
__aibro_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A28\n");
#endif
}
__aibro_R[9] = E[10]||(__aibro_R[9]&&E[9]);
E[7] = E[8]||((E[11]||E[15]||E[17]||E[13])&&(E[19]||E[11])&&(E[20]||E[15])&&(E[21]||E[17])&&(E[7]||E[13]))||__aibro_R[8]||__aibro_R[9];
__aibro_R[0] = E[12]&&E[7];
__aibro_R[1] = E[16]&&E[7];
E[21] = !(_true);
if (__aibro_R[2]) {
__aibro_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A38\n");
#endif
}
E[7] = __aibro_R[2]||E[7];
__aibro_R[3] = __aibro_R[2]||E[8];
__aibro_R[2] = !(_true);
__aibro_R[4] = E[11];
__aibro_R[5] = E[15];
__aibro_R[6] = E[17];
__aibro_R[7] = E[13];
__aibro__reset_input();
return E[7];
}

/* AUTOMATON RESET */

int aibro_reset () {
__aibro_R[0] = _false;
__aibro_R[1] = _false;
__aibro_R[2] = _true;
__aibro_R[3] = _false;
__aibro_R[4] = _false;
__aibro_R[5] = _false;
__aibro_R[6] = _false;
__aibro_R[7] = _false;
__aibro_R[8] = _false;
__aibro_R[9] = _false;
__aibro__reset_input();
return 0;
}
