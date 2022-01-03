#pragma once
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

class Random
{
public:
	Random() { srand(time(0)); }
	int next() {
		return rand();
	}
	int next(int ceiling) {
		return rand() % ceiling;
	}
};