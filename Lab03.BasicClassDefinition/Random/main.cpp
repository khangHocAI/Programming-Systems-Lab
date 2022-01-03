#include"Random.h"

int main()
{
	Random r;
	cout << r.toString() << endl;
	cout << r.next(10000);
	system("pause");
	return 0;
}