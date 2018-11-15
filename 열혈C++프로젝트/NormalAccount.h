// NormalAccount class
// ver 0.1
// Last Update 2018.11.15


#ifndef NORMAL_ACCOUNT_H
#define NORMAL_ACCOUNT_H

#include "Account.h"

class NormalAccount : public Account
{
public:
	NormalAccount(int accountID, char* name, int balance = 0, double rate = 0);
	virtual void ShowAccountInfo() const;
	virtual void Deposit(int value);
protected:
	double interestRate;
};



#endif // NORMAL_ACCOUNT_H