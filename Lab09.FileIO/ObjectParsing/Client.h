#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

class Client
{
private:
	int Id;
	string Name;
	double Balance;
public:
	Client()
	{
		Id = 1;
		Name = "A";
		Balance = 0;
	}
	Client(int id, string name, double balance)
	{
		Id = id;
		Name = name;
		Balance = balance;
	}
	string tostring()
	{
		stringstream ss;
		ss << Id << " - " << Name << " - " << Balance;
		return ss.str();
	}
	void Parse(string line, string seperator)
	{
		int startPos = 0;
		size_t foundPos = line.find(seperator, startPos);
		int i = 0;
		while (foundPos != string::npos)
		{
			int count = foundPos - startPos;
			string token = line.substr(startPos, count);
			if (i == 0) Id = stoi(token);
			else Name = token;
			startPos = foundPos + seperator.length();
			foundPos = line.find(seperator, startPos);
			i++;
		}
		int count = line.length() - startPos;
		string token = line.substr(startPos, count);
		Balance = stod(token);
	}
};
