// Account class (Entity Class)
// ver 0.6
// Last Update 2018.12.2


#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "pch.h"

class Account
{
public:
	Account(int accountID, char* name, int balance = 0);
	Account(const Account& other);
	Account& operator =(const Account& other);

	virtual void ShowAccountInfo() const;

	int GetID() const { return accountID; }

	virtual void Deposit(int value) { balance += value; }
	bool Withdraw(int value);

	virtual ~Account() { delete[] name;	}

protected:
	int accountID;
	char *name;
	int balance;
};

#endif // ACCOUNT_H
