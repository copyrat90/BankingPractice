// NormalAccount Implementation
// ver 0.1
// Last Update 2018.11.15


#include "pch.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int accountID, char* name, int balance, double rate)
	:Account(accountID, name, balance), interestRate(rate)
{ }

void NormalAccount::Deposit(int value)
{
	balance += static_cast<int>(interestRate * balance);
	balance += value;
}


void NormalAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout << "ÀÌÀÚÀ²: " << interestRate << std::endl;
}