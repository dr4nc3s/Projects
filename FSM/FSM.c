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

// Static funcs     ------------------------------------------------------------
static FSM_StateArg getEventNextState(PFSM_EventTableEntry_t pTbl, FSM_EventArg xEvent);

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
  pStateEntryFunc pvFnEntry = NULL;
  pStateExitFunc pvFnExit = NULL;
  PFSM_EventTableEntry_t pTblEvents = NULL;
  PFSM_StateTableEntry_t pTblStates = NULL;
  FSM_StateArg xNextState = FSM_STATE_NONE;
  bool bChangeState = false;

  if (ptCtrl == NULL)
  {
    FSM_DBG("ERR - ptCtrl is NULL\n");
    return xNextState;
  }

  // Set up pointers to the tables
  pTblStates = &(ptCtrl->ptStateTbl[ptCtrl->xCurState]);
  pTblEvents = pTblStates->ptEventTable;
  ptCtrl->xLastEvent = xEvt;

  // State change can either be due to event (next state) or due to something
  // during the process func. First check if it's something in the table
  if (pTblEvents != NULL)
  {
    xNextState = getEventNextState(pTblEvents, xEvt);
    if (xNextState != FSM_STATE_NONE)
    {
      bChangeState = true;
    }
  }

  // Do state process func 
  if (bChangeState == false)
  {
    ptFnProc = pTblStates->tHandlers.pvProcFn;
    if (ptFnProc != NULL)
    {
      xNextState = ptFnProc(xEvt);
      if (xNextState != FSM_STATE_NONE)
      {
        bChangeState = true;
      }
    }
  }

  // If we're meant to move to a new state, begin the exit funcs
  if (bChangeState)
  {
    // Update the control params and call the exit func, and then entry
    pvFnExit = pTblStates->tHandlers.pvExitFn;
    if (pvFnExit != NULL)
    {
      pvFnExit();
    }

    ptCtrl->xLastState = ptCtrl->xCurState;
    ptCtrl->xCurState = FSM_STATE_NONE;

    pvFnEntry = pTblStates->tHandlers.pvEntryFn;
    if (pvFnEntry != NULL)
    {
      pvFnEntry();
    }
  }

  return;
} // FSM_ProcessEvt()

///////////////////////////////////////////////////////////////////////////////
// Private Funcs                                                            ///
///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 * findEvent
 * @brief find corresponding next state given an event
 * 
 * @param[io] pTbl    - pointer to event table
 * @param[in] xEvent  - event to search for
 * 
 * @return index of event entry in table or 0xFF if not found
 ******************************************************************************/
static FSM_StateArg getEventNextState(PFSM_EventTableEntry_t pTbl, 
                                      FSM_EventArg xEvent)
{
  FSM_StateArg nextState = FSM_STATE_NONE;
  PFSM_EventTableEntry_t ptEntry = NULL;

  if (pTbl != NULL)
  {
    ptEntry = pTbl;
    while (ptEntry->xType != FSM_EVENT_NONE)
    {
      if (ptEntry->xType == xEvent)
      {
        nextState = ptEntry->xNextState;
        break;
      }
      ptEntry++;
    }
  }

  return nextState;
}  // findEvent()


/** @} FSM.c */
