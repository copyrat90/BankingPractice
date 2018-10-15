// main.cpp
// ver 0.1
// Last updated 2018.10.15

#include "pch.h"
#include <string>

#define ARR_MAX 100

typedef struct __Acount
{
	int accountID;
	std::string name;
	int balance;
} Account;


void ShowMenu()
{
	std::cout << "-----Menu------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

enum {MAKE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};


void MakeAccount(Account *pAccount, int *accountCnt)
{
	std::cout << "[계좌개설]" << std::endl;

	std::cout << "계좌ID: ";
	std::cin >> pAccount[*accountCnt].accountID;

	std::cout << "이  름: ";
	std::cin >> pAccount[*accountCnt].name;

	std::cout << "입금액: ";
	std::cin >> pAccount[*accountCnt].balance;

	(*accountCnt)++;
}


void Deposit(Account *pAccount, int accountCnt)
{
	std::cout << "[입    금]" << std::endl;
	int inputID, depositBalance;
	int i;

	std::cout << "계좌ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (pAccount[i].accountID == inputID)
		{
			std::cout << "입금액: ";
			std::cin >> depositBalance;

			pAccount[i].balance += depositBalance;

			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}
	
	std::cout << "존재하지 않는 ID입니다." << std::endl;
	std::cout << std::endl;
}


void Withdraw(Account *pAccount, int accountCnt)
{
	std::cout << "[출    금]" << std::endl;
	int inputID, withdrawBalance;
	int i;

	std::cout << "계좌ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (pAccount[i].accountID == inputID)
		{
			std::cout << "출금액: ";
			std::cin >> withdrawBalance;

			if (withdrawBalance > pAccount[i].balance)
			{
				std::cout << "잔액 부족!" << std::endl << std::endl;
				return;
			}

			pAccount[i].balance -= withdrawBalance;

			std::cout << "출금완료" << std::endl << std::endl;
			return;
		}
	}

	std::cout << "존재하지 않는 ID입니다." << std::endl;
	std::cout << std::endl;
}

void ShowAllAccount(Account *pAccount, int accountCnt)
{
	for (int i = 0; i < accountCnt; i++)
	{
		std::cout << "계좌ID: " << pAccount[i].accountID << std::endl;
		std::cout << "이  름: " << pAccount[i].name << std::endl;
		std::cout << "잔  액: " << pAccount[i].balance << std::endl;
		std::cout << std::endl;
	}
}


int main()
{
	Account aAccount[ARR_MAX];
	int accountCnt = 0;

	int choice;

	while (true)
	{
		ShowMenu();

		std::cout << "선택: ";
		std::cin >> choice;

		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount(aAccount, &accountCnt);
			break;

		case DEPOSIT:
			Deposit(aAccount, accountCnt);
			break;

		case WITHDRAW:
			Withdraw(aAccount, accountCnt);
			break;

		case SHOWALL:
			ShowAllAccount(aAccount, accountCnt);
			break;

		case EXIT:
			std::cout << "프로그램을 종료합니다." << std::endl;
			return 0;
		}
	}
}