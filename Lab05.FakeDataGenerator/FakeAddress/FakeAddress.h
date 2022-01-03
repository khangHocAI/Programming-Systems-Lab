#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include<vector>
using namespace std;
class FakeAddress
{
private:
	string house_num;
	string street_name;
	string ward;
	string district;
	string city;
public:
	FakeAddress()
	{
		srand(time(0));
	}
	int dice(int size)
	{
		return rand() % size;
	}
};
bool read(string name, vector<string>&v)
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