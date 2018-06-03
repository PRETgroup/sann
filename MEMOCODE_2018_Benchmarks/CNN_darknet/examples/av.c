/* sscc : C CODE OF SORTED EQUATIONS av - INLINE MODE */

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
#define __av_GENERIC_TEST(TEST) return TEST;
typedef void (*__av_APF)();
static __av_APF *__av_PActionArray;

#include "av.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef _runCNN_DEFINED
#ifndef runCNN
extern void runCNN();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __av_V0;


/* INPUT FUNCTIONS */

void av_I_scan () {
__av_V0 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __av_A1 \
__av_V0

/* OUTPUT ACTIONS */

/* ASSIGNMENTS */

#define __av_A2 \
__av_V0 = _false

/* PROCEDURE CALLS */

#define __av_A3 \
runCNN()

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int av_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __av__reset_input () {
__av_V0 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __av_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int av () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[3];
E[0] = !(_true);
E[1] = __av_R[1]&&!(__av_R[0]);
E[2] = E[1]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__av_A1);
if (E[2]) {
__av_A3;
#ifdef TRACE_ACTION
fprintf(stderr, "__av_A3\n");
#endif
}
E[1] = E[1]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__av_A1));
__av_R[1] = __av_R[0]||E[2]||(__av_R[1]&&E[1]);
E[1] = __av_R[1];
__av_R[0] = !(_true);
__av__reset_input();
return E[1];
}

/* AUTOMATON RESET */

int av_reset () {
__av_R[0] = _true;
__av_R[1] = _false;
__av__reset_input();
return 0;
}
