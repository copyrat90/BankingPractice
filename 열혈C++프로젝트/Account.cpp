// Account class Implementation
// ver 0.6
// Last Update 2018.12.2


#include "pch.h"
#include "Account.h"


Account::Account(int accountID, char* name, int balance)
	:accountID(accountID), balance(balance)
{
	if (balance < 0)
	{
		this->balance = 0;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, sizeof(char) * (strlen(name) + 1), name);
}


Account::Account(const Account& other)
	:accountID(other.accountID), balance(other.balance)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, sizeof(char)*(strlen(other.name) + 1), other.name);
}


Account& Account::operator =(const Account& other)
{
	delete[]name;
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, sizeof(char)*(strlen(other.name) + 1), other.name);

	accountID = other.accountID;
	balance = other.balance;
	return *this;
}


bool Account::Withdraw(int value)
{
	if (value > balance)
		return false;

	balance -= value;
	return true;
}


void Account::ShowAccountInfo() const
{
	std::cout << "°èÁÂID: " << accountID << std::endl;
	std::cout << "ÀÌ  ¸§: " << name << std::endl;
	std::cout << "ÀÜ  ¾×: " << balance << std::endl;
}