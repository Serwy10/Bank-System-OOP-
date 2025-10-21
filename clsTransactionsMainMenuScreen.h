#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Myc++Libarires/clsInputValidate.h"
#include"clsBankClient.h"
#include"clsDepositAccounts.h"
#include"clsWithdrawAccounts.h"
#include"clsTotalBalances.h"
#include"clsTransfer.h"
#include"clsTransferLogs.h"
using namespace std;
class clsTransactionsMainMenuScreen :protected clsScreen
{
private:
	enum _enTransactions { deposite = 1, withDraw = 2, TotalBalances = 3,Transfer=4,transferLog=5 ,MainMenu = 6};

	static void _performTransactionsOperations(_enTransactions choice) {

		switch (choice) {

		case _enTransactions::deposite:
			system("cls");
			_showDepositeScreen();
			_returntoTransactionMainMenu();
			break;
		case _enTransactions::withDraw:
			system("cls");
			_showWithDrawScreen();
			_returntoTransactionMainMenu();
			break;
		case _enTransactions::TotalBalances:
			system("cls");
			_showTotalBalances();
			_returntoTransactionMainMenu();
			break;

		case _enTransactions::Transfer:
			system("cls");
			_showTransferScreen();
			_returntoTransactionMainMenu();
			break;

		case _enTransactions::transferLog:
			system("cls");
			_showTransferLogScreen();
			_returntoTransactionMainMenu();
			break;
		case _enTransactions::MainMenu:
			break;
			
		}

	}

	static void _returntoTransactionMainMenu() {

		cout << "press any key to back to transactions menu \n";
		system("pause>0");
		showTransactionMainMenu();
	}

	static void _showDepositeScreen() {
		//cout << "deposite screen will be here . \n";
		clsDepositAccounts::showDepositeScreen();
	}

	static void _showWithDrawScreen() {
		//cout << "with draw screen will be here. \n";
		clsWithdrawAccounts::showWithDrawScreen();
	}

	static void _showTotalBalances() {

		//cout << "total balances screen will be here. \n";
		clsTotalBalances::showTotalBalances();
	}

	static void _BackToMainMenu() {

		//clsMainMenuScreen:: showMainMenuScreen();
		cout << "main menu screen will be here. \n";

	}

	static void _showTransferLogScreen() {
		clsTransferLogs::showTransferLogsScreen();
	}

	static void _showTransferScreen() {

		clsTransfer::showTransferScreen();
	}
public:
	static void showTransactionMainMenu() {
		system("cls");
		if (!ishavePremissions(clsUser::enPremissions::pTransactions)) {
			return;
		}

		drawScreenHeader("Transactions Main Menu");

		cout << "\t\t\t\t Transactions Main Menu\n";
		cout << "\t\t\t\t---------------------------\n";
		cout << "\t\t\t\t [1]Deposite\n";
		cout << "\t\t\t\t [2]WithDraw\n";
		cout << "\t\t\t\t [3]TotalBalances\n";
		cout << "\t\t\t\t [4]Transfer\n";
		cout << "\t\t\t\t [5]Transfer Logs\n";
		cout << "\t\t\t\t [6]MainMenu\n";
		cout << "\t\t\t\t---------------------------\n";

		_performTransactionsOperations((_enTransactions)clsInputValidate::readIntNumberBetween(1, 6, "enter operation you want (1-6) : "));

	}

};



