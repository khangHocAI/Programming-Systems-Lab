#include"Student.h"

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

Student::Student()
{
	_id = "18125086";
	_fullname = "Nguyen Huu Khang";
	_email = "huukhangvn@gmail.com";
	_birthday.setDay(25);
	_birthday.setMonth(10);
	_birthday.setYear(2000);
	_address = "57/45, Tran Binh Trong, P1,Q5,TPHCM";
	_tel = "0941413947";
}
Student::Student(string id, string fullname, string email, Date birthday, string address, string tel)
{
	_id = id;
	_fullname = fullname;
	_email = email;
	_birthday.setDay(birthday.Day());
	_birthday.setMonth(birthday.Month());
	_birthday.setYear(birthday.Year());
	_address = address;
	_tel = tel;
}
string Student::toString()
{
	stringstream out;
	out << _id << "-" << _fullname << "-"<< _email;
	out << _birthday.toString() << "\n" << _address << "-" << _tel;
	return out.str();
}