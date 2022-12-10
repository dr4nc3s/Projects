/*******************************************************************************
  @file Circle.cpp
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup Circle 
  @{
*******************************************************************************/

// Core includes    ------------------------------------------------------------
#include <cmath>

// Module includes  ------------------------------------------------------------
#include "Circle.h"

// Defines/Macros   ------------------------------------------------------------

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

Circle::Circle()
{
	this->radius = UNIT_CIRCLE_RAD;
}

Circle::Circle(double rad)
{
	this->radius = rad;
}

double Circle::getRadius()
{
	return this->radius;
}

void Circle::setRadius(double rad)
{
	this->radius = rad;
}

double Circle::getCircumference()
{
	return (2.0 * this->radius * M_PI);
}

double Circle::getArea()
{
	return (this->radius * this->radius * M_PI);
}

/** @} Circle.cpp */
