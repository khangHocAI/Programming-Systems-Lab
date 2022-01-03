#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<sstream>
using namespace std;

class Random
{
public:
	Random();
	~Random() {};
	string toString();
	int next();
	int next(int);
};