#pragma once
#include<iostream>
#include"clsUser.h"
#include"global.h"
#include"Myc++Libarires/clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void drawScreenHeader(string title, string subTitle = "") {

		cout << "\t\t\t\t------------------------------------------\n";
		cout <<"\t\t\t\t                 "<< title<<endl;
		

		if (subTitle != "") {
		cout << "\t\t\t\t                " << subTitle << endl;
			
		}
		cout << "\n\t\t\t\t------------------------------------------\n";
		
		cout << "\t\t\t\t  User : " << currentUser.getUserName()<<endl;
		cout << "\t\t\t\t  Date : ";
		clsDate::makeDate(clsDate());
		cout << endl;
	}

	static bool ishavePremissions(clsUser::enPremissions premission) {

		if (!currentUser.clsUser::checkApplyPremissions(premission)) {
			cout << "\t\t\t\t------------------------------------------------------------------\n";
			cout << "\t\t\t\t                 " << "Access Denied, Contact your Admin ." << endl;
			cout << "\t\t\t\t-----------------------------------------------------------------\n";
			return false;
		}
		else
			return true;

	}
};

