/*******************************************************************************
  @file FSM.c
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup FSM 
  @{
*******************************************************************************/

// Core includes    ------------------------------------------------------------
#include <stddef.h>

// Module includes  ------------------------------------------------------------
#include "FSM.h"

// Defines/Macros   ------------------------------------------------------------

#if (FSM_DEBUG_ENABLE == 1)
#define FSM_DBG(...)  printf("%s line %u: ", __FILE__, __LINE__); printf(__VA_ARGS__)
#else
#define FSM_DBG(...)
#endif

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

/******************************************************************************
 * FSM_Init
 * @brief
 * 
 * @param[io] ptCtrl      - 
 * @param[in] xStartState - 
 * 
 * @return true if errors
 ******************************************************************************/
bool FSM_Init(PFSM_Control_t ptCtrl, FSM_StateArg xStartState)
{
  pStateEntryFunc pvFnEntry = NULL;
  
  if (ptCtrl == NULL)
  {
    return true;
  }

  ptCtrl->xLastState = FSM_STATE_NONE;
  ptCtrl->xLastEvent = FSM_EVENT_NONE;
  ptCtrl->xNextState = xStartState;

  pvFnEntry = ptCtrl->ptStateTbl[ptCtrl->xCurState].tHandlers.pvEntryFn;
  if (pvFnEntry != NULL)
  {
    pvFnEntry();
  }

  return false;
}  // FSM_Init()

/******************************************************************************
 * FSM_ProcessEvt
 * @brief
 * 
 * @param[io] ptCtrl - 
 * @param[in] xEvt   - 
 * 
 * @return void
 ******************************************************************************/
void FSM_ProcessEvt(PFSM_Control_t ptCtrl, FSM_EventArg xEvt)
{
  pStateProcFunc ptFnProc = NULL;
  PFSM_EventTableEntry_t pTblEvents = NULL;
  PFSM_StateTableEntry_t pTblStates = NULL;
  FSM_StateArg xNextState = FSM_STATE_NONE;

  if (ptCtrl == NULL)
  {
    FSM_DBG("ERR - ptCtrl is NULL\n");
    return xNextState;
  }

  // Set up pointers to the tables
  pTblStates = &(ptCtrl->ptStateTbl[ptCtrl->xCurState]);
  pTblEvents = pTblStates->ptEventTable;

  ptCtrl->xLastEvent = xEvt;

  ptFnProc = pTblStates->tHandlers.pvProcFn;
  if (ptFnProc != NULL)
  {
    xNextState = ptFnProc(xEvt);
  }

  return xNextState;
} // FSM_ProcessEvt()

///////////////////////////////////////////////////////////////////////////////
// Private Funcs                                                            ///
///////////////////////////////////////////////////////////////////////////////


/** @} FSM.c */
