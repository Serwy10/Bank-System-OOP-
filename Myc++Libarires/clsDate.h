#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include"clsString.h"
class clsDate
{
private:
	int _day;
	int _month;
	int _year;
public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}
	clsDate(string date) {
		vector <string>sDate = clsString::splitString(date, "/");
		_day = stoi(sDate[0]);
		_month = stoi(sDate[1]);
		_year = stoi(sDate[2]);
	}
	clsDate(int _day, int _month, int _year) {
		this->_day = _day;
		this->_month = _month;
		this->_year = _year;
	}
	clsDate(int numOfDateInYear,int year) {

		_year = year;
		clsDate date = generatDateFromNumOfDaysInYear(numOfDateInYear,_year);
		
		_month = date._month;
		_day = date._day;
	}
	void setDay(int day) {
		_day = day;
	}
	int getDay() {
		return _day;
	}

	void setMonth(int month) {
		_month = month;
	}
	int getMonth() {
		return _month;
	}

	void setYear(int year) {
		_year = year;
	}
	int getYear() {
		return _year;
	}


	static bool isLeapYear(int year) {
		return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	}
	bool isLeapYear() {
		return isLeapYear(this->_year);
	}
	static short daysInYear(int _year) {
		return (isLeapYear(_year)) ? 366 : 365;
	}
	short daysInYear() {
		return daysInYear(this->_year);
	}

	static short daysInMonth(int month, int year) {
		short arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year)) ? 29 : 28 : arr[month - 1];
	}
	short daysInMonth() {
		return daysInMonth(this->_month, this->_year);
	}


	static clsDate generatDateFromNumOfDaysInYear(int numOfDaysinYear,int year) {
		clsDate date;
		date._day = 1;
		date._month = 1;
		date._year = year;
		
		return date = dateAfterAddDays(numOfDaysinYear, date._day, date._month, date._year);
		
	}
	clsDate generatDateFromNumOfDaysInYear(int numOfDaysinYear) {
		return generatDateFromNumOfDaysInYear(numOfDaysinYear, _year);
	}
	

	static void makeDate(clsDate date) {
		cout << date._day << "/" << date._month << "/" <<date. _year<< endl;
	}
	void makeDate() {
		makeDate(*this);
	}

	static short numOfDaysInYear(int year) {

		return (isLeapYear(year)) ? 366 : 365;
	}
	short numOfDaysInYear() {
		return numOfDaysInYear(this->_year);
	}

	static short numOfHoursInYear(int year) {
		return numOfDaysInYear(year) * 24;
	}
	short numOfHoursInYear() {
		return numOfHoursInYear(this->_year);
	}

	static int numOfMinutesInYear(int year) {
		return numOfDaysInYear(year) * 24 * 60;
	}
	int numOfMinutesInYear() {
		return numOfMinutesInYear(this->_year);
	}


	static int numOfSecondsInYear(int year) {
		return numOfDaysInYear(year) * 24 * 60 * 60;
	}
	int numOfSecondsInYear() {
		return numOfSecondsInYear(this->_year);
	}

	static int numOfDaysInMonth(int month,int year) {
		return daysInMonth(month, year);
	}
	int numOfDaysInMonth() {
		return numOfDaysInMonth(this->_month, this->_year);
	}

	static int numOfHoursInMonth(int month, int year) {
		return daysInMonth(month, year) * 24;
	}
	int numOfHoursInMonth() {
		return numOfHoursInMonth(this->_month, this->_year);
	}


	static int numOfMinutesInMonth(int month, int year) {
		return numOfDaysInMonth(month, year) * 24 * 60;
	}
	int numOfMinutesInMonth() {
		return numOfMinutesInMonth(this->_month, this->_year);
	}

	static int numOfSecondsInMonth(int month, int year) {
		return numOfDaysInMonth(month, year) * 24 * 60 * 60;
	}
	int numOfSecondsInMonth() {
		return numOfSecondsInMonth(this->_month, this->_year);
	}


	static short dayOrder(int year, short month, short day) {

		int a = ((14 - month) / 12);
		int y = year - a;
		int m = month + (12 * a) - 2;

		int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;

	}
	short dayOrder() {
		return dayOrder(this->_year, this->_month, this->_day);
	}


	static string weekDay(short dayOrder) {

		string arr[7]{"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arr[dayOrder];
	}
	static string monthName(int month) {

		string arr[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arr[month - 1];
	}


	static void printMonthCalender(int year,int month) {
		short counter = 0;
		cout << "----------------------" << monthName(month) << "--------------------------\n";
		for (int i = 0; i <= 6; i++) {
			cout << weekDay(i) << "\t";
		}
		cout << '\n';
		for (int i = 0; i <= 6; i++) {
			if (dayOrder(year, month, 1) != i) {
				cout << '\t';
				++counter;
				if (counter % 7 == 0)
					cout << '\n';
			}
			else {
				for (int i = 1; i <= daysInMonth(month, year); i++) {
					cout << i << '\t';
					++counter;
					if (counter % 7 == 0) {
						cout << '\n';
					}
				}
			}
				
		}
	}
	void printMonthCalender() {
		printMonthCalender(this->_year, this->_month);
	}


	static void printYearCalender(int year) {
		cout << "--------------------------------------\n";
		cout << "\t\tCalender " << year << "\t\t\n";
		cout << "--------------------------------------\n";
		for (int i = 1; i <= 12; i++) {
			printMonthCalender(year, i);
			cout << '\n';
		}
	}
	void printYearCalender() {
		printYearCalender(this->_year);
	}


	static short totalDaysFromBeginingOfYear(int year,int month,int day) {
		short total = 0;
		for (int i = 1; i <month; i++) {
			total += daysInMonth(i, year);
		}
		total += day;
		return total;
	}
	static clsDate dateAfterAddDays(int numOfDays,int day,int month, int year) {  //study another time
		numOfDays += totalDaysFromBeginingOfYear(year, month, day);
		clsDate date;

		date._month = 1;
		short monthDays = 0;
		date._year = year;
		while (true) {
			monthDays = daysInMonth(date._month, date._year);
			if (numOfDays > monthDays){
				numOfDays -= monthDays;
				if (date._month == 12) {
					date._month = 1;
					++date._year;
				}
				else {
					++date._month;
				}
			}
			else {
				date._day = numOfDays;
				break;
			}
		}
		
		return date;

	}

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
		return (date1._year < date2._year) ? true : (date1._year == date2._year) ? (date1._month < date2._month) ? true : (date1._month == date2._month) ?
			date1._day < date2._day : false : false;
	}
	bool  isDate1BeforeDate2(clsDate date) {
		return isDate1BeforeDate2(*this, date);
	}


	static bool isDate1EqualDate2(clsDate date1,clsDate date2) {
		return (date1._year == date2._year) && (date1._month == date2._month) && (date1._day == date2._day);
	}
	bool isDate1EqualDate2(clsDate date) {
		return isDate1EqualDate2(*this, date);
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
		return (!isDate1BeforeDate2(date1, date2)) && (!isDate1EqualDate2(date1, date2));
	}
	bool isDate1AfterDate2(clsDate date) {
		return isDate1AfterDate2(*this, date);
	}

	static bool isDayLastInMonth(int day,int month,int year) {
		return day == daysInMonth(month, year);
	}
	bool isDayLastInMonth() {
		return isDayLastInMonth(this->_day, this->_month, this->_year);
	}

	static bool isLastMonthInYear(int month) {
		return month == 12;
	}
	bool isLastMonthInYear() {
		return isLastMonthInYear(this->_month);
	}


	static clsDate increasedDateByOneDay2(clsDate &date) {

		if (isDayLastInMonth(date._day, date._month, date._year)) {
			if (isLastMonthInYear(date._month)) {
				date._day = 1;
				date._month = 1;
				++date._year;
			}
			else {
				date._day = 1;
				++date._month;
			}
		}
		else {
			++date._day;
		}
		return date;
	}
	clsDate  increasedDateByOneDay2() {
		return increasedDateByOneDay2(*this);
	}


	static clsDate increasedDateByXDays(int xDays,clsDate& date) {

		for (int i = 1; i <= xDays; i++) {
			date = increasedDateByOneDay2(date);
		}
		return date;
	}
	clsDate increasedDateByXDays(int xDays) {
		return increasedDateByXDays(xDays, *this);
	}


	static int differenceBetweenTwoDates(clsDate date1,clsDate date2) {
		int difference = 0;
		if (!isDate1BeforeDate2(date1, date2)) 
			swap(date1, date2);

			while (!isDate1EqualDate2(date1, date2)) {
				date1=increasedDateByOneDay2(date1);
				++difference;
			}
			return difference;

	}
	int differenceBetweenTwoDates(clsDate date) {
		return differenceBetweenTwoDates(*this, date);
	}

	static bool isWeekEnd(clsDate date) {
		short dayOrderInWeek = dayOrder(date._year, date._month, date._day);
		return (dayOrderInWeek == 0||dayOrderInWeek==6);
	}
	bool isWeekEnd() {
		return isWeekEnd(*this);
	}

	static bool isBusinnessDay(clsDate date) {
		return (!isWeekEnd(date));
	}
	bool isBusinnessDay() {
		return isBusinnessDay(*this);
	}

	static clsDate getSystemDate() {

		clsDate date;

		time_t t = time(0);
		tm* now = localtime(&t);
		date._day = now->tm_mday;
		date._month = now->tm_mon + 1;
		date._year = now->tm_year + 1990;
		return date;
	}


	static int yourAgeInDays(clsDate yourBirthDay) {
		return differenceBetweenTwoDates(yourBirthDay, getSystemDate());
	}

	static clsDate increaseDateByOneWeek(clsDate date) {

		return date=increasedDateByXDays(7, date);
	}
	clsDate increaseDateByOneWeek() {
		return *this=increasedDateByXDays(7);
	}


	static clsDate increaseDateByXWeeks(int xWeeks,clsDate date) {
		for (int i = 1; i <= xWeeks; i++) {
		date=increaseDateByOneWeek(date);
		}
		return date;
	}
	clsDate increaseDateByXWeeks(int xWeeks) {
		return increaseDateByXWeeks(xWeeks, *this);
	 }


	static clsDate increaseDateByOneMonth(clsDate &date) {

		if (isDayLastInMonth(date._day, date._month, date._year)){

		if (isLastMonthInYear(date._month)) {
				++date._year;
				date._month=1;
				date._day = daysInMonth(date._month, date._year);
			}
			else {
			++date._month;
			date._day = daysInMonth(date._month, date._year);

			}
		
		}
		else {
			++date._month;

		}
		return date;

	}

	clsDate increaseDateByOneMonth() {
		return increaseDateByOneMonth(*this);
	}

	static clsDate increaseDateByXMonths(int xMonths,clsDate &date) {

		for (int i = 1; i <= xMonths; i++) {
			increaseDateByOneMonth(date);
		}
		return date;
	}
	clsDate increaseDateByXMonths(int xMonths) {
		return increaseDateByXMonths(xMonths,*this);
	}

	static clsDate increaseDateByOneYear(clsDate &date) {

		++date._year;
		if (date._month == 2)
		{
			if (date._day == 29) {
				date._day = daysInMonth(date._month, date._year);
			}
		}
		return date;
	}

	clsDate increaseDateByOneYear() {
		return increaseDateByOneYear(*this);
	}


	static clsDate increaseDateByXYears(int xYears, clsDate &date) {

		for (int i = 1; i <= xYears; i++) {
			increaseDateByOneYear(date);
		}
		return date;
	}
	clsDate increaseDateByXYears(int xYears) {
		return increaseDateByXYears(xYears, *this);
	}

	static clsDate decreaseDateByOneDay(clsDate &date) {

		if (date._day == 1) {
			if (date._month == 1) {
				--date._year;
				date._month = 12;
				date._day = 31;
			}
			else {
				--date._month;
				date._day = daysInMonth(date._month, date._year);
			}
		}
		else {
			--date._day;
		}
		return date;
	}
	clsDate decreaseDateByOneDay() {
		return decreaseDateByOneDay(*this);
	}


	static clsDate decreaseDateByXDays(int xDays, clsDate &date) {
		for (int i = 1; i <= xDays; i++) {
			decreaseDateByOneDay(date);
		}
		return date;
	}
	clsDate decreaseDateByXDays(int xDays) {
		return decreaseDateByXDays(xDays, *this);
	}

	static clsDate decreaseDateByOneMonth(clsDate& date) { //here

		if (date._month == 1) {
			--date._year;
			date._month = 12;
		}
		else {
			--date._month;
			int monthdays = daysInMonth(date._month, date._year);
			if (date._day > monthdays)
				date._day = monthdays;
		}
		return date;

	}
	clsDate decreaseDateByOneMonth() {
		return decreaseDateByOneMonth(*this);
	}


	static clsDate decreaseDateByXMonths(int xMonths, clsDate& date) {

		for (int i = 1; i <= xMonths; i++) {
			decreaseDateByOneMonth(date);
		}
		return date;
	}
	clsDate decreaseDateByXMonths(int xMonths) {
		return decreaseDateByXMonths(xMonths, *this);
	}

	static clsDate decreaseDateByOneYear(clsDate &date) {
		--date._year;
		if (date._month == 2) {
			date._day = daysInMonth(date._month, date._year);
		}
		return date;
	}
	clsDate decreaseDateByOneYear() {
		return decreaseDateByOneYear(*this);
	}


	static clsDate decreaseDateByXYears(int xYears, clsDate& date) {
		date._year -= xYears;
		if (date._month == 2) {
			date._day = daysInMonth(date._month, date._year);
		}
		return date;
	}
	clsDate decreaseDateByXYears(int xYears) {
		return decreaseDateByXYears(xYears, *this);
	}

	
	static clsDate decreaseDateByOneDecade(clsDate& date) {
		date._year -= 10;
		if (date._month == 2) {
			date._day = daysInMonth(date._month, date._year);
		}
		return date;

	}
	clsDate decreaseDateByOneDecade() {
		return  decreaseDateByOneDecade(*this);
	}

	static void decreaseDateByXDecades(int xDecades, clsDate& date) {
		date._year -= (xDecades * 10);
		if (date._month == 2) {
			date._day = daysInMonth(date._month, date._year);
		}
		
	}
	void decreaseDateByXDecades(int xDecades) {
		return decreaseDateByXDecades(xDecades, *this);


	}

	static void decreaseDateByOneCentury(clsDate& date) {
		date._year -= 100;
		if (date._month == 2) {
			date._day = daysInMonth(date._month, date._year);
		}
		
	}
	void decreaseDateByOneCentury() {
		return decreaseDateByOneCentury(*this);
	}


	static void decreaseDateByOneMelinium(clsDate &date) {
		date._year -= 1000;
		if (date._month == 2) {
			date._day = daysInMonth(date._month, date._year);
		}
		

	}
	void decreaseDateByOneMelinium() {
		return decreaseDateByOneMelinium(*this);
	}

	static short daysUntilTheWeekEnd(clsDate date) {
		short dayOrderInWeek = dayOrder(date._year, date._month, date._day);
		if (dayOrderInWeek == 0)
			return 0;
		else
			return 7 - dayOrderInWeek;
	}
	short daysUntilTheWeekEnd() {
		return daysUntilTheWeekEnd(*this);
	}

	static short daysUntilEndOfMonth(clsDate date) {
		return daysInMonth(date._month, date._year) - date._day;
	}
	short daysUntilEndOfMonth() {
		return daysUntilEndOfMonth(*this);
	}

	static short daysUntilEndOfYear(clsDate date) {
		return daysInYear(date._year) - totalDaysFromBeginingOfYear(date._year, date._month, date._day);
	}
	short daysUntilEndOfYear() {
		return daysUntilEndOfYear(*this);
	}

	static int calculateVacationDays( clsDate date1,  clsDate date2) {
		int vacationsDays = 0;
		if (!isDate1BeforeDate2(date1, date2)) {
			swap(date1, date2);
		}
		while (!isDate1EqualDate2(date1, date2)) {
			if (!isWeekEnd(date1))
				++vacationsDays;
			increasedDateByOneDay2(date1);

		}
		return vacationsDays;
	}
	int calculateVacationDays(clsDate date2) {
		return calculateVacationDays(*this, date2);
	}

	static clsDate returnDateAfterVacation(int vacationDays,clsDate date) {

		while (vacationDays > 0) {
			if (!isWeekEnd(date))
				--vacationDays;
			if (vacationDays == 0)
			break;
			increasedDateByOneDay2(date);

		}
		return date;
	}
	clsDate returnDateAfterVacation(int vacationDays) {
		return returnDateAfterVacation(vacationDays, *this);
	}

	enum enDateCompare{before=-1,after=1,equal=0};

	static enDateCompare compareDates(clsDate date1,clsDate date2) {

		if (isDate1BeforeDate2(date1, date2)) return enDateCompare::before;
		if (isDate1EqualDate2(date1, date2)) return enDateCompare::equal;
		else return enDateCompare::after;
	}

	enDateCompare compareDates(clsDate date) {
		return compareDates(*this, date);
	}

	static bool isValidDate(clsDate date) {

		return !((date._day > daysInMonth(date._month, date._year) || (date._month < 1 || date._month>12)));

	}

	static string dateToString(clsDate date) {
		return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
	}

	static string getStringDateAndTimeNow() {

		time_t t = time(0);
		tm* now = localtime(&t);

		string second =to_string( now->tm_sec);
		string minute =to_string( now->tm_min);
		string hour =to_string( now->tm_hour);

		string date = dateToString(clsDate());

		return date + "-" + hour + ":" + minute + ":" + second;
	}

};

