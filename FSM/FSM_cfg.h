/*******************************************************************************
  @file FSM_cfg.h
  @date 
  @author David Rances
  @brief Generic FSM module - header file for modifying the FSM module according
         the target application

  @version 1.0

  \addtogroup FSM 
  @{
*******************************************************************************/

#ifndef _FSM_CFG_H 
#define _FSM_CFG_H 

// Core includes    ------------------------------------------------------------
#include <stdint.h>
#include <stdbool.h>

// Module includes  ------------------------------------------------------------

// Defines/Macros   ------------------------------------------------------------

// Choose one of the following sizes for the FSM event type
#define FSM_EVENT_ARG_U8
// #define FSM_EVENT_ARG_U16
// #define FSM_EVENT_ARG_U32

// Helper macros for FSM event table entries
#define DEF_FSM_EVENT_ENTRY(_eventID, _nxtState) \
  { \
    .xType = _eventID, \
    .xNextState = _nxtState \
  }

#define DEF_FSM_EVENT_END() \
  { \
    .xType = 0xFF, \
    .xNextState = 0xFF \
  }

// Helper macro for FSM state table entries
#define DEF_FSM_STATE_TBL_ENTRY(_state, _entry, _proc, _exit, _eventTbl) \
{ \
  .xState = _state, \
  .tHandlers.pvEntryFn = _entry, \
  .tHandlers.pvProcFn = _proc, \
  .tHandlers.pvExitFn = _exit, \
  .ptEventTable = _eventTbl \
}

// Debug macros
#define FSM_DEBUG_ENABLE (0)

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------


#endif  //  _FSM_CFG_H 

/** @} FSM.h */
