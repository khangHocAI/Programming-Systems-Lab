#include"Course.h"
Course::Course()
{
	_id = "CS202";
	_name = "Program";
	_academicStartYear = 2019;
	_academicEndYear = 2020;
	_semester = 1;
}
Course::Course(string id, string name, int academicStartYear, int academicEndYear, int semester)
{
	_id = id;
	_name = name;
	_academicStartYear = academicStartYear;
	_academicEndYear = academicEndYear;
	_semester = 1;
}
string Course::toString()
{
	stringstream ss;
	ss << _id << "-" << _name << "-" << _academicStartYear << "-" << _academicEndYear << "-" << _semester;
	return ss.str();
}