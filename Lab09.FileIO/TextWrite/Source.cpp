#include"TextWrite.h"

int main()
{
	int n;
	cout << "Number of customer: ";
	cin >> n;
	vector<Client*>list;
	int id;
	string name;
	double balance;
	for (int i = 0; i < n;i++)
	{
		cout << i + 1 << ":" << endl;
		cout << "ID: ";
		cin >> id;
		cout << "NAME: ";
		getline(cin, name);
		while (name.length()<1) getline(cin, name);
		cout << "BALANCE: ";
		cin >> balance;
		list.push_back(new Client(id, name, balance));
	}
	ofstream fout("client.txt",ios::out);
	while (!fout)
	{
		exit(EXIT_FAILURE);
	}
	fout << list.size();
	for (auto& client : list)
	{
		fout << endl << client->tostring();
	}
	return 0;

}