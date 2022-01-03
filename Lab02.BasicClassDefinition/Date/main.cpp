#include"Date.h"

int main()
{
	Date date;
	cout << date.Day() << "/" << date.Month() << "/" << date.Year() << endl;

	date.setDay(25);
	date.setMonth(10);
	date.setYear(2000);
	cout << date.toString() << endl;

	try
	{
		Date normal(5, 7, 2010);
		cout << "Normal time: " << normal.toString() << endl;

		Date fail(29, 2, 2019);
		cout << "Time caused exception" << fail.toString() << endl;
	}
	catch (exception &exc)
	{
		cout << exc.what();
	}
	return 0;
}