/*******************************************************************************
  @file main.cpp
  @date 
  @author 
  @brief 

  @version 1.0

  \addtogroup  
  @{
*******************************************************************************/

// Core includes    ------------------------------------------------------------
#include <iostream>
#include <iomanip>

// Module includes  ------------------------------------------------------------
#include "BankAccount/BankAccount.h"
#include "Pizza/Pizza.h"
#include "Circle/Circle.h"

// Defines/Macros   ------------------------------------------------------------

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

using namespace std;

int main(void)
{
	string sOwner;

	BankAccount testAcct( "Tester", 1000 );
	Pizza nyPizza( "Cheese", 10, 14 );
	Circle circle0(1.4);

	nyPizza.addTopping("Pepperoni");

	sOwner = testAcct.getOwner();
	cout << "Bank Account Owner: " << sOwner << endl;

	cout << nyPizza.getName() << " - $" << nyPizza.getCost() << endl;
	nyPizza.printToppings();

	cout << setprecision(2);
	cout << "Circle - radius: " << circle0.getRadius() 
			 << " circumference: " << circle0.getCircumference()
			 << " area: " << circle0.getArea() << endl;

	return 0;
}

/** @} main.cpp */
