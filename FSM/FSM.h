/*******************************************************************************
  @file FSM.h
  @date
  @author David Rances
  @brief Generic FSM module

  @version 1.0

  \addtogroup FSM
  @{
*******************************************************************************/

#ifndef _FSM_H
#define _FSM_H

// Core includes    ------------------------------------------------------------
#include <stdint.h>
#include <stdbool.h>

// Module includes  ------------------------------------------------------------
#include "FSM_cfg.h"

// Defines/Macros   ------------------------------------------------------------

#define FSM_STATE_NONE  (0xFF)
#define FSM_EVENT_NONE  (0xFF)

#if defined(FSM_EVENT_ARG_U8)
typedef uint8_t FSM_EventArg;
#elif defined(FSM_EVENT_ARG_U16)
typedef uint16_t FSM_EventArg;
#elif defined(FSM_EVENT_ARG_U32)
typedef uint32_t FSM_EventArg;
#else
#error "FSM - select an event argument size"
#endif

// Surely don't need 200+ states
typedef uint8_t FSM_StateArg;

// Templates for the function handlers for a state
typedef void (*pStateEntryFunc)(void);
typedef FSM_StateArg (*pStateProcFunc)(FSM_EventArg xEvt);
typedef void (*pStateExitFunc)(void);

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

typedef struct 
{
  FSM_EventArg xType;       //< Event ID
  FSM_StateArg xNextState;  //< Next state after this event is processed
} FSM_EventTableEntry_t, *PFSM_EventTableEntry_t;

typedef struct
{
  FSM_StateArg xState;
  struct
  {
    pStateEntryFunc pvEntryFn;  //< Exec entry func when this state is entered
    pStateProcFunc  pvProcFn;   //< Exec proc func as long as current state persists
    pStateExitFunc  pvExitFn;   //< Exec exit func on leaving this state
  } tHandlers;
  FSM_EventTableEntry_t const *ptEventTable;  //< pointer to table of events this state will process
} FSM_StateTableEntry_t, *PFSM_StateTableEntry_t;

// Control structure for FSM instance
typedef struct
{
  FSM_StateArg xLastState;
  FSM_StateArg xCurState;
  FSM_StateArg xNextState;
  FSM_EventArg xLastEvent;
  FSM_StateTableEntry_t const *ptStateTbl;
} FSM_Control_t, *PFSM_Control_t;

// Local Variables  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

bool FSM_Init(PFSM_Control_t ptCtrl, FSM_StateArg xStartState);
void FSM_ProcessEvt(PFSM_Control_t ptCtrl, FSM_EventArg xEvt);

#ifdef __cplusplus
};
#endif

#endif //  _FSM_H

/** @} FSM.h */
