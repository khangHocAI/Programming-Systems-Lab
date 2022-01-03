#include"Random.h"

int main()
{
	const int INITIAL_SIZE = 100;
	const int MAX = 200;
	Random r;

	int length;
	cout << "Size:";
	cin >> length;

	vector<int>a;
	a.reserve(INITIAL_SIZE);
	for (int i = 0; i < length; i++)
	{
		int num = r.next(MAX);
		a.push_back(num);
	}
	int sum = 0;
	cout << "Vector:\n";
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
		sum += a[i];
	}
	cout << "\n" << sum << endl;
	system("pause");
	return 0;
}