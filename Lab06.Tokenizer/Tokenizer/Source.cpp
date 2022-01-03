#include"Tokenizer.h"

int main()
{
	string line = "41, 817, 12, 9371, 154";
	string seperator = ", ";
	vector<string> tokens = Tokenizer::Parse(line, seperator);
	vector<int>num;
	for (auto i = 0; i < tokens.size(); i++)
	{
		int number = stoi(tokens[i]);
		num.push_back(number);
	}
	for (auto i = 0; i < num.size(); i++)
		cout << num[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}