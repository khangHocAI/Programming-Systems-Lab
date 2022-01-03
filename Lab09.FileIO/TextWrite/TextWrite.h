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

};