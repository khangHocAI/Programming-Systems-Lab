#pragma once
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<ctime>
using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	//Constructor, destructor
	Date();
	Date(int, int, int);
	~Date() {};
	//Properties
	int Day() { return _day; }
	int Month() { return _month; }
	int Year() { return _year; }
	void setDay(int value)
	{
		_day = value;
	}
	void setMonth(int value)
	{
		_month = value;
	}
	void setYear(int value)
	{
		_year = value;
	}
	//Method
	string toString();
};
class Time {
private:
	int _hour = 0;
	int _min = 0;
	int _sec = 0;
public:
	//Constructor, destructor
	Time();
	Time(int, int, int);
	~Time() {};
	// Properties
	int Hour()
	{
		return _hour;
	}
	int Min()
	{
		return _min;
	}
	int Sec()
	{
		return _sec;
	}
	void setHour(int value)
	{
		_hour = value;
	}
	void setMin(int value)
	{
		_min = value;
	}
	void setSec(int value)
	{
		_sec = value;
	}
	// method
	string toString();


};
class DateTime
{
private:
	Date _date;
	Time _time;
public:
	DateTime();
	DateTime(Date, Time);
	~DateTime() {};
	int Day() { return _date.Day(); }
	int Month() { return _date.Month(); }
	int Year() { return _date.Year(); }
	int Hour() { return _time.Hour(); }
	int Min() { return _time.Min(); }
	int Sec() { return _time.Sec(); }
	void setDate(int day, int month, int year)
	{
		_date.setDay(day);
		_date.setMonth(month);
		_date.setYear(year);
	}
	void setTime(int hour, int min, int sec)
	{
		_time.setHour(hour);
		_time.setMin(min);
		_time.setSec(sec);
	}
	string toString();
};