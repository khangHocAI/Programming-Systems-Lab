#include"FakeAddress.h"

int main()
{
	srand(time(NULL));
	FakeAddress f;
	vector<string> iniHouseNum, iniStreet, iniWard, iniDist;
	read("housenum", iniHouseNum);
	read("street", iniStreet);
	read("ward", iniWard);
	read("district", iniDist);
	vector<string> RanHouseNum, RanStreet, RanWard, RanDist;
	for (int i = 0; i < 10; i++)
	{
		RanHouseNum.push_back(iniHouseNum[f.dice(iniHouseNum.size())]);
		RanStreet.push_back(iniStreet[f.dice(iniStreet.size())]);
		RanWard.push_back(iniWard[f.dice(iniWard.size())]);
		RanDist.push_back(iniDist[f.dice(iniDist.size())]);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << RanHouseNum[i] << ", " << RanStreet[i];
		cout << ", " << RanWard[i] << ", " << RanDist[i] << ", " << "HCM" << endl;
	}
	system("pause");
	return 0;
}