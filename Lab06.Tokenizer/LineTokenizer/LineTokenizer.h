#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Line
{
private:
	int x, y;
public:
	int getX() { return x; }
	int getY() { return y; }
	Line(int val1, int val2)
	{
		x = val1;
		y = val2;
	}
};
class LineTokenizer
{
public:
	static vector<string>Parse(string line, string XYsep, string LineSep)
	{
		int startPos = 1;
		vector<string>tokens;
		string sep = XYsep;
		size_t foundPos = line.find(sep, startPos);
		int i = 0;
		while (foundPos != string::npos)
		{
			string token;
			int count = foundPos - startPos;
			token = line.substr(startPos, count);
			tokens.push_back(token);
			startPos = foundPos + sep.size();
			i++;
			if (i % 2 == 0) sep = XYsep;
			else sep = LineSep;
			foundPos = line.find(sep, startPos);
		}
		int count = line.length() - startPos - 1;
		tokens.push_back(line.substr(startPos, count));
		return tokens;

	}
};