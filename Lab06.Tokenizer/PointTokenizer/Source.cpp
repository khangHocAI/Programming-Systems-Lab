#include"PointTokenizer.h"

int main()
{
	string line = "1/2, 2/3, 3/4";
	string div = "/";
	string sep = ", ";
	vector<string>tokens = PointTokenizer::Parse(line, div, sep);
	vector<Point> f;
	for (int i = 0; i < tokens.size(); i += 2)
	{
		int x = stoi(tokens[i]);
		int y = stoi(tokens[i + 1]);
		Point p(x, y);
		f.push_back(p);
	}
	for (int i = 0; i < f.size(); i++)
		cout << f[i].getX() << " , " << f[i].getY() << endl;
	system("pause");
	return 0;
}