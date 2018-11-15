// HighCreditAccount Implementation
// ver 0.1
// Last Update 2018.11.15


#include "pch.h"
#include "HighCreditAccount.h"


HighCreditAccount::HighCreditAccount(int accountID, char* name, int balance, double rate, int cr)
	:NormalAccount(accountID, name, balance, rate), creditRating(cr)
{ }


void HighCreditAccount::Deposit(int value)
{
	double finalInterestRate = interestRate;
	switch (creditRating)
	{
	case 1:
		finalInterestRate += 0.07;
		break;
	case 2:
		finalInterestRate += 0.04;
		break;
	case 3:
		finalInterestRate += 0.02;
		break;
	default:
		std::cout << "ERROR in HighCreditAccount::Deposit() : Invalid creditRating" << std::endl;
		return;
	}

	balance += static_cast<int>(finalInterestRate * balance);
	balance += value;
}