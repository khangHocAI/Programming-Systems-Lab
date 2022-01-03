#include"FakeTel.h"
int main()
{
	srand(time(NULL));
	FakeTel f;
	vector<string>tel, prefix;
	vector<string>dataPrefix;
	read("Prefix", dataPrefix);
	
	for (int i = 0; i < 10; i++)
	{
		prefix.push_back(dataPrefix[f.random(dataPrefix.size())]);
		string tl = "";
		for (int i = 0; i < 7; i++)
		{
			stringstream ss;
			int val = f.random(10);
			ss << val;
			tl += ss.str();
		}
		tel.push_back(tl);
	}
	for (int i = 0; i < 10; i++)
		cout << prefix[i] << tel[i] << endl;
	system("pause");
	return 0;
}