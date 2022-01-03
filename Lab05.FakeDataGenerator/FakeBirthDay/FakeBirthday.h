#pragma once
#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

class FakeBirthday
{
public:
	FakeBirthday()
	{
		srand(time(0));
	}
	int random(int val1, int range)
	{
		return rand() % range + val1;
	}



};


