#pragma once
#include<Windows.h>
#include<vector>
#include<fstream>
#include<string>
#include<conio.h>
#include<algorithm>
#include<sstream>
#include"Note.h"
#include"Tag.h"
#include"InvertedIndex.h"
using namespace std;

class Helper
{
public:
	void saveNoteFile(Note note);
	void saveNotetoList(Note note);
	void saveNoteList(NoteList notelist);
	void reWriteNoteList(NoteList notelist);
	void gotoxy(int column, int line);
	int wherex();
	int wherey();
	vector<string> TagTokenizer(string data);
	bool getAllNoteTitle(vector<string>& v);
	bool readEachNote(string name, NoteList& notelist, TagList& taglist, InvertedIndex& inverted);
	string inputData(char* p);
	bool checkNumber(string data, int n, int &trans);
	void ConvertLower(string& data);
	void wordTokenizer(string data, vector<string>& v, map<string, int>& m);
};