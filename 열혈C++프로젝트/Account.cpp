// Account class Implementation
// ver 0.7
// Last Update 2018.12.2


#include "pch.h"
#include "Account.h"


Account::Account(int accountID, String name, int balance)
	:accountID(accountID), balance(balance), name(name)
{
	if (balance < 0)
	{
		this->balance = 0;
	}
}


bool Account::Withdraw(int value)
{
	if (value > balance)
		return false;

	balance -= value;
	return true;
}


void Account::ShowAccountInfo() const
{
	std::cout << "°èÁÂID: " << accountID << std::endl;
	std::cout << "ÀÌ  ¸§: " << name << std::endl;
	std::cout << "ÀÜ  ¾×: " << balance << std::endl;
}