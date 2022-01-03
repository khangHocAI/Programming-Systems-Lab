#pragma once
#include<iostream>
#include<time.h>
using namespace std;

class Dice
{
public:
	Dice()
	{
		srand(time(0));
	}
	int Roll()
	{
		return rand() % 6 + 1;
	}
};