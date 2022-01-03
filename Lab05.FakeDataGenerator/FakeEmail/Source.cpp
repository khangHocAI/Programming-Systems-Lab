#include"FakeEmail.h"

int main()
{
	srand(time(NULL));
	FakeEmail f;
	vector<string>local, domain;
	vector<string>dataDomain;
	read("domain", dataDomain);
	vector<int>character;
	for (int i = 48; i < 58; i++) character.push_back(i);
	for (int i = 65; i < 91; i++) character.push_back(i);
	for (int i = 97; i < 123; i++) character.push_back(i);
	for (int i = 0; i < 10; i++)
	{
		int sizeOfLocal = f.random(10, 15);
		string lc = "";
		for (int i = 0; i < sizeOfLocal; i++)
		{
			int t = f.random(61);
			lc += char(character[t]);
		}
		local.push_back(lc);
		domain.push_back(dataDomain[f.random(dataDomain.size())]);
	}
	for (int i = 0; i < 10; i++)
		cout << local[i] << "@" << domain[i] << endl;
	system("pause");
	return 0;
}