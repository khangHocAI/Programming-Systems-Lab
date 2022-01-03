#include"Category.h"

Date::Date()
{
	time_t infor = time(0);
	struct tm now;
	localtime_s(&now, &infor);
	_day = now.tm_mday;
	_month = now.tm_mon;
	_year = now.tm_year;
}
Date::Date(int day, int month, int year)
{
	bool isok = false;
	if ((day >= 1) && (day <= 31) && (month >= 1) && (month <= 12) && (year >= 1))
	{
		isok = true;
		if ((month == 2 && day > 29) || day == 29 && month == 2 && ((year % 4 != 0 || year % 100 == 0) && (year % 400 != 0)))
			isok = false;
	}
	if (isok)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	else throw runtime_error("Invalid argument");
}
string Date::toString()
{
	stringstream out;
	out << setfill('0') << setw(2) << _day << ":";
	out << setfill('0') << setw(2) << _month << ":";
	out << _year;
	return out.str();
}
Product::Product()
{
	_id = 123;
	_categoryId = 1;
	_productName = "kindle";
	_price = 50;
	_quantity = 1000;
	_sku = "kdl";
	time_t infor = time(0);
	struct tm now;
	localtime_s(&now, &infor);
	_importedDate.setDay(now.tm_mday);
	_importedDate.setMonth(now.tm_mon);
	_importedDate.setYear(now.tm_year);
	_description = "Book machine";

}
Product::Product(int id, int categoryId, string productName, float price, int quantity, string sku, Date importedDate, string description)
{
	_id = id;
	_categoryId = categoryId;
	_productName = productName;
	_price = price;
	_quantity = quantity;
	_sku = sku;
	_importedDate.setDay(importedDate.Day());
	_importedDate.setMonth(importedDate.Month());
	_importedDate.setYear(importedDate.Year());
	_description = description;
}
string Product::toString()
{
	stringstream ss;
	ss << _id << "-" << _categoryId << "-" << _productName << "-";
	ss << _price << "-" << _quantity << "-" << _sku << "-";
	ss << _importedDate.Day() << "-" << _importedDate.Month() << "-" << _importedDate.Year() << "-";
	ss << _description;
	return ss.str();
}
Category::Category()
{
	_id = 1;
	_name = "Hello";
}
Category::Category(int id , string name)
{
	_id = id;
	_name = name;
}
string Category::toString()
{
	stringstream ss;
	for (int i = 0; i < _product.size(); i++)
	{
		ss << _id << "-" << _product[i].categoryId() << "-" << _product[i].productName << "-";
		ss << _product[i].price << "-" << _product[i].quantity << "-" << _product[i].sku << "-";
		ss << _product[i].importedDate.Day() << "-" << _product[i].importedDate.Month() << "-" << _product[i].importedDate.Year() << "-";
		ss << _product[i].description << "\n";
	}
	return ss.str();
}