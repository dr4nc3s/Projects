#include <iostream>

#define TEST_ARRAY_LEN 	( 10 )

int testArray[TEST_ARRAY_LEN] = { 0 };

int multiply(int x, int y, int z);
int sumArray(int *pArr, int arrLen);

using namespace std;

int main(void)
{
	int a, b, c;
	
	// Set up the test array
	for (int i = 0; i < TEST_ARRAY_LEN; i++)
	{
		testArray[i] = (rand() * rand()) % 10;
	}

	cout << "Please enter your 3 numbers with an ENTER between each number." << endl;
	cin >> a;
	cin >> b;
	cin >> c;

	cout << "Result: " << multiply(a, b, c) << endl;

	cout << "Next is sumArray assignment. The array input, and then result, will be printed out." << endl;

	for (int i = 0; i < TEST_ARRAY_LEN; i++)
	{
		cout << testArray[i] << ", ";
	}	
	cout << endl << "Sum: " << sumArray(testArray, TEST_ARRAY_LEN) << endl;

	return 0;
}

int multiply(int x, int y, int z)
{
	return (x * y * z);
}

int sumArray(int *pArr, int arrLen)
{
	int sumArr = 0;

	for (int x = 0; x < arrLen; x++)
	{
		sumArr += pArr[x];
	}

	return sumArr;
}