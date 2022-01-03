#include"EmployeePolymorphism.h"

int main()
{
	srand(time(NULL));
	int n;
	cin >> n;
	Random rd;
	int pe = rd.MakeRandom(n-2);
	int de = rd.MakeRandom(n - pe - 1);
	int man = n - pe - de;
	int price = rd.MakeRandom(10) * 1000;
	int dailySalary = rd.MakeRandom(5) * 100000;
	
	Employee *e;
	for (int i = 0; i < pe; i++)
	{
		Product_employee pro(rd.MakeRandom(200), price);
		e = &pro;
		e->print();
		cout << e->salary() << endl;
	}
	for (int i = 0; i < de; i++)
	{
		Daily_employee daily(rd.MakeRandom(30), dailySalary);
		e = &daily;
		e->print();
		cout << e->salary() << endl;
	}
	for (int i = 0; i < man; i++)
	{
		int baseSalary = rd.MakeRandom(10) * 1000000;
		int factor = rd.MakeRandom(5);
		Manager mn(baseSalary, factor);
		e = &mn;
		e->print();
		cout << e->salary() << endl;
	}
	system("pause");
	return 0;
}