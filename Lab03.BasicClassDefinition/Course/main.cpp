#include"Course.h"

int main()
{
	Course c;
	cout << c.toString() << endl;
	c = Course("STAT", "STATISTICS", 2019, 2020, 1);
	cout << c.toString() << endl;
	system("pause");
	return 0;
}