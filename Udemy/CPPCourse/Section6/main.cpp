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

// Module includes  ------------------------------------------------------------
#include "BankAccount/BankAccount.h"
#include "Pizza/Pizza.h"

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
	nyPizza.addTopping("Pepperoni");

	sOwner = testAcct.getOwner();
	cout << "Bank Account Owner: " << sOwner << endl;

	cout << nyPizza.getName() << " - $" << nyPizza.getCost() << endl;
	nyPizza.printToppings();

	return 0;
}

/** @} main.cpp */
