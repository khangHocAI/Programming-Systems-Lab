#pragma once

#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<sstream>
using namespace std;
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
