#include"Address.h"

int main()
{
	Address a;
	cout << a.toString() << endl;
	a = Address("49", "2", "Eaknuec", "Krongpac", "DakLak", "VN", "47");
	cout << a.toString() << endl;
	system("pause");
	return 0;
}