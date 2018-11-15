// AccountHandler class (Control Class)
// ver 1.1
// Last Update 2018.11.15


#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H

#include "Account.h"

enum AccountType { NORMAL = 1, CREDIT = 2 };

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
	void MakeNormalAccount();
	void MakeHighCreditAccount();

	Account *arrAccount[ARR_MAX];
	int accountCnt;
};


#endif // ACCOUNT_HANDLER_H