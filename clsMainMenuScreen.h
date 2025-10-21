#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Myc++Libarires/clsInputValidate.h"
#include"clsBankClient.h"
#include<vector>
#include"clsShowAllClients.h"
#include"clsAddNewClient.h"
#include"clsDeleteClient.h"
#include"clsFindClients.h"
#include"clsUpdateClients.h"
#include"clsTransactionsMainMenuScreen.h"
#include"clsManageUsersMenu.h"
#include"global.h"
#include"clsLoginGerister.h"

using namespace std;
class clsMainMenuScreen:protected clsScreen
{
private:
	enum enChoice{eListClients=1,eAddCClients=2,eDeleteClients=3,eUdateClients=4,eFindClients=5,eTransactions=6,eManageUsers=7,eLoginRegister=8,eLogOut=9};

	static void _performUserChoice(enChoice choice) {

		short permissions = currentUser.getPermissions();
		switch (choice) {

		case enChoice::eListClients:
			
				system("cls");
				_showAllClients();
				_returnToMainMenu();
			
			break;
		case enChoice::eAddCClients:
			
			system("cls");
			_addNewClient();
			_returnToMainMenu();
				break;
		case enChoice::eDeleteClients:
			
				system("cls");
				_deleteClients();
				_returnToMainMenu();
				
			break;
		case enChoice::eUdateClients:
		
				system("cls");
				_updateClients();
				_returnToMainMenu();
				
			break;
		case enChoice::eFindClients:
			
				system("cls");
				_findClients();
				_returnToMainMenu();
				
			break;
			 
		case enChoice::eTransactions:
			
			system("cls");
			_Transactions();
			_returnToMainMenu();
			
			break;
		case enChoice::eManageUsers:
			
			system("cls");
			_manageUsers();
			_returnToMainMenu();
				
			break;

		case enChoice::eLoginRegister:

			system("cls");
			_loginRegister();
			_returnToMainMenu();

			break;

		case enChoice::eLogOut:
			system("cls");
			_logOut();
			
		
		}

		

	}
	

	static void _showAllClients() {

		clsShowAllClients::showAllClients();

	}

	static void _addNewClient() {
		//cout << "Add New Client Screen Will Be Here\n";

		clsAddNewClient::addNewClient();
	}

	static void _deleteClients() {
		clsDeleteClient::deleteClient();
	}

	static void _updateClients() {
		clsUpdateClients::updateClient();
	}

	static void _findClients() {
		clsFindClients::findClient();
		
	}

	static void _Transactions() {
		clsTransactionsMainMenuScreen::showTransactionMainMenu();
	}

	static void _manageUsers() {
		//cout << "manage users screen will be here.\n";
		clsManageUsersMenu::showManageUsersMenuScreen();
	}

	static void _loginRegister() {
		//cout << "login register will be here.\n";
		clsLoginRegister::showGegisterLoginsScreen();
	}

	static void _logOut() {
		//cout << "Log out screen will be here . \n";

		 currentUser = clsUser::find("", "");
		
	}

	static void _returnToMainMenu() {
		cout << "\n press any key to back to main menu screen...\n";
		system("pause>0");
		showMainMenuScreen();
	}

public:
	static void showMainMenuScreen() {
		system("cls");
	        drawScreenHeader("Main Screen");
			cout << "\t\t\t\t Main Menu\n";
			cout << "\t\t\t\t---------------------------\n";
			cout << "\t\t\t\t [1]Show All Clients\n";
			cout << "\t\t\t\t [2]Add New Client\n";
			cout << "\t\t\t\t [3]Dlete Client\n";
			cout << "\t\t\t\t [4]Update Client\n";
			cout << "\t\t\t\t [5]Find client\n";
			cout << "\t\t\t\t [6]Transactions\n";
			cout << "\t\t\t\t [7]Manage Users\n";
			cout << "\t\t\t\t [8]Login Register\n";
			cout << "\t\t\t\t [9]Log Out\n";
			cout << "\t\t\t\t---------------------------\n";
			_performUserChoice((enChoice)clsInputValidate::readIntNumberBetween(1, 9, "\t\t\t\tenter what operation you want from (1-9) : "));
	}

};

