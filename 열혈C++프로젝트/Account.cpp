// Account class Implementation
// ver 0.2
// Last Update 2018.10.15


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


bool Account::Withdraw(int value)
{
	if (value > balance)
		return false;

	balance -= value;
	return true;
}


void Account::ShowAccountInfo()
{
	std::cout << "����ID: " << accountID << std::endl;
	std::cout << "��  ��: " << name << std::endl;
	std::cout << "��  ��: " << balance << std::endl;
}