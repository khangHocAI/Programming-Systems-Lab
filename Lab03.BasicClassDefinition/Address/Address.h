#pragma once
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Address
{
private:
	string _number;
	string _street;
	string _ward;
	string _district;
	string _city;
	string _country;
	string _postalCode;
public:
	string number() { return _number; }
	string street() { return _street; }
	string ward() {
		return _ward;
	}
	string district() { return _district; } 
	string city() { return _city; }
	string country() { return _country; }
	string postalCode() { return _postalCode; }
	void setNumber(string value) { _number = value; }
	void setStreet(string value) { _street = value; }
	void setWard(string value) { _ward = value; }
	void setDistrict(string value){ _district = value; }
	void setCity(string value){ _city = value; }
	void setCountry(string value){ _country = value; }
	void setPostalCode(string value) {
			_postalCode = value;
	}
	Address();
	Address(string, string, string, string, string, string, string);
	~Address() {};
	string toString();

};