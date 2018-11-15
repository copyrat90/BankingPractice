// HighCreditAccount Implementation
// ver 0.1
// Last Update 2018.11.15


#include "pch.h"
#include "HighCreditAccount.h"

// switch-case ��� �迭�� �ſ��޺� �߰������� ����
double crBonusRate[4] = { 0, 0.07, 0.04, 0.02 };


HighCreditAccount::HighCreditAccount(int accountID, char* name, int balance, double rate, int cr)
	:NormalAccount(accountID, name, balance, rate), creditRating(cr)
{ 
	if (creditRating < A || creditRating > C)
	{
		std::cout << "Error in HighCreditAccount::HighCreditAccount() : Invalid creditRating" << std::endl
			<< "creditRating was set to default value(A) instead." << std::endl;
		creditRating = A;
	}
}


void HighCreditAccount::Deposit(int value)
{
	double finalInterestRate = interestRate;
	finalInterestRate += crBonusRate[creditRating];

	balance += static_cast<int>(finalInterestRate * balance);
	balance += value;
}


void HighCreditAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout << "������: " << interestRate << " (+" << crBonusRate[creditRating] << ")" << std::endl;
	std::cout << "�ſ���: ";
	switch (creditRating)
	{
	case A:
		std::cout << 'A';
		break;
	case B:
		std::cout << 'B';
		break;
	case C:
		std::cout << 'C';
		break;
	}
	std::cout << std::endl;
}