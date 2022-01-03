#include"Date.h"

Date::Date()
{
	time_t infor = time(0);
	struct tm now;
	localtime_s(&now, &infor);
	_day = now.tm_mday;
	_month = now.tm_mon;
	_year = now.tm_year;
}
Date::Date(int day, int month, int year)
{
	bool isok = false;
	if ((day >= 1) && (day <= 31) && (month >= 1) && (month <= 12) && (year >= 1))
	{
		isok = true;
		if (day == 29 && month == 2 && ((year % 4 != 0 || year % 100 == 0) && (year % 400 != 0)))
			isok = false;
	}
	if (isok)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	else throw runtime_error("Invalid argument");
}
string Date::toString()
{
	stringstream out;
	out << setfill('0') << setw(2) << _day << ":";
	out << setfill('0') << setw(2) << _month << ":";
	out << _year;
	return out.str();
}