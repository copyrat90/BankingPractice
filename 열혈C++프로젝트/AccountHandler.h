// AccountHandler class (Control Class)
// ver 1.0
// Last Update 2018.11.6


#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H

#include "Account.h"

class AccountHandler
{
public:
	AccountHandler();
	~AccountHandler();

	void ShowMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccount() const;

private:
	Account *arrAccount[ARR_MAX];
	int accountCnt;
};


#endif // ACCOUNT_HANDLER_H