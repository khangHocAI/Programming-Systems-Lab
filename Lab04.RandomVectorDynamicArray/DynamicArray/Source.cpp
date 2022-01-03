#include"DynamicArray.h"

int main()
{
	int length;
	cout << "Size:";
	cin >> length;
	DynamicArray a;
	Random r;
	for (int i = 0; i < length; i++)
	{
		int num = r.next();
		a.push_back(num);
	}
	cout << "Array:\n";
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
		sum += a[i];
	}
	cout << "\n" << sum << endl;
	system("pause");
	return 0;
}