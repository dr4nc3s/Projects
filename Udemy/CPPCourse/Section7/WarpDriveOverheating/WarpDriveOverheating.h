/*******************************************************************************
  @file WarpDriveOverheating.h
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup WarpDriveOverheating 
  @{
*******************************************************************************/

#ifndef _WARPDRIVEOVERHEATING_H 
#define _WARPDRIVEOVERHEATING_H 

// Core includes    ------------------------------------------------------------
#include <stdexcept>

// Module includes  ------------------------------------------------------------

// Defines/Macros   ------------------------------------------------------------

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

// Classes          ------------------------------------------------------------

class WarpDriverOverheating : public std::overflow_error
{
	public:
		WarpDriverOverheating() : std::overflow_error("Warp drive has exceeded safe temperature tolerance") { }
		
	private:


};

#endif  //  _WARPDRIVEOVERHEATING_H 

/** @} WarpDriveOverheating.h */
