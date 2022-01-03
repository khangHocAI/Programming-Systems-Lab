#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<sstream>
#include<iomanip>
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