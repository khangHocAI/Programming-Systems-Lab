#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Fraction
{
private:
	int nominator, denominator;
public:
	int getNom() { return nominator; }
	int getDenom() { return denominator; }
	Fraction(int val1, int val2)
	{
		nominator = val1;
		denominator = val2;
	}
};
class FractionTokenizer
{
public:
	static vector<string>Parse(string line, string DivisionSep, string seperator)
	{
		int startPos = 0;
		vector<string>tokens;
		string sep = DivisionSep;
		size_t foundPos = line.find(sep,startPos);
		int i = 0;
		while (foundPos != string::npos)
		{
			string token;
			int count = foundPos - startPos;
			token = line.substr(startPos,count);
			tokens.push_back(token);
			startPos = foundPos + sep.size();
			i++;
			if (i % 2 == 0) sep = DivisionSep;
			else sep = seperator;
			foundPos = line.find(sep, startPos);
		}
		int count = line.length() - startPos;
		tokens.push_back(line.substr(startPos, count));
		return tokens;

	}

};