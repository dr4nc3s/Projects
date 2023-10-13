/*******************************************************************************
  @file ProtoRingbuf.c
  @date  13 Oct 2023
  @author David R
  @brief Minimal API to add ring buffer logic around any given memory

  @version 1.0

  \addtogroup ProtoRingbuf 
  @{
*******************************************************************************/

// Core includes    ------------------------------------------------------------

// Module includes  ------------------------------------------------------------
#include "ProtoRingbuf.h"

// Defines/Macros   ------------------------------------------------------------

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

typedef struct RingBuf_t
{
	volatile MEM_ADDR_T pt_head;	//< pointer to oldest slot to read from
	volatile MEM_ADDR_T pt_tail;	//< pointer to recently added element
	size_t cur_size;
	size_t max_size;
} RingBuf_t;

// Local Functions  ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

// Func Definitions ------------------------------------------------------------

/******************************************************************************
 * @brief Initialize a ringbuf 
 *
 * @param buf_size -- size in bytes of ringbuf
 *
 * @return pointer to ringbuf instance
 *****************************************************************************/
PRingBuf ProtoRingBuf_Init(size_t buf_size)
{
  PRingBuf ptBuf = NULL;

	if (buf_size <= MAX_BUF_LEN)
	{
		ptBuf = malloc(sizeof(RingBuf_t));
		if (ptBuf)
		{
			ptBuf->max_size = buf_size;
			ptBuf->cur_size = 0;
			ptBuf->pt_head = 1;
			ptBuf->pt_tail = 0;
			PRINGBUF_LOG_DBG("ringbuf of size %d initialized\n", buf_size);
		}
	}

	return ptBuf;
}  // ProtoRingBuf_Init()

/******************************************************************************
 * @brief Add an element to ringbuf
 *
 * @param ptBuf  -- pointer to ringbuf to add to
 * @param pvItem -- pointer to item to add
 *
 * @return pointer to ringbuf instance
 *****************************************************************************/
PRingBuf_err_t ProtoRingBuf_Enqueue(PRingBuf ptBuf, void *pvItem)
{
  PRingBuf_err_t err = PRINGBUF_ERR_ILLPARAM;
	uint32_t new_tail;

	if (ptBuf)
	{
		new_tail = (ptBuf->pt_tail == ptBuf->max_size) ? 1 : ptBuf->pt_tail + 1;

		// Copy data to new_tail slot

		if (ptBuf->cur_size < ptBuf->max_size)
		{
			ptBuf->cur_size++;
		}
		else if (ptBuf->cur_size == ptBuf->max_size)
		{
			ptBuf->pt_head = new_tail + 1;
		}

		ptBuf->pt_tail = new_tail;
		err = PRINGBUF_ERR_NONE;
		PRINGBUF_LOG_DBG("enqueue HEAD: %d TAIL: %d cur_size: %d\n", 
			    		 ptBuf->pt_head, ptBuf->pt_tail, ptBuf->cur_size);
	}

	return err;
}  // ProtoRingBuf_Enqueue()

/******************************************************************************
 * @brief Initialize a ringbuf 
 *
 * @param buf_size -- size in bytes of ringbuf
 *
 * @return pointer to ringbuf instance
 *****************************************************************************/
PRingBuf_err_t ProtoRingBuf_Dequeue(PRingBuf ptBuf, void *pvItem)
{
  PRingBuf_err_t err = PRINGBUF_ERR_ILLPARAM;

	if (ptBuf)
	{
		err = PRINGBUF_ERR_EMPTY;
		
		if (ptBuf->cur_size > 0)
		{
			// Read from HEAD
			ptBuf->pt_head++;
			ptBuf->cur_size--;
      
			if (ptBuf->pt_head > ptBuf->max_size)
			{
				ptBuf->pt_head = 1;
			}
			
			err = PRINGBUF_ERR_NONE;
			PRINGBUF_LOG_DBG("dequeue HEAD: %d TAIL: %d cur_size: %d\n", 
			    			 ptBuf->pt_head, ptBuf->pt_tail, ptBuf->cur_size);
		}
	}

	return err;
}  // ProtoRingBuf_Dequeue()

/******************************************************************************
 * @brief Reset a ringbuf (rd = wr)
 *
 * @param ptBuf  -- pointer to ringbuf to add to
 *
 * @return 
 *   PRINGBUF_ERR_ILLPARAM - ptBuf = NULL
 *****************************************************************************/
PRingBuf_err_t ProtoRingBuf_Reset(PRingBuf ptBuf)
{
  PRingBuf_err_t err = PRINGBUF_ERR_ILLPARAM;

	if (ptBuf)
	{
		ptBuf->cur_size = 0;
		ptBuf->pt_head = 1;
		ptBuf->pt_tail = 1;
		err = PRINGBUF_ERR_NONE;
		PRINGBUF_LOG_DBG("ringbuf cleared!\n");
	}

	return err;
}  // ProtoRingBuf_Reset()

/******************************************************************************
 * @brief Check if ringbuf is empty
 *
 * @param ptBuf  -- pointer to ringbuf to check
 *
 * @return true/false
 *****************************************************************************/
bool ProtoRingBuf_Empty(PRingBuf ptBuf)
{
  bool bErr = true;
	
	if (ptBuf)
	{
		bErr = ptBuf->cur_size == 0;
	}

	return bErr;
}  // ProtoRingBuf_Empty()

/******************************************************************************
 * @brief Get size of current ptBuf
 *
 * @param ptBuf  -- pointer to ringbuf to check
 *
 * @return -1 if ptBuf == NULL
 *****************************************************************************/
size_t ProtoRingBuf_Size(PRingBuf ptBuf)
{
	size_t cur_size = -1;
	if (ptBuf)
	{
		cur_size = ptBuf->cur_size;
	}
	return cur_size;
}  // ProtoRingBuf_Size()


////////////////////////////////////////////////////////////////////////////////
//  Static Functions 
////////////////////////////////////////////////////////////////////////////////



/** @} ProtoRingbuf.c */
