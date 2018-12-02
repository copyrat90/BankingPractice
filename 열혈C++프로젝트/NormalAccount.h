// NormalAccount class
// ver 0.2
// Last Update 2018.12.2


#ifndef NORMAL_ACCOUNT_H
#define NORMAL_ACCOUNT_H

#include "Account.h"

class NormalAccount : public Account
{
public:
	NormalAccount(int accountID, String name, int balance = 0, double rate = 0);
	virtual void ShowAccountInfo() const;
	virtual void Deposit(int value);
protected:
	double interestRate;
};



#endif // NORMAL_ACCOUNT_H