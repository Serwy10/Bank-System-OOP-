#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Myc++Libarires/clsInputValidate.h"
#include"clsFindUsers.h"
#include"clsListUsers.h"
#include"clsAddUsers.h"
#include"clsDeleteUsers.h"
#include"clsUpdateUsers.h"
using namespace std;

class clsManageUsersMenu:protected clsScreen
{
private :
	enum enManageUsers{enListU=1,enAddU=2,enDeleteU=3,enUpdateU=4,enFindU=5,enMainMenu=6};

	static  void _performManageUsersOperations(enManageUsers choice) {

		switch (choice) {
		case enListU:
			system("cls");
			_showListUsers();
			_returntoManageUsersScreen();
			break;
		case enAddU:
			system("cls");
			_showAddUsersScreen();
			_returntoManageUsersScreen();
			break;
		case enDeleteU:
			system("cls");
			_showDeleteUsersScreen();
			_returntoManageUsersScreen();
			break;
		case enUpdateU:
			system("cls");
			_showUpdateUsersScreen();
			_returntoManageUsersScreen();
			break;
		case enFindU:
			system("cls");
			_showFindUsersScreen();
			_returntoManageUsersScreen();
			break;
		case enMainMenu:
			break;
		}
	}

	static void _returntoManageUsersScreen() {
		cout << "\n\npress any key to back to manage users screen....";
		system("pause>0");
		showManageUsersMenuScreen();
	}

	static void _showListUsers() {
		//cout << "list users will be here . ";
		clsListUsers::showListUsers();
	}
	static void _showAddUsersScreen() {
		//cout << "add users will be here . ";

		clsAddUsers::showAddUsersScreen();
	}
	static void _showDeleteUsersScreen() {
		//cout << "delete users will be here . ";
		clsDeleteUsers::showDeleteUsersScreen();
	}

	static void _showUpdateUsersScreen() {
		//cout << "update users will be here . ";
		clsUpdateUsers::showUpdateUsersScreen();
	}

	static void _showFindUsersScreen() {
		//cout << "find users will be here . ";

		clsFindUsers::showFindUsersScreen();
	}
public:

	static void showManageUsersMenuScreen() {
		system("cls");
		if (!ishavePremissions(clsUser::enPremissions::pManage)) {
			return;
		}

		drawScreenHeader("Manage Users Screen");
		cout << "\t\t\t\t Manage Menu\n";
		cout << "\t\t\t\t---------------------------\n";
		cout << "\t\t\t\t [1]List All Users\n";
		cout << "\t\t\t\t [2]Add New User\n";
		cout << "\t\t\t\t [3]Dlete User\n";
		cout << "\t\t\t\t [4]Update User\n";
		cout << "\t\t\t\t [5]Find User\n";
		cout << "\t\t\t\t [6]Main Menu\n";
		cout << "\t\t\t\t---------------------------\n";
		_performManageUsersOperations((enManageUsers)clsInputValidate::readIntNumberBetween(1, 6, "enter operation you want from (1-6)"));
	}

};

