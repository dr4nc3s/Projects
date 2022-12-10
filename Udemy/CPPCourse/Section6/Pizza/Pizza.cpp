/*******************************************************************************
  @file Pizza.cpp
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup Pizza 
  @{
*******************************************************************************/

// Core includes    ------------------------------------------------------------
#include <iostream>

// Module includes  ------------------------------------------------------------
#include "Pizza.h"

// Defines/Macros   ------------------------------------------------------------

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

using namespace std;

Pizza::Pizza( string name, int cost, int diameter )
{
	this->name = name;
	this->cost = cost;
	this->diameter = diameter;
	this->toppings.push_back("Cheese");
}

void Pizza::addTopping( string topping )
{
	this->toppings.push_back(topping);
	return;
}

string Pizza::getName() const
{
	return this->name;
}

int Pizza::getCost() const
{
	return this->cost;
}

void Pizza::printToppings()
{
	for ( int x = 0;x < this->toppings.size(); x++ )
	{
		cout << "\t" << this->toppings.at(x) << endl;
	}
}

/** @} Pizza.cpp */
