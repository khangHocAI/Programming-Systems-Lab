#pragma once
#include<string>
#include<vector>
#include<fstream>
#include"Note.h"

using namespace std;

class Tag
{
private:
	string Name;
	vector<Note> RelatedNote;
public:
	Tag(string data)
	{
		Name = data;
	}
	string getName() { return Name; }
	int getRelatedNoteSize() { return RelatedNote.size(); }
	Note getRelatedNote(int index) { return RelatedNote[index]; }
	Note* getRelatedNoteAddress(int index) { return &RelatedNote[index]; }
	void addRelatedNote(Note note) { RelatedNote.push_back(note); }
	void RemoveNoteInTag(string name)
	{
		size_t position = 0;
		for (position; position < RelatedNote.size(); position++)
			if (RelatedNote[position].getTitle() == name)
			{
				break;
			}
		if (position < RelatedNote.size())
			RelatedNote.erase(RelatedNote.begin() + position);
	}
};
class TagList
{
private:
	vector<Tag>list;
	vector<string>listname;
public:
	
	void addTag(Tag tag) { list.push_back(tag); }
	Tag getTag(int index) { return list[index]; }
	Tag* getTagAddress(int index) { return &list[index]; }
	string getTagName(int index) { return listname[index]; }
	void addTagName(string name) { listname.push_back(name); }
	int getlistTagsize() { return listname.size(); }
	int IsExistedTag(string name)
	{
		for (size_t i = 0; i < listname.size(); i++)
			if (listname[i] == name) return i ;
		return -1;
	}
	void RemoveTag(int index)
	{
		list.erase(list.begin() + index);
		listname.erase(listname.begin() + index);
	}


	
};