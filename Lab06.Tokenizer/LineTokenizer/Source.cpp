#include"LineTokenizer.h"

int main()
{
	string line = "(1, 2); (3, 4); (5, 6)";
	string XYsep = ", ";
	string linesep = "); (";
	vector<string>tokens = LineTokenizer::Parse(line, XYsep, linesep);
	vector<Line> f;
	for (int i = 0; i < tokens.size(); i += 2)
	{
		int x = stoi(tokens[i]);
		int y = stoi(tokens[i + 1]);
		Line p(x, y);
		f.push_back(p);
	}
	for (int i = 0; i < f.size(); i++)
		cout << f[i].getX() << " and " << f[i].getY() << endl;
	system("pause");
	return 0;
}