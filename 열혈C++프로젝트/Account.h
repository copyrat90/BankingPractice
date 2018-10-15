// Account class
// ver 0.3
// Last Update 2018.10.15


#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "pch.h"

class Account
{
public:
	Account(int accountID, char* name, int balance = 0);
	Account(const Account& other);

	void ShowAccountInfo();

	int GetID() const { return accountID; }

	void Deposit(int value) { balance += value; }
	bool Withdraw(int value);

	~Account() { delete[] name;	}

private:
	int accountID;
	char *name;
	int balance;
};

#endif // ACCOUNT_H
