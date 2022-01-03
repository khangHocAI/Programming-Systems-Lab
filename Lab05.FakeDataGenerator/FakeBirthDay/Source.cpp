#include"FakeBirthday.h"

int main()
{
	srand(time(NULL));
	FakeBirthday f;
	vector<int>day, month, year;
	for (int i = 0; i < 10; i++)
	{
		int y = f.random(1900, 119);
		year.push_back(y);
		int m = f.random(1, 12);
		month.push_back(m);
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) day.push_back(f.random(1, 31));
		else if (m == 4 || m == 6 || m == 9 || m == 11) day.push_back(f.random(1, 30));
		else
		{
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) day.push_back(f.random(1, 29));
			else day.push_back(f.random(1, 28));
		}
	}
	for (int i = 0; i < 10; i++)
		cout << day[i] << " - " << month[i] << " - " << year[i] << endl;
	system("pause");
	return 0;
}