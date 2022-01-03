#pragma once
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<fstream>
using namespace std;

class word_position
{
private:
	string filename;
	int AppearanceTime;
public:
	word_position(string name, int val) { filename = name; AppearanceTime = val; }
	string getfileName() { return filename; }
	int getAppearanceTime() { return AppearanceTime; }
	void setfileIndex(string value) { filename = value; }
	void setAppearanceTime(int value) { AppearanceTime = value; }
};
class InvertedIndex
{
private:
	map<string, vector<word_position> > Dictionary;
	vector<string>DeletedFile;
public:
	void addNewFile(string name, vector<string>v, map<string, int>m)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			string word = v[i];
			word_position wp(name, m[word]);
			Dictionary[word].push_back(wp);
		}
	}
	void addDeletedNote(string name) { DeletedFile.push_back(name); }
	void SearchFile(string word)
	{
		if (Dictionary.find(word) == Dictionary.end())
		{
			cout << "No instance exist\n";
			return;
		}
		int size = (int)Dictionary[word].size();
		for (int counter = 0; counter < size; counter++)
		{
			string name = Dictionary[word][counter].getfileName();
			bool isok = true;
			for (auto it = DeletedFile.begin(); it != DeletedFile.end(); it++)
				if (*it == name) isok = false;
			if (isok)
			{
				cout << "   " << counter + 1;
				cout << ".Filename: " << name << endl;
				cout << "-> Appear: " << Dictionary[word][counter].getAppearanceTime() << endl;
			}
		}
	}
};
