

#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H

#include <string>

class BankAccount
{
	public:
		BankAccount(std::string owner);
		BankAccount(std::string owner, int balance);

		void deposit(int amount);
		void withdraw(int amount);
		std::string getOwner();
		int getBalance();

	private:
		std::string 	owner;
		int						balance;
};

#endif  // _BANKACCOUNT_H