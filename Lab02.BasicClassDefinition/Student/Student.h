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
class Student
{
private:
	string _id;
	string _fullname; 
	string _email; 
	Date _birthday;
	string _address; 
	string _tel;

public:
	Student();
	Student(string, string, string, Date, string, string);
	~Student() {};

	string Id() { return _id; }
	string Fullname() { return _fullname; } 
	string Email() { return _email; } 
	Date Birthday() { return _birthday; }
	string Address() { return _address; }
	string Tel() { return _tel; }

	void SetId(string value)
	{
		_id = value;
	}
	void SetFulname(string value){
		_fullname = value;
	}
	void SetEmail(string value) {
		_email = value;
	}
	void SetBirthday(Date value) {
		_birthday.setDay(value.Day());
		_birthday.setMonth(value.Month());
		_birthday.setYear(value.Year());
	}
	void SetAddress(string value) {
		_address = value;
	}
	void	SetTel(string value){
		_tel = value;
	}
	
	string toString();
};