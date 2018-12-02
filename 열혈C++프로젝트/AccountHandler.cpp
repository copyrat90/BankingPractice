// AccountHandler Implementation
// ver 0.6
// Last Update 2018.12.2


#include "pch.h"

#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


AccountHandler::AccountHandler() : accountCnt(0), arrAccount(ARR_MAX) {}


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
	int choice;

	std::cout << "[������������]" << std::endl
		<< "1. ���뿹�ݰ���    2. �ſ�ŷڰ���" << std::endl;

	while (true)
	{
		std::cout << "����: ";
		std::cin >> choice;

		if (choice == NORMAL)
		{
			MakeNormalAccount();
			break;
		}
		else if (choice == CREDIT)
		{
			MakeHighCreditAccount();
			break;
		}
	}
}


void AccountHandler::MakeNormalAccount()
{
	int accountID;
	char name[NAME_LEN];
	int balance;
	double ratioIn100;

	std::cout << "[���뿹�ݰ��� ����]" << std::endl;

	std::cout << "����ID: ";
	std::cin >> accountID;

	std::cout << "��  ��: ";
	std::cin >> name;

	std::cout << "�Աݾ�: ";
	std::cin >> balance;

	std::cout << "������: ";
	std::cin >> ratioIn100;

	arrAccount[accountCnt++] = new NormalAccount(accountID, name, balance, ratioIn100 * 0.01);
}


void AccountHandler::MakeHighCreditAccount()
{
	int accountID;
	char name[NAME_LEN];
	int balance;
	double ratioIn100;
	int rating;

	std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;

	std::cout << "����ID: ";
	std::cin >> accountID;

	std::cout << "��  ��: ";
	std::cin >> name;

	std::cout << "�Աݾ�: ";
	std::cin >> balance;

	std::cout << "������: ";
	std::cin >> ratioIn100;

	std::cout << "�ſ���(1toA, 2toB, 3toC): ";
	std::cin >> rating;

	arrAccount[accountCnt++] = new HighCreditAccount(accountID, name, balance, ratioIn100 * 0.01, rating);
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