#pragma once
#include<iostream>
#include<vector>
#include<time.h>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class FakeTel
{
public:
	FakeTel()
	{
		srand(time(0));
	}
	int random(int range)
	{
		return rand() % range;
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