email: nhkhang18@apcs.vn
ID: 18125086
Name: Nguyen Huu Khang

***********************
*Implemented function:
** Note.h:
- Class Note:
 + Note(string title, string detail)
 + string getTitle()
 + string getDetail()
 + string get76Character()
 + string getTag(int index)
 + void setTitle(string title)
 + void setDetail(string detail)
 + void setTag(string tag)
 + int getNumofTag() 
 + void RemoveTagInNote(string name)
- Class NoteList:
 + void AddANote(Note newNote)
 + int getlistNotesize()
 + Note getNote(int index)
 + Note* getNoteAddress(int index)
 + string getNoteName(int index)
 + void AddNoteName(string name)
 + bool IsExistedNote(string name)
 + void RemoveNote(int index)
**Tag.h:
- Class Tag:
 + Tag(string data)
 + string getName()
 + int getRelatedNoteSize() 
 + Note getRelatedNote(int index) 
 + Note* getRelatedNoteAddress(int index)
 + void addRelatedNote(Note note)
 + void RemoveNoteInTag(string name)
- Class TagList:
 + void addTag(Tag tag) 
 + Tag getTag(int index)
 + Tag* getTagAddress(int index) 
 + string getTagName(int index) 
 + void addTagName(string name) 
 + int getlistTagsize() 
 + int IsExistedTag(string name)
 + void RemoveTag(int index)
**InvertedIndex.h
- Class word_position:
+ word_position(string name, int val)
+ string getfileName() 
+ int getAppearanceTime()
+ void setfileIndex(string value) 
+ void setAppearanceTime(int value)
-Class InvertedIndex
+ void addNewFile(string name, vector<string>v, map<string, int>m)
+ void SearchFile(string word)
+ void addDeletedFile(string name)
**Method.h
- Class Method
+ bool Load(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
+ void Add(string title, string detail, vector<string>tags, NoteList& notelist, TagList& taglist, InvertedIndex& inverted);
+ void Save(Note note);
+ void DeleteTag(TagList& taglist, int index);
+ void DeleteNote(NoteList& notelist, TagList& taglist, int index);
+ void Search(InvertedIndex inverted, NoteList notelist, string key);
**Screen.h
- Class Screen
+ static void Menu(NoteList & notelist, TagList& taglist, InvertedIndex& inverted);
+ static void AddScreen(NoteList & notelist, TagList& taglist, InvertedIndex& inverted);
+ static void ViewScreen(NoteList notelist, TagList taglist, InvertedIndex inverted);
	.static void ViewTagScreen(NoteList notelist, TagList taglist, int& index);
	.static void ViewRelatedNoteScreen(NoteList notelist, TagList taglist, int index, InvertedIndex inverted);
	.static void ViewNoteScreenFromTag(NoteList notelist, TagList taglist, Note note, int index, InvertedIndex inverted);
	.static void ViewNoteScreen(NoteList notelist, TagList taglist, InvertedIndex inverted);
	.static void DisplayNote(Note note);
	.static void DisplayNoteList(NoteList notelist);
+ static void DeleteScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
	.static void DeleteTagScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
	.static void DeleteNoteScreen(NoteList& notelist, TagList& taglist, InvertedIndex &inverted);
+ static void SearchScreen(NoteList notelist, TagList taglist, InvertedIndex inverted);
+ static void ExitScreen();
**Helper.h
+ void saveNoteFile(Note note);
+ void saveNotetoList(Note note);
+ void saveNoteList(NoteList notelist);
+ void reWriteNoteList(NoteList notelist);
+ void gotoxy(int column, int line);
+ int wherex();
+ int wherey();
+ vector<string> TagTokenizer(string data);
+ bool getAllNoteTitle(vector<string>& v);
+ bool readEachNote(string name, NoteList& notelist, TagList& taglist, InvertedIndex& inverted);
+ string inputData(char* p);
+ bool checkNumber(string data, int n, int &trans);
+ void ConvertLower(string& data);
+ void wordTokenizer(string data, vector<string>& v, map<string, int>& m);


*******************
OOP ASPECT:
Class Note, NoteList, Tag, TagList, word_position, Inverted Index, Helper, Method, Screen
 + NoteList has vector<Note>
 + TagList has vector<Tag>
 + Tag has vector<Note>
 + Inverted Index has map<string, vector<word_position>>
 + Almost all functions are in classes
 + Attributes of each class can't be accessed from the outside.