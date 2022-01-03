#include"Address.h"

Address::Address()
{
	_number = "57/45";
	_street = "TBT";
	_ward = "1";
	_district = "5";
	_city = "HCM";
	_country = "VN";
	_postalCode = "084";
}
Address::Address(string number, string street, string ward, string district, string city, string country, string postalCode)
{
	_number = number;
	_street = street;
	_ward = ward;
	_district = district;
	_city = city;
	_country = country;
	_postalCode = postalCode;
}
string Address::toString()
{
	stringstream ss;
	ss << _number << "/" << _street << "/" << _ward << "/" << _district << "/" << _city << "/" << _country << "/" << _postalCode;
	return ss.str();
}