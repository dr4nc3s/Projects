/*******************************************************************************
  @file Circle.h
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup Circle 
  @{
*******************************************************************************/

#ifndef _CIRCLE_H 
#define _CIRCLE_H 

// Core includes    ------------------------------------------------------------

// Module includes  ------------------------------------------------------------

// Defines/Macros   ------------------------------------------------------------

#define UNIT_CIRCLE_RAD		( 1.0 )

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------


class Circle
{
	public:
		Circle();
		Circle(double rad);
		double 		getRadius();
		void 			setRadius(double rad);
		double 		getCircumference();
		double 		getArea();

	private:
		double radius;
};

#endif  //  _CIRCLE_H 

/** @} Circle.h */
