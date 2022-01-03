#include"Screen.h"

void Screen::Menu(NoteList& notelist, TagList &taglist, InvertedIndex& inverted)
{
	Helper helper;
	system("cls");
	helper.gotoxy(30, 3);
	cout << "NOTE TAKING APP:";
	helper.gotoxy(50, 4);
	cout << "AUTHOR: N.H.Khang";
	helper.gotoxy(25, 6);
	cout << "1. Add new note.";
	helper.gotoxy(25, 7);
	cout << "2. View.";
	helper.gotoxy(25, 8);
	cout << "3. Delete.";
	helper.gotoxy(25, 9);
	cout << "4. Search.";
	helper.gotoxy(25, 10);
	cout << "5. Exit.";
	helper.gotoxy(30, 12);
	cout << "Please choose: ";
	string n;
	helper.gotoxy(45, 12);
	cin >> n;
	while (n.size() != 1 || n[0] < 49 || n[0] >53)
	{
		helper.gotoxy(45, 12);
		cout << "                     ";
		helper.gotoxy(45, 12);
		cin >> n;
	}
	switch (n[0])
	{
	case '1': AddScreen(notelist, taglist, inverted); break;
	case '2': ViewScreen(notelist, taglist,inverted); break;
	case '3': DeleteScreen(notelist, taglist,inverted); break;
	case '4': SearchScreen(notelist, taglist,inverted); break;
	default: ExitScreen();
		break;
	}
}
void Screen::AddScreen(NoteList& notelist, TagList& taglist, InvertedIndex& inverted)
{
	Helper helper;
	system("cls");
	helper.gotoxy(15, 8);
	cout << "CREATE NEW NOTE (+++):";
	string title, tag, detail = "";
	pair<int, int>TagsPosition; // dung de dien tag vao tren man hinh
	vector<string>tags;
	helper.gotoxy(10, 11);
	cout << "TITLE: ";
	helper.gotoxy(10, 13);
	cout << "TAGS:";
	TagsPosition = { 20, 13 };
	helper.gotoxy(5, 15);
	cout << "DETAIL: Maximum 1000 characters  (Press esc to finish)";
	helper.gotoxy(17, 11);
	getline(cin, title);
	while (title.size() < 1) getline(cin, title);
	helper.gotoxy(3,16);
	while (detail.size() < 1)
	{
		char* p = new char[1000];
		detail = helper.inputData(p);
		delete []p;
	}
	string n;
	AddTagScreen(n);
	while (n[0] == 49)
	{
		helper.gotoxy(75, 3);
		cout << "Tags:                          ";
		helper.gotoxy(81, 3);
		while (tag.size()<1) getline(cin, tag);
		tags.push_back(tag);
		int x = TagsPosition.first;
		int y = TagsPosition.second;
		helper.gotoxy(x,y);
		if (x == 20) cout << tag;
		else cout << ", " << tag;
		x = helper.wherex();
		y = helper.wherey();
		TagsPosition = { x,y };
		helper.gotoxy(75, 3);
		cout << "                               ";
		tag = "";
		AddTagScreen(n);
	}
	Method method;
	if (n[0] == 50)	method.Add(title, detail, tags, notelist, taglist, inverted);
	Menu(notelist, taglist,inverted);
}
void AddTagScreen(string& n)
{
	Helper helper;
	helper.gotoxy(50, 1);
	cout << "**************";
	helper.gotoxy(50, 2);
	cout << "*1. Add Tag. *";
	helper.gotoxy(50, 3);
	cout << "*2. Save.    *";
	helper.gotoxy(50, 4);
	cout << "*3. Exit.    *";
	helper.gotoxy(50, 5);
	cout << "**************";
	helper.gotoxy(50, 6);
	cout << "Please choose:        ";
	helper.gotoxy(65, 6);
	cin >> n;
	while (n.size() != 1 || n[0] < 49 || n[0] >51)
	{
		helper.gotoxy(65, 6);
		cout << "                     ";
		helper.gotoxy(65, 6);
		cin >> n;
	}
}
void Screen::ViewScreen(NoteList notelist, TagList taglist, InvertedIndex inverted)
{
	system("cls");
	Helper helper;
	helper.gotoxy(5, 4);
	cout << "*************************";
	helper.gotoxy(5, 5);
	cout << "*  1. View all tags     *";
	helper.gotoxy(5, 6);
	cout << "*  2. View a note.      *";
	helper.gotoxy(5, 7);
	cout << "*  3. Exit.             *";
	helper.gotoxy(5, 8);
	cout << "*************************";
	helper.gotoxy(8, 9);
	cout << "Please choose: ";
	helper.gotoxy(25, 9);
	string n;
	cin >> n;
	while (n.size() != 1 || n[0] < 49 || n[0] >51)
	{
		helper.gotoxy(25, 9);
		cout << "                   ";
		helper.gotoxy(25, 9);
		cin >> n;
	}
	if (n == "1")
	{	
		int index;
		ViewTagScreen(notelist, taglist, index);
		if (index == taglist.getlistTagsize() + 1) Menu(notelist, taglist,inverted);
		else ViewRelatedNoteScreen(notelist, taglist, index,inverted);
	}
	else if (n == "2")
	{
		ViewNoteScreen(notelist,taglist,inverted);
	}
	Menu(notelist, taglist, inverted);
}
void Screen::ViewTagScreen(NoteList notelist, TagList taglist, int &index)
{
	Helper helper;
	helper.gotoxy(55, 4);
	cout << "LIST OF EXISTED TAGS:";
	int i = 0;
	for (; i < taglist.getlistTagsize(); i++)
	{
		helper.gotoxy(50, 6 + i);
		cout << i + 1 << ". " << taglist.getTagName(i);
	}
	helper.gotoxy(50, 6 + i);
	cout << i + 1 << ".**** <GO BACK>****" ;
	int num = i + 1;
	helper.gotoxy(55, 6 + i + 2);
	cout << "Please choose: ";
	helper.gotoxy(70, 6 + i + 2);
	string input;
	cin >> input;
	while (input.size() < 1 || !helper.checkNumber(input, num, index))
	{
			helper.gotoxy(70, 6 + i + 2);
			cout << "                 ";
			helper.gotoxy(70, 6 + i + 2);
			cin >> input;
	}
}
void Screen::ViewRelatedNoteScreen(NoteList notelist, TagList taglist, int index, InvertedIndex inverted)
{
	Helper helper;
	system("cls");
	Tag tag = taglist.getTag(index-1);
	helper.gotoxy(40, 6);
	cout << "RELATED NOTES TO " << tag.getName() << ":";
	int size = tag.getRelatedNoteSize();
	int count = 0;
	int i = 0;
	for (i; i< size; i++)
	{
		Note note = tag.getRelatedNote(i);
		helper.gotoxy(35, 7 + count);
		cout << i + 1 << ". " << note.getTitle();
		helper.gotoxy(30, 8 + count);
		cout << note.get76Character() << endl;
		count += 2;
	}
	int num = i + 1;
	helper.gotoxy(35, 7 + count);
	cout << i + 1 << ".**** <GO BACK>****";
	helper.gotoxy(10, 2);
	cout << "Please choose:";
	helper.gotoxy(26, 2);
	string n;
	cin >> n;
	int trans;
	while (n.size() != 1 || !helper.checkNumber(n, i+1,trans))
	{
		helper.gotoxy(26, 2);
		cout << "                   ";
		helper.gotoxy(26, 2);
		cin >> n;
	}
	if (trans == num) ViewScreen(notelist, taglist,inverted);
	Note note = tag.getRelatedNote(trans - 1);
	ViewNoteScreenFromTag(notelist, taglist, note, index,inverted);
}
void Screen::DisplayNote(Note note)
{
	Helper helper;
	system("cls");
	helper.gotoxy(30, 4);
	cout << note.getTitle();
	helper.gotoxy(20, 6);
	cout << "Tags: ";
	int t = note.getNumofTag();
	for (int i = 0; i < t - 1; i++)
		cout << note.getTag(i) << ", ";
	cout << note.getTag(t - 1);
	helper.gotoxy(5, 8);
	cout << note.getDetail();
	helper.gotoxy(20, 2);
	system("pause");
}
void Screen::DisplayNoteList(NoteList notelist)
{
	system("cls");
	Helper helper;
	helper.gotoxy(50, 4);
	cout << "LIST OF EXISTED NOTES: ";
	int i = 0;
	for (; i < notelist.getlistNotesize(); i++)
	{
		helper.gotoxy(45, 6 + i);
		cout << i + 1 << ". " << notelist.getNoteName(i);
	}
	helper.gotoxy(45, 6 + i);
	cout << i + 1 << ".**** <GO BACK>****";
	helper.gotoxy(50, 6 + i + 2);
	cout << "Please choose: ";
	helper.gotoxy(67, 6 + i + 2);
}
void Screen::ViewNoteScreenFromTag(NoteList notelist, TagList taglist,Note note, int index, InvertedIndex inverted)
{
	DisplayNote(note);
	ViewRelatedNoteScreen(notelist, taglist ,index,inverted);
}
void Screen::ViewNoteScreen(NoteList notelist, TagList taglist, InvertedIndex inverted)
{
	Helper helper;
	DisplayNoteList(notelist);
	string input;
	cin >> input;
	int index;
	int num = notelist.getlistNotesize() + 1;
	while (input.size() < 1 || !helper.checkNumber(input, num, index))
	{
		helper.gotoxy(67, 6 + num + 1);
		cout << "                 ";
		helper.gotoxy(67, 6 + num + 1);
		cin >> input;
	}
	if (index == num) ViewScreen(notelist, taglist,inverted);
	else
	{
		Note note = notelist.getNote(index - 1);
		DisplayNote(note);
		ViewNoteScreen(notelist, taglist,inverted);
	}
}
void Screen::DeleteScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted)
{
	Helper helper;
	system("cls");
	helper.gotoxy(5, 4);
	cout << "*************************";
	helper.gotoxy(5, 5);
	cout << "*  1. Delete tag.       *";
	helper.gotoxy(5, 6);
	cout << "*  2. Delete note.      *";
	helper.gotoxy(5, 7);
	cout << "*  3. Exit.             *";
	helper.gotoxy(5, 8);
	cout << "*************************";
	helper.gotoxy(8, 9);
	cout << "Please choose: ";
	helper.gotoxy(25, 9);
	string n;
	cin >> n;
	while (n.size() != 1 || n[0] < 49 || n[0] >51)
	{
		helper.gotoxy(25, 9);
		cout << "                   ";
		helper.gotoxy(25, 9);
		cin >> n;
	}
	if (n == "1")
	{
		DeleteTagScreen(notelist, taglist,inverted);
	}
	else if (n == "2")
	{
		DeleteNoteScreen(notelist, taglist,inverted);
	}
	Menu(notelist, taglist,inverted);
}
void Screen::DeleteTagScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted)
{
	int index;
	Helper helper;
	
	ViewTagScreen(notelist, taglist, index);
	if (index < taglist.getlistTagsize() + 1)
	{
		string tagname = taglist.getTagName(index - 1);
		Method method;
		method.DeleteTag(taglist, index - 1);
		system("cls");
		helper.gotoxy(40, 10);
		cout << "SUCCESSFULLY REMOVE TAG " << tagname;
		helper.gotoxy(30, 11);
		system("pause");
	}
	DeleteScreen(notelist, taglist, inverted);
}
void Screen::DeleteNoteScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted)
{
	Helper helper;
	DisplayNoteList(notelist);
	string input;
	cin >> input;
	int index;
	int num = notelist.getlistNotesize() + 1;
	while (input.size() < 1 || !helper.checkNumber(input, num, index))
	{
		helper.gotoxy(67, 6 + num + 1);
		cout << "                 ";
		helper.gotoxy(67, 6 + num + 1);
		cin >> input;
	}
	if (index < num) 
	{
		Note note = notelist.getNote(index - 1);
		Method method;
		method.DeleteNote(notelist,taglist, index - 1,inverted);
		
		system("cls");
		helper.gotoxy(40, 10);
		cout << "SUCCESSFULLY REMOVE NOTE " << note.getTitle();
		helper.gotoxy(30, 11);
		system("pause");
	}
	DeleteScreen(notelist, taglist,inverted);
	
}
void Screen::SearchScreen(NoteList notelist, TagList taglist, InvertedIndex inverted)
{
	Helper helper;
	system("cls");
	helper.gotoxy(5, 5);
	cout << "***********SEARCH BY KEYWORD****************";
	helper.gotoxy(10,8);
	cout << "Enter word here: ";
	string key;
	getline(cin, key);
	while (key.size() <1) getline(cin, key);
	Method method;
	method.Search(inverted, notelist, key);
	system("pause");
	Menu(notelist, taglist, inverted);
}
void Screen::ExitScreen()
{
	Helper helper;
	system("cls");
	helper.gotoxy(20, 10);
	cout << "THANKS FOR USING OUR APP. SEE YA!!!";
	Sleep(1500);
	ExitProcess(0);
}