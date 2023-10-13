/*******************************************************************************
  @file ProtoRingbuf.h
  @date 13 Oct 2023
  @author David R
  @brief Minimal API to add ring buffer logic around any given memory

  @version 1.0

  \addtogroup ProtoRingbuf 
  @{
*******************************************************************************/

#ifndef _PROTORINGBUF_H 
#define _PROTORINGBUF_H 

// Core includes    ------------------------------------------------------------
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// Module includes  ------------------------------------------------------------

// Defines/Macros   ------------------------------------------------------------

/// Maximum len for ringbufs - modify according to needs
#define MAX_BUF_LEN 200

#define MEM_ADDR_T  uint32_t

typedef struct RingBuf_t* PRingBuf;

/// Debugging 
#define PROTO_RINGBUF_ENABLE_LOG_DBG  (1)
#define PROTO_RINGBUF_ENABLE_LOG_ERR  (1)

#if (PROTO_RINGBUF_ENABLE_LOG_DBG == 1)
#define PRINGBUF_LOG_DBG(...) \
  printf("proto_ringbuf :: %u DBG -- ", __LINE__); \
  printf(__VA_ARGS__)
#else
#define PRINGBUF_LOG_DBG(...) 
#endif

#if (PROTO_RINGBUF_ENABLE_LOG_ERR == 1)
#define PRINGBUF_LOG_ERR(...) printf(__VA_ARGS__) \
  printf("proto_ringbuf :: %u ERR -- ", __LINE__); \
  printf(__VA_ARGS__)
#else
#define PRINGBUF_LOG_ERR(...) 
#endif

// Enumerations     ------------------------------------------------------------

typedef enum
{
  PRINGBUF_ERR_NONE = 0,
  PRINGBUF_ERR_EMPTY,
  PRINGBUF_ERR_FULL,
  PRINGBUF_ERR_ILLPARAM,
  PRINGBUF_ERR_UNKNOWN,
} PRingBuf_err_t;

// Structures       ------------------------------------------------------------

// Local Functions  ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

PRingBuf        ProtoRingBuf_Init(size_t buf_size);
PRingBuf_err_t  ProtoRingBuf_Enqueue(PRingBuf ptBuf, void *pvItem);
PRingBuf_err_t  ProtoRingBuf_Dequeue(PRingBuf ptBuf, void *pvItem);
PRingBuf_err_t  ProtoRingBuf_Reset(PRingBuf ptBuf);
bool            ProtoRingBuf_Empty(PRingBuf ptBuf);
size_t          ProtoRingBuf_Size(PRingBuf ptBuf);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif  //  _PROTORINGBUF_H 

/** @} ProtoRingbuf.h */
