/*******************************************************************************
  @file Pizza.h
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup Pizza 
  @{
*******************************************************************************/

#ifndef _PIZZA_H 
#define _PIZZA_H 

// Core includes    ------------------------------------------------------------
#include <string>
#include <vector>

// Module includes  ------------------------------------------------------------

// Defines/Macros   ------------------------------------------------------------

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

class Pizza 
{
	public:
		Pizza( std::string name, int cost, int diameter );

		void 					addTopping( std::string topping );
		int 					getCost() const;
		std::string		getName() const;
		void 					printToppings();

	private:
		std::string 	name;
		int 					cost;
		int 					diameter;

		std::vector<std::string> toppings;
};

#endif  //  _PIZZA_H 

/** @} Pizza.h */
