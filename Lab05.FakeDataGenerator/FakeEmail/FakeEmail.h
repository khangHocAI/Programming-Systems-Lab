#pragma once
#include<iostream>
#include<vector>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;

class FakeEmail
{
public:
	FakeEmail()
	{
		srand(time(0));
	}
	int random(int start, int range)
	{
		return rand() % range + start;
	}
	int random(int value)
	{
		return rand() % value;
	}
};
bool read(string name, vector<string>& v)
{
	ifstream fin;
	fin.open(name + ".txt");
	if (!fin.is_open()) return false;
	string data;
	while (!fin.eof())
	{
		getline(fin, data);
		if (data != "") v.push_back(data);
	}
	fin.close();
	return true;
}