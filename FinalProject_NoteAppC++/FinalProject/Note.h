#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Note
{
private:
	string Title;
	string Detail;
	vector<string>tags;
public:
	Note(string title, string detail) { Title = title; Detail = detail; }
	string getTitle() { return Title; }
	string getDetail() { return Detail; }
	string get76Character() {
		int t = Detail.size();
		int size = min(t, 76);
		string res = "";
		for (int i = 0; i < size; i++)
		{
			if (Detail[i] == '\n') res += " ";
			else res += Detail[i];
		}
		if (size == 76) res += "...";
		return res;
	}
	string getTag(int index) { return tags[index]; }
	void setTitle(string title) { Title = title; }
	void setDetail(string detail) { Detail = detail; }
	void setTag(string tag)
	{
		tags.push_back(tag);
	}
	int getNumofTag() { return tags.size(); }
	void RemoveTagInNote(string name)
	{
		size_t position = 0;
		for (position; position < tags.size(); position++)
			if (tags[position] == name)
			{
				break;
			}
		if (position < tags.size())
			tags.erase(tags.begin() + position);
	}
	
};
class NoteList
{
private:
	vector<Note>list;
	vector<string>listname;
public:
	void AddANote(Note newNote) { list.push_back(newNote); }
	int getlistNotesize() { return listname.size(); }
	Note getNote(int index) { return list[index]; }
	Note* getNoteAddress(int index) { return &list[index]; }
	string getNoteName(int index) { return listname[index]; }
	void AddNoteName(string name) { listname.push_back(name); }
	bool IsExistedNote(string name)
	{
		for (auto it = listname.begin(); it != listname.end(); it++)
			if (*it == name) return true;
		return false;
	}
	void RemoveNote(int index)
	{
		list.erase(list.begin() + index);
		listname.erase(listname.begin() + index);
	}
};