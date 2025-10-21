#pragma once
#include<iostream>
#include"Myc++Libarires/clsDate.h"
#include"Myc++Libarires/clsString.h"
#include"Myc++Libarires/clsPeriod.h"
#include"Myc++Libarires/clsUtil.h"
using namespace std;
class clsInputValidate
{
public:
	static bool isNumberBetween(int number, int from, int to) {
		return( (number >= from) && (number <= to));
	}
	static bool isNumberBetween(double number, double from, double to) {
		return((number >= from) && (number <= to));
	}
	static bool isDateBetween(clsDate date, clsDate from, clsDate to) {
		if (clsDate::isDate1AfterDate2(from, to))
			clsUtil::Swap(from, to);
		return clsPeriod::isDateInPeriod(clsPeriod(from, to), date);
	}

	static int readIntNumber(string message= "enter valid number : ") {
		int number;
		cout << message;
		cin >> number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> number;
		}
		return number;
	}

	static double readDbNumber(string message) {
		double number;
		cout << message;
		cin >> number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> number;
		}
		return number;
	}

	

	static int readIntNumberBetween(int from, int to, string message) {
		int num = readIntNumber(message);

		while (!isNumberBetween(num, from, to)) {
			num = readIntNumber(message);
		}
		return num;
	}

	static double readDbNumberInRange(double from,double to,string message) {

		double num = readIntNumber("enter valid number : ");

		while (!isNumberBetween(num, from, to)) {
			cout << message << endl;
			num = readIntNumber("enter valid number : ");
		}
		
		return num;
	}

	static bool isValidDate(clsDate date) {
		return clsDate::isValidDate(date);
	}

	static string readString() {
		string st;
		getline(cin >> ws, st);
		return st;
	}


};

