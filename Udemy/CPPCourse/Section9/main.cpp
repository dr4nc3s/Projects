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
#include <fstream>

// Module includes  ------------------------------------------------------------

// Defines/Macros   ------------------------------------------------------------

#define MAX_VAL		( 100 )
#define MIN_VAL		( 0 )

#define SCORES_FILENAME		( "scores.txt" )
// Enumerations     ------------------------------------------------------------

// Structures       ------------------------------------------------------------

// Local Variables  ------------------------------------------------------------

// Func Prototypes  ------------------------------------------------------------

// Const variables  ------------------------------------------------------------

// Global variables ------------------------------------------------------------

using namespace std;

int main(void)
{
	ifstream fsScores;
	int avgScore, maxScore, minScore, score, sumScore, countScore;

	avgScore = 0;
	countScore = 0;
	sumScore = 0;
	score = 0;
	maxScore = MIN_VAL - 1;
	minScore = MAX_VAL + 1;

	fsScores.open( SCORES_FILENAME );
	while ( !fsScores.eof() )
	{
		fsScores >> score;

		if ( (score >= MIN_VAL) && (score <= MAX_VAL) )
		{
			countScore++;

			maxScore = (score > maxScore) ? score : maxScore;
			minScore = (score < minScore) ? score : minScore;
			sumScore += score;
		}
	}
	fsScores.close();

	avgScore = sumScore / countScore;

	cout << "Max: " << maxScore << endl;
	cout << "Min: " << minScore << endl;
	cout << "Avg: " << avgScore << endl;

	return 0;
}

/** @} main.cpp */
