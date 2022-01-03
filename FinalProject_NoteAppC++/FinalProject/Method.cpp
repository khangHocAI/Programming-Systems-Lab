#include"Method.h"

bool Method::Load(NoteList& notelist, TagList& taglist, InvertedIndex &inverted)
{
	vector<string>v;
	Helper helper;
	bool isok = helper.getAllNoteTitle(v);
	if (!isok) return false;
	for (auto it = v.begin(); it != v.end(); it++)
		bool readable = helper.readEachNote(*it, notelist, taglist, inverted);
	return true;
}
void Method::Add(string title, string detail, vector<string>tags, NoteList& notelist, TagList& taglist,InvertedIndex &inverted)
{
	Helper helper;
	bool isexist = notelist.IsExistedNote(title);
	if (isexist)
	{
		int i = 1;
		string newtitle = title + "(" + to_string(i) + ")";
		while (notelist.IsExistedNote(newtitle))
		{
			i++;
			newtitle = title + "(" + to_string(i) + ")";
		}
		title = newtitle;
	}
	Note  newNote(title, detail);
	for (auto it = tags.begin(); it != tags.end(); it++)
		newNote.setTag(*it);
	notelist.AddANote(newNote);
	notelist.AddNoteName(title);
	for (size_t i = 0; i < tags.size(); i++)
	{
		int position = taglist.IsExistedTag(tags[i]);
		if (position != -1)
		{
			
			taglist.getTagAddress(position)->addRelatedNote(newNote);
		}
		else
		{
			Tag tag(tags[i]);
			tag.addRelatedNote(newNote);
			taglist.addTag(tag);
			taglist.addTagName(tags[i]);
		}
	}
	Save(newNote);
	helper.ConvertLower(detail);
	vector<string>vt;
	map<string, int>m;
	helper.wordTokenizer(detail, vt, m);
	inverted.addNewFile(title, vt, m);
}
void Method::Save(Note note)
{
	Helper helper;
	helper.saveNoteFile(note);
	helper.saveNotetoList(note);
}
void Method::DeleteTag(TagList& taglist, int index)
{
	Helper helper;
	Tag *tag = taglist.getTagAddress(index);
	string name = tag->getName();
	for (int i = 0; i < tag->getRelatedNoteSize(); i++)
	{
		Note *note = tag->getRelatedNoteAddress(i);
		note->RemoveTagInNote(name);
		helper.saveNoteFile(*note);
	}
	taglist.RemoveTag(index);
}
void Method::DeleteNote(NoteList& notelist, TagList &taglist, int index, InvertedIndex &inverted)
{
	Helper helper;
	Note* note = notelist.getNoteAddress(index);
	string name = note->getTitle();
	for (int i = 0; i < note->getNumofTag(); i++)
	{
		string tagname = note->getTag(i);
		int index = taglist.IsExistedTag(tagname);
		if (index != -1) taglist.getTagAddress(index)->RemoveNoteInTag(name);
	}
	notelist.RemoveNote(index);
	helper.saveNoteList(notelist);
	bool isok = remove(("Note//" + name + ".txt").c_str());
	inverted.addDeletedNote(name);
}
void Method::Search(InvertedIndex inverted, NoteList notelist, string key)
{
	inverted.SearchFile(key);
}
