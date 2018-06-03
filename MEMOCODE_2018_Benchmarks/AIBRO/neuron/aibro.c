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
#ifndef _activate3_DEFINED
#ifndef activate3
extern integer activate3(integer ,integer ,integer ,integer ,integer ,integer ,integer);
#endif
#endif
#ifndef _activate4_DEFINED
#ifndef activate4
extern integer activate4(integer ,integer ,integer ,integer ,integer ,integer ,integer ,integer);
#endif
#endif
#ifndef _activate5_DEFINED
#ifndef activate5
extern integer activate5(integer ,integer ,integer ,integer ,integer ,integer ,integer ,integer ,integer);
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _debug_DEFINED
#ifndef debug
extern void debug(integer);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __aibro_V0;
static boolean __aibro_V1;
static integer __aibro_V2;
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
static integer __aibro_V17;
static integer __aibro_V18;
static integer __aibro_V19;
static integer __aibro_V20;
static integer __aibro_V21;
static integer __aibro_V22;
static integer __aibro_V23;
static integer __aibro_V24;
static integer __aibro_V25;
static integer __aibro_V26;
static integer __aibro_V27;
static integer __aibro_V28;
static integer __aibro_V29;
static integer __aibro_V30;
static integer __aibro_V31;
static integer __aibro_V32;
static integer __aibro_V33;
static integer __aibro_V34;
static integer __aibro_V35;
static integer __aibro_V36;
static integer __aibro_V37;
static integer __aibro_V38;
static integer __aibro_V39;
static integer __aibro_V40;
static integer __aibro_V41;
static integer __aibro_V42;
static integer __aibro_V43;
static integer __aibro_V44;
static integer __aibro_V45;
static integer __aibro_V46;
static integer __aibro_V47;
static integer __aibro_V48;
static integer __aibro_V49;
static integer __aibro_V50;
static integer __aibro_V51;


/* INPUT FUNCTIONS */

void aibro_I_A () {
__aibro_V0 = _true;
}
void aibro_I_B () {
__aibro_V1 = _true;
}
void aibro_I_front1 (integer __V) {
__aibro_V2 = __V;
__aibro_V3 = _true;
}
void aibro_I_front2 (integer __V) {
__aibro_V4 = __V;
__aibro_V5 = _true;
}
void aibro_I_front3 (integer __V) {
__aibro_V6 = __V;
__aibro_V7 = _true;
}
void aibro_I_side1 (integer __V) {
__aibro_V8 = __V;
__aibro_V9 = _true;
}
void aibro_I_side2 (integer __V) {
__aibro_V10 = __V;
__aibro_V11 = _true;
}
void aibro_I_side3 (integer __V) {
__aibro_V12 = __V;
__aibro_V13 = _true;
}
void aibro_I_side4 (integer __V) {
__aibro_V14 = __V;
__aibro_V15 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __aibro_A1 \
__aibro_V0
#define __aibro_A2 \
__aibro_V1
#define __aibro_A3 \
__aibro_V3
#define __aibro_A4 \
__aibro_V5
#define __aibro_A5 \
__aibro_V7
#define __aibro_A6 \
__aibro_V9
#define __aibro_A7 \
__aibro_V11
#define __aibro_A8 \
__aibro_V13
#define __aibro_A9 \
__aibro_V15

/* OUTPUT ACTIONS */

#define __aibro_A10 \
aibro_O_outA1(__aibro_V16)
#define __aibro_A11 \
aibro_O_outA2(__aibro_V17)
#define __aibro_A12 \
aibro_O_outA3(__aibro_V18)
#define __aibro_A13 \
aibro_O_outB1(__aibro_V19)
#define __aibro_A14 \
aibro_O_outB2(__aibro_V20)
#define __aibro_A15 \
aibro_O_outC(__aibro_V21)

/* ASSIGNMENTS */

#define __aibro_A16 \
__aibro_V0 = _false
#define __aibro_A17 \
__aibro_V1 = _false
#define __aibro_A18 \
__aibro_V3 = _false
#define __aibro_A19 \
__aibro_V5 = _false
#define __aibro_A20 \
__aibro_V7 = _false
#define __aibro_A21 \
__aibro_V9 = _false
#define __aibro_A22 \
__aibro_V11 = _false
#define __aibro_A23 \
__aibro_V13 = _false
#define __aibro_A24 \
__aibro_V15 = _false
#define __aibro_A25 \
__aibro_V29 = 0
#define __aibro_A26 \
__aibro_V29 = __aibro_V29+2
#define __aibro_A27 \
__aibro_V29 = __aibro_V29+1
#define __aibro_A28 \
__aibro_V21 = __aibro_V29
#define __aibro_A29 \
__aibro_V30 = 1
#define __aibro_A30 \
__aibro_V32 = 1
#define __aibro_A31 \
__aibro_V33 = 0
#define __aibro_A32 \
__aibro_V31 = 2
#define __aibro_A33 \
__aibro_V32 = 1
#define __aibro_A34 \
__aibro_V33 = 0
#define __aibro_A35 \
__aibro_V34 = activate3(__aibro_V2, __aibro_V4, __aibro_V6, __aibro_V33, __aibro_V30, 0, __aibro_V32)
#define __aibro_A36 \
__aibro_V35 = activate3(__aibro_V2, __aibro_V4, __aibro_V6, __aibro_V33, __aibro_V30, 1, __aibro_V32)
#define __aibro_A37 \
__aibro_V36 = activate3(__aibro_V2, __aibro_V4, __aibro_V6, __aibro_V33, __aibro_V30, 2, __aibro_V32)
#define __aibro_A38 \
__aibro_V22 = activate3(__aibro_V34, __aibro_V35, __aibro_V36, __aibro_V33, __aibro_V31, 0, __aibro_V32)
#define __aibro_A39 \
__aibro_V23 = activate3(__aibro_V34, __aibro_V35, __aibro_V36, __aibro_V33, __aibro_V31, 1, __aibro_V32)
#define __aibro_A40 \
__aibro_V24 = activate3(__aibro_V34, __aibro_V35, __aibro_V36, __aibro_V33, __aibro_V31, 2, __aibro_V32)
#define __aibro_A41 \
__aibro_V37 = 1
#define __aibro_A42 \
__aibro_V39 = 1
#define __aibro_A43 \
__aibro_V40 = 1
#define __aibro_A44 \
__aibro_V38 = 2
#define __aibro_A45 \
__aibro_V39 = 1
#define __aibro_A46 \
__aibro_V40 = 1
#define __aibro_A47 \
__aibro_V41 = activate4(__aibro_V8, __aibro_V10, __aibro_V12, __aibro_V14, __aibro_V40, __aibro_V37, 0, __aibro_V39)
#define __aibro_A48 \
__aibro_V42 = activate4(__aibro_V8, __aibro_V10, __aibro_V12, __aibro_V14, __aibro_V40, __aibro_V37, 1, __aibro_V39)
#define __aibro_A49 \
__aibro_V43 = activate4(__aibro_V8, __aibro_V10, __aibro_V12, __aibro_V14, __aibro_V40, __aibro_V37, 2, __aibro_V39)
#define __aibro_A50 \
__aibro_V25 = activate3(__aibro_V41, __aibro_V42, __aibro_V43, __aibro_V40, __aibro_V38, 0, __aibro_V39)
#define __aibro_A51 \
__aibro_V26 = activate3(__aibro_V41, __aibro_V42, __aibro_V43, __aibro_V40, __aibro_V38, 1, __aibro_V39)
#define __aibro_A52 \
__aibro_V44 = 1
#define __aibro_A53 \
__aibro_V46 = 1
#define __aibro_A54 \
__aibro_V47 = 2
#define __aibro_A55 \
__aibro_V45 = 2
#define __aibro_A56 \
__aibro_V46 = 1
#define __aibro_A57 \
__aibro_V47 = 2
#define __aibro_A58 \
__aibro_V48 = activate5(__aibro_V22, __aibro_V23, __aibro_V24, __aibro_V25, __aibro_V26, __aibro_V47, __aibro_V44, 0, __aibro_V46)
#define __aibro_A59 \
__aibro_V49 = activate5(__aibro_V22, __aibro_V23, __aibro_V24, __aibro_V25, __aibro_V26, __aibro_V47, __aibro_V44, 1, __aibro_V46)
#define __aibro_A60 \
__aibro_V50 = activate5(__aibro_V22, __aibro_V23, __aibro_V24, __aibro_V25, __aibro_V26, __aibro_V47, __aibro_V44, 2, __aibro_V46)
#define __aibro_A61 \
__aibro_V51 = activate5(__aibro_V22, __aibro_V23, __aibro_V24, __aibro_V25, __aibro_V26, __aibro_V47, __aibro_V44, 3, __aibro_V46)
#define __aibro_A62 \
__aibro_V27 = activate4(__aibro_V48, __aibro_V49, __aibro_V50, __aibro_V51, __aibro_V47, __aibro_V45, 0, __aibro_V46)
#define __aibro_A63 \
__aibro_V28 = activate4(__aibro_V48, __aibro_V49, __aibro_V50, __aibro_V51, __aibro_V47, __aibro_V45, 1, __aibro_V46)

/* PROCEDURE CALLS */

/* CONDITIONS */

#define __aibro_A64 \
__aibro_V27>0
#define __aibro_A65 \
__aibro_V28>0

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __aibro_A66 \

#define __aibro_A67 \

#define __aibro_A68 \

#define __aibro_A69 \

#define __aibro_A70 \

#define __aibro_A71 \

#define __aibro_A72 \

#define __aibro_A73 \

#define __aibro_A74 \

#define __aibro_A75 \

#define __aibro_A76 \

#define __aibro_A77 \

#define __aibro_A78 \

#define __aibro_A79 \

#define __aibro_A80 \

#define __aibro_A81 \

#define __aibro_A82 \

#define __aibro_A83 \

#define __aibro_A84 \

#define __aibro_A85 \

#define __aibro_A86 \

#define __aibro_A87 \

#define __aibro_A88 \

#define __aibro_A89 \

#define __aibro_A90 \

#define __aibro_A91 \

#define __aibro_A92 \

#define __aibro_A93 \

#define __aibro_A94 \

#define __aibro_A95 \

#define __aibro_A96 \

#define __aibro_A97 \

#define __aibro_A98 \

#define __aibro_A99 \

#define __aibro_A100 \

#define __aibro_A101 \

#define __aibro_A102 \

#define __aibro_A103 \

#define __aibro_A104 \

#define __aibro_A105 \

#define __aibro_A106 \

#define __aibro_A107 \

#define __aibro_A108 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int aibro_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __aibro__reset_input () {
__aibro_V0 = _false;
__aibro_V1 = _false;
__aibro_V3 = _false;
__aibro_V5 = _false;
__aibro_V7 = _false;
__aibro_V9 = _false;
__aibro_V11 = _false;
__aibro_V13 = _false;
__aibro_V15 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __aibro_R[7] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int aibro () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[30];
E[0] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__aibro_A3));
if (E[0]) {
__aibro_A66;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A66\n");
#endif
}
E[1] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__aibro_A4));
if (E[1]) {
__aibro_A67;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A67\n");
#endif
}
E[2] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__aibro_A5));
if (E[2]) {
__aibro_A68;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A68\n");
#endif
}
E[3] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__aibro_A6));
if (E[3]) {
__aibro_A69;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A69\n");
#endif
}
E[4] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__aibro_A7));
if (E[4]) {
__aibro_A70;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A70\n");
#endif
}
E[5] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__aibro_A8));
if (E[5]) {
__aibro_A71;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A71\n");
#endif
}
E[6] = __aibro_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__aibro_A9));
if (E[6]) {
__aibro_A72;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A72\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A73;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A73\n");
#endif
}
if (!(_true)) {
__aibro_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A10\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A74;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A74\n");
#endif
}
if (!(_true)) {
__aibro_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A11\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A75;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A75\n");
#endif
}
if (!(_true)) {
__aibro_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A12\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A76;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A76\n");
#endif
}
if (!(_true)) {
__aibro_A13;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A13\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A77;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A77\n");
#endif
}
if (!(_true)) {
__aibro_A14;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A14\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A78;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A78\n");
#endif
}
E[7] = __aibro_R[6]&&!(__aibro_R[0]);
if (E[7]) {
__aibro_A55;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A55\n");
#endif
}
if (E[7]) {
__aibro_A56;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A56\n");
#endif
}
if (E[7]) {
__aibro_A57;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A57\n");
#endif
}
E[8] = __aibro_R[4]&&!(__aibro_R[0]);
if (E[8]) {
__aibro_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A32\n");
#endif
}
if (E[8]) {
__aibro_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A33\n");
#endif
}
if (E[8]) {
__aibro_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A34\n");
#endif
}
E[9] = __aibro_R[2]&&!(__aibro_R[0]);
E[10] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__aibro_A1);
if (E[10]) {
__aibro_A93;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A93\n");
#endif
}
if (E[10]) {
__aibro_A87;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A87\n");
#endif
}
if (E[10]) {
__aibro_A88;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A88\n");
#endif
}
if (E[10]) {
__aibro_A89;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A89\n");
#endif
}
if (E[10]) {
__aibro_A90;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A90\n");
#endif
}
if (E[10]) {
__aibro_A91;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A91\n");
#endif
}
if (E[10]) {
__aibro_A92;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A92\n");
#endif
}
if (E[10]) {
__aibro_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A29\n");
#endif
}
if (E[10]) {
__aibro_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A30\n");
#endif
}
if (E[10]) {
__aibro_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A31\n");
#endif
}
if (E[10]) {
__aibro_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A35\n");
#endif
}
if (E[10]) {
__aibro_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A36\n");
#endif
}
if (E[10]) {
__aibro_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A37\n");
#endif
}
if (E[8]) {
__aibro_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A38\n");
#endif
}
if (E[8]) {
__aibro_A39;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A39\n");
#endif
}
if (E[8]) {
__aibro_A40;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A40\n");
#endif
}
E[11] = __aibro_R[5]&&!(__aibro_R[0]);
if (E[11]) {
__aibro_A44;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A44\n");
#endif
}
if (E[11]) {
__aibro_A45;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A45\n");
#endif
}
if (E[11]) {
__aibro_A46;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A46\n");
#endif
}
E[12] = __aibro_R[3]&&!(__aibro_R[0]);
E[13] = E[12]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__aibro_A2);
if (E[13]) {
__aibro_A100;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A100\n");
#endif
}
if (E[13]) {
__aibro_A94;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A94\n");
#endif
}
if (E[13]) {
__aibro_A95;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A95\n");
#endif
}
if (E[13]) {
__aibro_A96;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A96\n");
#endif
}
if (E[13]) {
__aibro_A97;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A97\n");
#endif
}
if (E[13]) {
__aibro_A98;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A98\n");
#endif
}
if (E[13]) {
__aibro_A99;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A99\n");
#endif
}
if (E[13]) {
__aibro_A41;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A41\n");
#endif
}
if (E[13]) {
__aibro_A42;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A42\n");
#endif
}
if (E[13]) {
__aibro_A43;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A43\n");
#endif
}
if (E[13]) {
__aibro_A47;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A47\n");
#endif
}
if (E[13]) {
__aibro_A48;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A48\n");
#endif
}
if (E[13]) {
__aibro_A49;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A49\n");
#endif
}
if (E[11]) {
__aibro_A50;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A50\n");
#endif
}
if (E[11]) {
__aibro_A51;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A51\n");
#endif
}
E[14] = __aibro_R[2]||__aibro_R[4];
E[15] = __aibro_R[3]||__aibro_R[5];
E[16] = E[14]||E[15];
E[14] = (E[16]&&!(E[14]))||E[8];
E[15] = (E[16]&&!(E[15]))||E[11];
E[17] = (E[8]||E[11])&&E[14]&&E[15];
if (E[17]) {
__aibro_A108;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A108\n");
#endif
}
if (E[17]) {
__aibro_A101;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A101\n");
#endif
}
if (E[17]) {
__aibro_A102;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A102\n");
#endif
}
if (E[17]) {
__aibro_A103;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A103\n");
#endif
}
if (E[17]) {
__aibro_A104;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A104\n");
#endif
}
if (E[17]) {
__aibro_A105;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A105\n");
#endif
}
if (E[17]) {
__aibro_A106;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A106\n");
#endif
}
if (E[17]) {
__aibro_A107;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A107\n");
#endif
}
if (E[17]) {
__aibro_A52;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A52\n");
#endif
}
if (E[17]) {
__aibro_A53;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A53\n");
#endif
}
if (E[17]) {
__aibro_A54;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A54\n");
#endif
}
if (E[17]) {
__aibro_A58;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A58\n");
#endif
}
if (E[17]) {
__aibro_A59;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A59\n");
#endif
}
if (E[17]) {
__aibro_A60;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A60\n");
#endif
}
if (E[17]) {
__aibro_A61;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A61\n");
#endif
}
if (E[7]) {
__aibro_A62;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A62\n");
#endif
}
if (E[7]) {
__aibro_A63;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A63\n");
#endif
}
E[18] = E[7]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 64\n"),
#endif
__aibro_A64);
if (E[18]) {
__aibro_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A26\n");
#endif
}
E[19] = E[18]||(E[7]&&!(E[18]));
E[20] = E[19]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 65\n"),
#endif
__aibro_A65);
if (E[20]) {
__aibro_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A27\n");
#endif
}
E[19] = E[20]||(E[19]&&!(E[20]));
if (E[19]) {
__aibro_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A28\n");
#endif
}
if (E[19]) {
__aibro_A15;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A15\n");
#endif
}
E[21] = E[10]||E[8];
E[22] = E[10]||E[8];
E[23] = E[13]||E[11];
E[24] = E[13]||E[11];
E[25] = E[17]||E[7];
E[26] = E[17]||E[7];
E[27] = !(_true);
if (__aibro_R[0]) {
__aibro_A85;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A85\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A79;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A79\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A80;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A80\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A81;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A81\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A82;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A82\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A83;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A83\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A84;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A84\n");
#endif
}
if (__aibro_R[0]) {
__aibro_A86;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A86\n");
#endif
}
E[28] = __aibro_R[0]||E[19];
E[29] = __aibro_R[1]&&!(__aibro_R[0]);
if (E[29]) {
__aibro_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__aibro_A25\n");
#endif
}
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__aibro_A1));
__aibro_R[2] = E[29]||(__aibro_R[2]&&E[9]);
E[12] = E[12]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__aibro_A2));
__aibro_R[3] = E[29]||(__aibro_R[3]&&E[12]);
E[15] = E[28]||((__aibro_R[2]||E[10]||__aibro_R[3]||E[13])&&(E[14]||__aibro_R[2]||E[10])&&(E[15]||__aibro_R[3]||E[13]))||E[17];
E[16] = __aibro_R[1]||__aibro_R[6]||E[16];
__aibro_R[0] = !(_true);
__aibro_R[1] = E[28];
__aibro_R[4] = E[10];
__aibro_R[5] = E[13];
__aibro_R[6] = E[17];
__aibro__reset_input();
return E[15];
}

/* AUTOMATON RESET */

int aibro_reset () {
__aibro_R[0] = _true;
__aibro_R[1] = _false;
__aibro_R[2] = _false;
__aibro_R[3] = _false;
__aibro_R[4] = _false;
__aibro_R[5] = _false;
__aibro_R[6] = _false;
__aibro__reset_input();
return 0;
}
