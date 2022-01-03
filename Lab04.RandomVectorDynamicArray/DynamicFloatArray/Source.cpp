#include"DynamicFloatArray.h"

int main()
{
	int length;
	cout << "Size:";
	cin >> length;
	DynamicArray a;
	Random r;
	for (int i = 0; i < length; i++)
	{
		float num = r.next();
		a.push_back(num);
	}
	cout << "Array:\n";
	float sum = 0;
	for (int i = 0; i < length; i++)
	{
		cout << fixed << setprecision(2) << a[i] << " ";
		sum += a[i];
	}
	cout << "\n" << fixed << setprecision(2) << sum << endl;
	system("pause");
	return 0;
}