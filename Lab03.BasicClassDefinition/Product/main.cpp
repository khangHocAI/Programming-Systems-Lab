#include"Product.h"

int main()
{
	Product p;
	cout << p.toString() << endl;
	try
	{
		Date d = Date(30, 2, 2000);
		cout << "ERROR";
	}
	catch (exception &ex)
	{
		cout << ex.what();
	}
	system("pause");
	return 0;
}