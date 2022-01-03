#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Course
{
private:
	string _id;
	string _name;
	int _academicStartYear;
	int _academicEndYear;
	int _semester;
public:
	string id() { return _id; }
	string name() { return _name; }
	int academicStartYear() { return _academicStartYear; }
	int academicEndYear() { return _academicEndYear; }
	int semester() { return _semester; }
	void setName(string value) { _name = value; }
	void setAcademicStartYear(int value) { _academicStartYear = value; }
	void setAcademicEndYear(int value) { _academicEndYear = value; }
	void setSemester(int value) { _semester = value; }
	Course();
	Course(string, string, int, int, int);
	~Course() {};
	string toString();
};