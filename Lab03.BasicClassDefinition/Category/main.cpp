#include"Category.h"

int main()
{
	Category c;
	cout << c.toString();
	try
	{
		Date d = Date(31, 2, 2019);
	}
	catch (exception &ex)
	{
		cout << ex.what();
	}
	system("pause");
	return 0;
}