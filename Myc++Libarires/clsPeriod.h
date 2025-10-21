#pragma once
#include<iostream>
#include"Myc++Libarires/clsDate.h";
#include"Myc++Libarires/clsString.h";
using namespace std;
class clsPeriod
{
private:
	clsDate _sDate;
	clsDate _eDate;
public :
	clsPeriod(clsDate sdate,clsDate edate) {
		_sDate = sdate;
		_eDate = edate;
	}
	static bool isPeriodsOverlaping(clsPeriod period1, clsPeriod period2) {

		if ((clsDate::compareDates(period2._eDate, period1._sDate) == clsDate::enDateCompare::before)
			||
			(clsDate::compareDates(period1._eDate, period2._sDate) == clsDate::enDateCompare::before))
			return false;
		else
			return true;
	}
	bool isPeriodsOverlaping(clsPeriod period) {
		return isPeriodsOverlaping(*this, period);
	}

	static int periodLegnthInDays(clsDate date1,clsDate date2) {
		return clsDate::differenceBetweenTwoDates(date1, date2);
	}
	int periodLegnthInDays() {
		return periodLegnthInDays(this->_sDate, this->_eDate);
	}


	static bool isDateInPeriod(clsPeriod period1, clsDate date1) {
		if ((clsDate::compareDates(date1, period1._sDate) == clsDate::enDateCompare::before)
			||
			(clsDate::compareDates(date1, period1._eDate) == clsDate::enDateCompare::after))
			return false;
		else
			return true;
	}
	bool isDateInPeriod(clsDate date) {
		return isDateInPeriod(*this, date);
	}


	static int countOverlapsDays(clsPeriod period1, clsPeriod period2) {

		int counter = 0;
		int period1Legnth = period1.periodLegnthInDays();
		int period2Legnth = period2.periodLegnthInDays();

		if (period1Legnth > period2Legnth) {
			while (clsDate::compareDates(period2._sDate, period2._eDate) != clsDate::enDateCompare::equal) {
				if (period1.isDateInPeriod(period2._sDate))
					++counter;
				clsDate::increasedDateByOneDay2(period2._sDate);
			}
		}
		else {
			while (clsDate::compareDates(period1._sDate, period1._eDate) != clsDate::enDateCompare::equal) {
				if (period2.isDateInPeriod(period1._sDate))
					++counter;
				clsDate::increasedDateByOneDay2(period1._sDate);
			}
		}
		return counter;
	}

	int countOverlapsDays(clsPeriod period) {
		return countOverlapsDays(*this, period);
	}

};

