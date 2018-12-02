// AccountHandler class (Control Class)
// ver 1.2
// Last Update 2018.12.2


#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H

#include "Account.h"
#include "AccountArray.h"

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

	BoundCheckAccountPtrArray arrAccount;
	int accountCnt;
};


#endif // ACCOUNT_HANDLER_H