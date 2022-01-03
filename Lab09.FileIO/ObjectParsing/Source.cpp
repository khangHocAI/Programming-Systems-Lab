#include"Client.h"


int main()
{
	ifstream fin("client.txt",ios::in);
	if (!fin)
	{
		exit(EXIT_FAILURE);
	}
	string line;
	getline(fin, line);
	int n = stoi(line);
	vector<Client> list;
	for (int i = 0; i < n;i++)
	{
		getline(fin, line,'\n');
		Client client;
		client.Parse(line, " - ");
		list.push_back(client);
	}
	for (auto& x : list)
	{
		cout << endl << x.tostring();
	}
	return 0;
}