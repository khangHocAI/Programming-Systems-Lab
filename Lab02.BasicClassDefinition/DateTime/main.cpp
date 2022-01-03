#include"DateTime.h"

int main()
{
	DateTime dt;
	cout << dt.Day() << "-" << dt.Month() << "-"<<  dt.Year() << endl;
	cout << dt.Hour() << ":" << dt.Min() << ":" << dt.Sec() << endl;

	dt.setDate(25, 10, 2000);
	dt.setTime(10, 11, 15);
	cout << dt.toString() << endl;

	try
	{
		Date fail(29, 2, 2019);

		cout << "Time caused exception" << fail.toString() << endl;
		Time t(100, 100, 100);
		cout << "Time caused exception" << t.toString() << endl;

	}
	catch (exception &exc)
	{
		cout << exc.what();
	}
	return 0;
}