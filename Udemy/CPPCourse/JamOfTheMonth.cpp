#include <iostream>
#include <iomanip>

using namespace std;

typedef struct 
{
	char 		cName;
	uint8_t nFreeJams;
	float 	fMonthlyRate;
	float 	fDiscountedJamPrice;
} MonthlyPackage_t, *PMonthlyPackage;


// Package List
static const MonthlyPackage_t atPackages[] =
{
	{ 'A',	2, 	8.00, 	5.00 },
	{ 'B',	4, 	12.00, 	4.00 },
	{ 'C',	6, 	15.00, 	3.00 },
	{ 0, 		0, 	0, 	0 },
};


int main(void)
{
	PMonthlyPackage ptPkg = NULL;
	char cPkg;
	int sPurchased = 0;
	float fTotalOwed = 0;

	// Prompt 1 - what package does user have
	cout << "Please enter which Jam Package you own (A, B, C): ";
	cin >> cPkg;

	// Prompt 2 - jams purchased this month
	cout << "Please enter how many jams you pruchased this month: ";
	cin >> sPurchased;

	ptPkg = (PMonthlyPackage)&atPackages[0];
	while (ptPkg->cName != 0)
	{
		if (ptPkg->cName == cPkg)
		{
			break;
		}
		ptPkg++;
	}

	fTotalOwed += ptPkg->fMonthlyRate;
	if ( sPurchased > ptPkg->nFreeJams )
	{
		fTotalOwed += ptPkg->fDiscountedJamPrice * ( sPurchased - ptPkg->nFreeJams );
	}
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << "Your total is: $" << setprecision(2) << fTotalOwed << endl;

	return 0;
}