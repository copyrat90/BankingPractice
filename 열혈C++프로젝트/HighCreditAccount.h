// HighCreditAccount class
// ver 0.1
// Last Update 2018.11.15


#ifndef HIGH_CREDIT_ACCOUNT
#define HIGH_CREDTI_ACCOUNT

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
public:
	HighCreditAccount(int accountID, char* name, int balance = 0, double rate = 0, int cr = 1);
	virtual void Deposit(int value);
protected:
	int creditRating;
};

#endif // HIGH_CREDIT_ACCOUNT