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
class DynamicArray
{
private:
	const int INITIAL_SIZE = 64;
	const int SIZE_INCREASE_STEP = 128;
	int *_a;
	int _length;
	int _maxsize;
public:
	int Size() { return _length; }
	DynamicArray();
	~DynamicArray();
	void push_back(int element);
	int operator[](int index);

};