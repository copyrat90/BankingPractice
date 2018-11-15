// HighCreditAccount class
// ver 0.1
// Last Update 2018.11.15


#ifndef HIGH_CREDIT_ACCOUNT
#define HIGH_CREDIT_ACCOUNT

#include "NormalAccount.h"

enum CreditRating { A = 1, B, C };

class HighCreditAccount : public NormalAccount
{
public:
	HighCreditAccount(int accountID, char* name, int balance = 0, double rate = 0, int cr = 1);
	virtual void ShowAccountInfo() const;
	virtual void Deposit(int value);
protected:
	int creditRating;
};

#endif // HIGH_CREDIT_ACCOUNT