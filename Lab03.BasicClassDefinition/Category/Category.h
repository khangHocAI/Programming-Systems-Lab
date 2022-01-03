#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<ctime>
#include<iomanip>
using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	//Constructor destructor
	Date();
	Date(int, int, int);
	~Date() {};
	//Properties
	int Day() { return _day; }
	int Month() { return _month; }
	int Year() { return _year; }
	void setDay(int value)
	{
		_day = value;
	}
	void setMonth(int value)
	{
		_month = value;
	}
	void setYear(int value)
	{
		_year = value;
	}
	//Method
	string toString();
};
class Product
{
private:
	int _id;
	int _categoryId;
	string _productName;
	float _price;
	int _quantity;
	string _sku;
	Date _importedDate;
	string _description;

public:
	int id() { return _id; }
	int categoryId() { return _categoryId; }
	string productName() { return _productName; }
	float price() { return _price; }
	int quantity() { return _quantity; }
	string sku() { return _sku; }
	Date importedDate() { return _importedDate; }
	string description() { return _description; }
	void setId(int value) { _id = value; }
	void setCategoryId(int value) { _categoryId = value; }
	void setProductName(string value) { _productName = value; }
	void setPrice(float value) { _price = value; }
	void setQuantity(int value) { _quantity = value; }
	void setSku(string value) { _sku = value; }
	void setImportedDate(Date value) { _importedDate = value; }
	void setDescription(string value) { _description = value; }
	Product();
	Product(int, int, string, float, int, string, Date, string);
	~Product() {};
	string toString();

};
class Category
{
private:
	int _id;
	string _name;
	vector<Product> _product;
public:
	int id() { return _id; }
	string name() { return _name; }
	void setId(int value) { _id = value; }
	void setName(string value) { _name = value; }
	Category();
	Category(int, string);
	~Category() {};
	string toString();

};