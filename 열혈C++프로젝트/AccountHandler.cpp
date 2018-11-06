// AccountHandler Implementation
// ver 0.4
// Last Update 2018.11.6


#include "pch.h"
#include "AccountHandler.h"


AccountHandler::AccountHandler() : accountCnt(0) {}


AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accountCnt; i++)
		delete arrAccount[i];
}


void AccountHandler::ShowMenu() const
{
	std::cout << "-----Menu------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}


void AccountHandler::MakeAccount()
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

	arrAccount[accountCnt++] = new Account(accountID, name, balance);
}


void AccountHandler::Deposit()
{
	std::cout << "[입    금]" << std::endl;
	int inputID, depositBalance;
	int i;

	std::cout << "계좌ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (arrAccount[i]->GetID() == inputID)
		{
			std::cout << "입금액: ";
			std::cin >> depositBalance;

			arrAccount[i]->Deposit(depositBalance);

			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}

	std::cout << "존재하지 않는 ID입니다." << std::endl;
	std::cout << std::endl;
}


void AccountHandler::Withdraw()
{
	std::cout << "[출    금]" << std::endl;
	int inputID, withdrawBalance;
	int i;

	std::cout << "계좌ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (arrAccount[i]->GetID() == inputID)
		{
			std::cout << "출금액: ";
			std::cin >> withdrawBalance;

			bool overdraw = !arrAccount[i]->Withdraw(withdrawBalance);
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

void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < accountCnt; i++)
	{
		arrAccount[i]->ShowAccountInfo();
		std::cout << std::endl;
	}
}