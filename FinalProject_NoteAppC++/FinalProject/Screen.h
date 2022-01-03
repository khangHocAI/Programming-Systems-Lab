#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Method.h"
#include"Helper.h"
using namespace std;

class Screen
{
public:
	static void Menu(NoteList & notelist, TagList& taglist, InvertedIndex& inverted);
	static void AddScreen(NoteList & notelist, TagList& taglist, InvertedIndex& inverted);
	static void ViewScreen(NoteList notelist, TagList taglist, InvertedIndex inverted);
	static void ViewTagScreen(NoteList notelist, TagList taglist, int& index);
	static void ViewRelatedNoteScreen(NoteList notelist, TagList taglist, int index, InvertedIndex inverted);
	static void ViewNoteScreenFromTag(NoteList notelist, TagList taglist, Note note, int index, InvertedIndex inverted);
	static void ViewNoteScreen(NoteList notelist, TagList taglist, InvertedIndex inverted);
	static void DeleteScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
	static void DeleteTagScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
	static void DeleteNoteScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
	static void SearchScreen(NoteList notelist, TagList taglist, InvertedIndex inverted);
	static void DisplayNote(Note note);
	static void DisplayNoteList(NoteList notelist);
	static void ExitScreen();
};

void AddTagScreen(string &n);