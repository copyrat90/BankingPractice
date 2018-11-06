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
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. ��    ��" << std::endl;
	std::cout << "3. ��    ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}


void AccountHandler::MakeAccount()
{
	int accountID;
	char name[NAME_LEN];
	int balance;

	std::cout << "[���°���]" << std::endl;

	std::cout << "����ID: ";
	std::cin >> accountID;

	std::cout << "��  ��: ";
	std::cin >> name;

	std::cout << "�Աݾ�: ";
	std::cin >> balance;

	arrAccount[accountCnt++] = new Account(accountID, name, balance);
}


void AccountHandler::Deposit()
{
	std::cout << "[��    ��]" << std::endl;
	int inputID, depositBalance;
	int i;

	std::cout << "����ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (arrAccount[i]->GetID() == inputID)
		{
			std::cout << "�Աݾ�: ";
			std::cin >> depositBalance;

			arrAccount[i]->Deposit(depositBalance);

			std::cout << "�ԱݿϷ�" << std::endl << std::endl;
			return;
		}
	}

	std::cout << "�������� �ʴ� ID�Դϴ�." << std::endl;
	std::cout << std::endl;
}


void AccountHandler::Withdraw()
{
	std::cout << "[��    ��]" << std::endl;
	int inputID, withdrawBalance;
	int i;

	std::cout << "����ID: ";
	std::cin >> inputID;
	for (i = 0; i < accountCnt; i++)
	{
		if (arrAccount[i]->GetID() == inputID)
		{
			std::cout << "��ݾ�: ";
			std::cin >> withdrawBalance;

			bool overdraw = !arrAccount[i]->Withdraw(withdrawBalance);
			if (overdraw)
			{
				std::cout << "�ܾ� ����!" << std::endl << std::endl;
				return;
			}

			std::cout << "��ݿϷ�" << std::endl << std::endl;
			return;
		}
	}

	std::cout << "�������� �ʴ� ID�Դϴ�." << std::endl;
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