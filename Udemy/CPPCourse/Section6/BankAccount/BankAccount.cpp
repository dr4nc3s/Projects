
// System includes  -----------------------------------------------------------
#include <iostream>

// Local includes  -----------------------------------------------------------
#include "BankAccount.h"

// namespace usage
using namespace std;

BankAccount::BankAccount(string owner)
{
	this->owner = owner;
}

BankAccount::BankAccount(string owner, int balance)
{
	this->owner = owner;
	if (balance <= 0)
	{
		cout << "Invalid amount for balance" << endl;
	}
	else
	{
		this->balance = balance;
	}
}

void BankAccount::deposit(int amount)
{
	if (amount <= 0)
	{
		cout << "Invalid amount for deposit" << endl;
	}
	else
	{
		this->balance += amount;
	}
	return;
}

void BankAccount::withdraw(int amount)
{
	if ( (amount <= 0) || (amount > this->balance) )
	{
		cout << "Invalid amount for withdrawal" << endl;
	}
	else
	{
		this->balance -= amount;
	}
	return;
}

string BankAccount::getOwner()
{
	return this->owner;
}

int BankAccount::getBalance()
{
	return this->balance;
}