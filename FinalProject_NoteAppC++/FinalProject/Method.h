#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Tag.h"
#include"Note.h"
#include"Helper.h"
#include"InvertedIndex.h"
using namespace std;

class Method
{
public:
	bool Load(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
	void Add(string title, string detail, vector<string>tags, NoteList& notelist, TagList& taglist, InvertedIndex& inverted);
	void Save(Note note);
	void DeleteTag(TagList& taglist, int index);
	void DeleteNote(NoteList& notelist, TagList& taglist, int index, InvertedIndex& inverted);
	void Search(InvertedIndex inverted, NoteList notelist, string key);
};