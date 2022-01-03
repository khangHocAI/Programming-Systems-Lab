#pragma once
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Shape
{
public:
	virtual void print() = 0;
	virtual float perimeter() = 0;
	virtual float area() = 0;
};

class Circle:public Shape
{
private:
	float radius;
public:
	Circle(float value) { radius = value; }
	void print() { cout << "Circle"; }
	float perimeter() { return (3.14 * 2 * radius); }
	float area() { return (3.14 *radius * radius); }
};

class Triangle:public Shape
{
private:
	float edge,height;
public:
	Triangle(float e, float h) { edge = e; height = h; }
	void print() { cout << "Triangle"; }
	float perimeter() { return (3 * edge ); }
	float area() { return (0.5 * edge * height); }
};

class Rectangle:public Shape
{
private:
	float length, width;
public:
	Rectangle(float l, float w) { length = l; width = w; }
	void print() { cout << "Rectangle"; }
	float perimeter() { return ( 2 * (length + width)); }
	float area() { return (length * width); }
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
		return rand() % 20 + 1;
	}
	int MakeRandom(int n)
	{
		return rand() % n + 1;
	}
};
