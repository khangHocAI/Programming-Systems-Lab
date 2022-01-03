#pragma once

#include<iostream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<random>
using namespace std;

class Random
{
public:
	Random() { srand(time(0)); }
	float next() {
		static std::default_random_engine e;
		static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
		return dis(e);
	}
	float next(int ceiling) {
		static std::default_random_engine e;
		static std::uniform_real_distribution<> dis(0, ceiling); // rage 0 - 1
		return dis(e);
	}
};
class DynamicArray
{
private:
	const int INITIAL_SIZE = 64;
	const int SIZE_INCREASE_STEP = 128;
	float *_a;
	int _length;
	int _maxsize;
public:
	int Size() { return _length; }
	DynamicArray();
	~DynamicArray();
	void push_back(float element);
	float operator[](int index);

};