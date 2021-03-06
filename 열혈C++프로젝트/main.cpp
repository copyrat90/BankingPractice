// main.cpp
// ver 0.3
// Last updated 2018.11.6

#include "pch.h"
#include "Account.h"
#include "AccountHandler.h"

enum {MAKE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};


int main()
{
	AccountHandler accManager;
	int choice;

	while (true)
	{
		accManager.ShowMenu();

		std::cout << "선택: ";
		std::cin >> choice;

		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			accManager.MakeAccount();
			break;

		case DEPOSIT:
			accManager.Deposit();
			break;

		case WITHDRAW:
			accManager.Withdraw();
			break;

		case SHOWALL:
			accManager.ShowAllAccount();
			break;

		case EXIT:
			std::cout << "프로그램을 종료합니다." << std::endl;
			return 0;
		}

		std::cout << std::endl;
	}
}