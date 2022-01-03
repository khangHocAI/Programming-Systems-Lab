#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

int main()
{
	const int INITIAL_SIZE = 100;
	const int MAX = 200;
	srand(time(NULL));

	int length;
	cout << "Size:";
	cin >> length;

	vector<int>a;
	a.reserve(INITIAL_SIZE);
	for (int i = 0; i < length; i++)
	{
		int num = rand() % MAX;
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