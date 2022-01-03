#pragma once
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Employee
{
public:
	virtual int salary() = 0;
	virtual void print() = 0;
};

class Product_employee: public Employee
{
private: 
	int product;
	int price;
public:
	Product_employee(int value, int val2) { product = value; price = val2; }
	void print() { cout << "Product employee: "; }
	int salary()
	{
		return product * price;
	}

};
class Daily_employee: public Employee
{
private: 
	int day;
	int daysalary;
public:
	Daily_employee(int value, int val2) { day = value;daysalary = val2; }
	void print() { cout << "Daily employee: "; }
	int salary()
	{
		return day * daysalary;
	}
};
class Manager: public Employee
{
private:
	int base;
	int workfactor;
public:
	Manager(int val1, int val2) { base = val1; workfactor = val2; }
	void print() { cout << "Manager: "; }
	int salary()
	{
		return base * workfactor;
	}
};

class Random
{
public:
	Random()
	{
		srand(time(0));
	}
	int MakeRandom()
	{
		return rand() % 200 + 1;
	}
	int MakeRandom(int n)
	{
		return rand() % n + 1;
	}
};