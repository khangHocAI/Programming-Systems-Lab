#include"DateTime.h"

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
Time::Time()
{
	time_t info = time(0);
	struct tm now;
	localtime_s(&now, &info);
	_hour = now.tm_hour;
	_min = now.tm_min;
	_sec = now.tm_sec;
}
Time::Time(int hour, int min, int sec)
{
	if ((0 <= hour) && (hour <= 12) && (min >= 0) && (min <= 59) && (sec >= 0) && (sec <= 59))
	{
		_hour = hour;
		_min = min;
		_sec = sec;
	}
	else
	{
		throw runtime_error("Invalid argument");
	}
}
string Time::toString()
{
	stringstream out;
	out << setfill('0') << setw(2) << _hour;
	out << ":";
	out << setfill('0') << setw(2) << _min;
	out << ":";
	out << setfill('0') << setw(2) << _sec;
	return out.str();
}

DateTime::DateTime()
{
	time_t info = time(0);
	struct tm now;
	localtime_s(&now, &info);
	_date.setDay(now.tm_mday);
	_date.setMonth(now.tm_mon + 1);
	_date.setYear(now.tm_year + 1900);
	_time.setHour(now.tm_hour);
	_time.setMin(now.tm_min);
	_time.setSec(now.tm_sec);
}
DateTime::DateTime(Date d, Time t)
{
	_date.setDay(d.Day());
	_date.setMonth(d.Month());
	_date.setYear(d.Year());
	_time.setHour(t.Hour());
	_time.setMin(t.Min());
	_time.setSec(t.Sec());
}
string DateTime::toString()
{
	stringstream ss;
	ss << _time.toString() << " at " << _date.toString();
	return ss.str();
}