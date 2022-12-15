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
#include <stdexcept>

// Module includes  ------------------------------------------------------------
#include "WarpDriveOverheating/WarpDriveOverheating.h"

// Defines/Macros   ------------------------------------------------------------

#define WARPDRIVE_TEMP_THRESHOLD 	( 80 )

// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

typedef struct GradeLevel
{
	int floor;
	int ceiling;
	char grade;
} GradeLevel;
#define SIZE_GRADELEVEL		sizeof(GradeLevel)

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

static char getLetterGrade(int pct);
static void warpTest(int temp);

// Const variables  ------------------------------------------------------------

static const GradeLevel atGrades[] = 
{
	{ 0, 	59, 	'F' },
	{ 60, 69, 	'D' },
	{ 70, 79, 	'C' },
	{ 80, 89, 	'B' },
	{ 90, 100, 	'A' },
	{ 101, -1, 	0 },
};

static const int numGradeBrackets = sizeof(atGrades) / SIZE_GRADELEVEL;

// Global variables ------------------------------------------------------------

using namespace std;

int main(void)
{
	int pct[5] = { 12, 85, 97, -12, 66 };


	for ( int i : pct )
	{
		try
		{
			warpTest(i);
		}
		catch(const WarpDriverOverheating& err)
		{
			cerr << err.what() << endl;
		}
		
	}
	

/*
	for (int i : pct)
	{
		try 
		{
			cout << "Letter grade for " << i << "% is " << getLetterGrade(i) << endl;
		}
		catch(const out_of_range& err)
		{
			cout << err.what() << endl;
		}
	}
*/

	return 0;
}


/******************************************************************************
 * getLetterGrade
 * 
 * return char
******************************************************************************/
static char getLetterGrade(int pct)
{
	char cGrade = 'N';

	if ( (pct < 0) || (pct > 100) )
	{
		throw out_of_range("Your percent must be within 0 and 100, inclusive\n");
	}

	for (int x = 0; x < numGradeBrackets; x++)
	{
		if ( (pct >= atGrades[x].floor) && (pct <= atGrades[x].ceiling) )
		{
			cGrade = atGrades[x].grade;
		}
	}

	return cGrade;
}

/******************************************************************************
 * warpTest
 * 
 * return void
******************************************************************************/
static void warpTest(int temp)
{
	if (temp > WARPDRIVE_TEMP_THRESHOLD)
	{
		throw WarpDriverOverheating();
	}
	else
	{
		cout << "Warp drive temp: " << temp << " deg Celsius -- safe temperature" << endl;
	}

	return;
}  // warpTest


/** @} main.cpp */
