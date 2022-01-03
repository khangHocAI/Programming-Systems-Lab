#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
	vector<string> tokens;
	vector<int>numbers;
	string line = "41, 817, 12, 9371, 154";
	string sep = ", ";
	int stpos = 0;
	size_t foundpos = line.find(sep, stpos);
	while (foundpos != string::npos)
	{
		int count = foundpos - stpos;
		string token = line.substr(stpos, count);
		tokens.push_back(token);
		stpos = foundpos + sep.length();
		foundpos = line.find(sep,stpos);
	}
	int count = foundpos - stpos;
	string token = line.substr(stpos, count);
	tokens.push_back(token);
	for (auto i = 0; i < tokens.size(); i++)
	{
		auto num = stoi(tokens[i]);
		numbers.push_back(num);
	}
	for (auto i = 0; i < numbers.size(); i++) cout << numbers[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}