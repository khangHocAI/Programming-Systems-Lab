#include"FractionTokenizer.h"

int main()
{
	string line = "1/2, 2/3, 3/4";
	string div = "/";
	string sep = ", ";
	vector<string>tokens = FractionTokenizer::Parse(line, div, sep);
	vector<Fraction> f;
	for (int i = 0; i < tokens.size(); i+=2)
	{
		int nom = stoi(tokens[i]);
		int denom = stoi(tokens[i + 1]);
		Fraction p(nom, denom);
		f.push_back(p);
	}
	for (int i = 0; i < f.size(); i++)
		cout << f[i].getNom() << " div " << f[i].getDenom() << endl;
	system("pause");
	return 0;
}