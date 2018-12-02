// Account class (Entity Class)
// ver 0.7
// Last Update 2018.12.2


#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "pch.h"
#include "String.h"

class Account
{
public:
	Account(int accountID, String name, int balance = 0);

	virtual void ShowAccountInfo() const;

	int GetID() const { return accountID; }

	virtual void Deposit(int value) { balance += value; }
	bool Withdraw(int value);

protected:
	int accountID;
	String name;
	int balance;
};

#endif // ACCOUNT_H
