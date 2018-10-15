// main.cpp
// ver 0.2
// Last updated 2018.10.15

#include "pch.h"

void ShowMenu();
void MakeAccount(Account **ppAccount, int &accountCnt);
void Deposit(Account **ppAccount, int accountCnt);
void Withdraw(Account **ppAccount, int accountCnt);
void ShowAllAccount(Account **ppAccount, int accountCnt);

enum {MAKE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};


int main()
{
	Account *ppAccount[ARR_MAX];
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
			MakeAccount(ppAccount, accountCnt);
			break;

		case DEPOSIT:
			Deposit(ppAccount, accountCnt);
			break;

		case WITHDRAW:
			Withdraw(ppAccount, accountCnt);
			break;

		case SHOWALL:
			ShowAllAccount(ppAccount, accountCnt);
			break;

		case EXIT:
			for (int i = 0; i < accountCnt; i++)
				delete ppAccount[i];
			std::cout << "프로그램을 종료합니다." << std::endl;
			return 0;
		}

		std::cout << std::endl;
	}
}



void ShowMenu()
{
	std::cout << "-----Menu------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}


void MakeAccount(Account **ppAccount, int &accountCnt)
{
	int accountID;
	char name[NAME_LEN];
	int balance;

	std::cout << "[계좌개설]" << std::endl;

	std::cout << "계좌ID: ";
	std::cin >> accountID;

	std::cout << "이  름: ";
	std::cin >> name;

	std::cout << "입금액: ";
	std::cin >> balance;

	ppAccount[accountCnt] = new Account(accountID, name, balance);

	accountCnt++;
}


void Deposit(Account **ppAccount, int accountCnt)
{
	std::cout << "[입    금]" << std::endl;
	int inputID, depositBalance;
	int i;

	std::cout << "계좌ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (ppAccount[i]->GetID() == inputID)
		{
			std::cout << "입금액: ";
			std::cin >> depositBalance;

			ppAccount[i]->Deposit(depositBalance);

			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}

	std::cout << "존재하지 않는 ID입니다." << std::endl;
	std::cout << std::endl;
}


void Withdraw(Account **ppAccount, int accountCnt)
{
	std::cout << "[출    금]" << std::endl;
	int inputID, withdrawBalance;
	int i;

	std::cout << "계좌ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (ppAccount[i]->GetID() == inputID)
		{
			std::cout << "출금액: ";
			std::cin >> withdrawBalance;

			bool overdraw = !ppAccount[i]->Withdraw(withdrawBalance);
			if (overdraw)
			{
				std::cout << "잔액 부족!" << std::endl << std::endl;
				return;
			}

			std::cout << "출금완료" << std::endl << std::endl;
			return;
		}
	}

	std::cout << "존재하지 않는 ID입니다." << std::endl;
	std::cout << std::endl;
}

void ShowAllAccount(Account **ppAccount, int accountCnt)
{
	for (int i = 0; i < accountCnt; i++)
	{
		ppAccount[i]->ShowAccountInfo();
		std::cout << std::endl;
	}
}