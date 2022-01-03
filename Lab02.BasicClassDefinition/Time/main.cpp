#include"Time.h"

int main()
{
	Time now;
	cout << now.Hour() << ":" << now.Min() << ":" << now.Sec() << endl;

	now.setHour(10);
	now.setMin(9);
	now.setSec(1);
	cout << now.toString() << endl;
	try
	{
		Time normal(5, 7, 10);
		cout << "Normal time: " << normal.toString() << endl;

		Time fail(100, 100, 100);
		cout << "Time caused exception" << fail.toString() << endl;
	}
	catch (exception &ex)
	{
		cout << ex.what();
	}

	return 0;
}