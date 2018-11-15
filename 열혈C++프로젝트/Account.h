// Account class (Entity Class)
// ver 0.5
// Last Update 2018.11.15


#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "pch.h"

class Account
{
public:
	Account(int accountID, char* name, int balance = 0);
	Account(const Account& other);

	void ShowAccountInfo() const;

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
