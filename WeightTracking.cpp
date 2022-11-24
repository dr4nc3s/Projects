#include <iostream>
#include <vector>
#include <string>

#define PROMPT_COUNT				( 5 )
#define MAX_STR_INPUT_LEN		( 32 )

using namespace std;


int main(void)
{
	vector<string> vecNames{};
	vector<float> vecWeight{};

	char cNameBuf[MAX_STR_INPUT_LEN] = { 0 };
	float fWeight;

	for (int i = 0; i < PROMPT_COUNT; i++)
	{
		cout << "Please enter the person's name: ";
		cin.getline(cNameBuf, MAX_STR_INPUT_LEN);
		cout << "Now please enter the person's weight: ";
		cin >> fWeight;

		vecNames.push_back( string(cNameBuf) );
		vecWeight.push_back(fWeight);
	}

	for (int x = 0; x < vecNames.size(); x++)
	{
		cout << vecNames.at(x) << " weighs " << vecWeight.at(x) << " lbs." << endl;
	}

	return 0;
}