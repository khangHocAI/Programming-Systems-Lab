#include"Helper.h"

void Helper::saveNoteFile(Note note)
{
	ofstream fout;
	fout.open("Note//" + note.getTitle() + ".txt");
	fout << "Tags: ";
	int t = note.getNumofTag();
	if (t > 0)
	{
		for (int i = 0; i < t - 1; i++)
			fout << note.getTag(i) << ", ";
		fout << note.getTag(t - 1) << endl;
	}
	else fout << endl;
	fout << note.getDetail();
	fout.close();
}
void Helper::saveNotetoList(Note note)
{
	ofstream fout2;
	fout2.open("NoteList.txt", ios::app);
	fout2 << note.getTitle() << endl;
	fout2.close();
}
void Helper::saveNoteList(NoteList notelist)
{
	ofstream fout;
	fout.open("NoteList.txt");
	for (int i = 0; i < notelist.getlistNotesize();i++)
	{
		fout << notelist.getNoteName(i) << endl;
	}
	fout.close();
}
void Helper::reWriteNoteList(NoteList notelist)
{
	ofstream fout;
	fout.open("NoteList.txt");
	int t = notelist.getlistNotesize();
	for (int i = 0; i < t; i++)
	{
		fout << notelist.getNoteName(i) << endl;
	}
	fout.close();
}
void Helper::gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
bool Helper::getAllNoteTitle(vector<string>& v)
{
	ifstream fin;
	fin.open("NoteList.txt");
	if (!fin.is_open()) return false;
	while (!fin.eof())
	{
		string data;
		getline(fin, data);
		if (data.size() >= 1) v.push_back(data);
	}
	fin.close();
	if (v.empty()) return false;
	return true;
}
vector<string> Helper::TagTokenizer(string data)
{
	vector<string>v;
	int startPos = 6;
	size_t foundPos;
	foundPos = data.find(", ",startPos);
	while (foundPos != string::npos)
	{
		int count = foundPos - startPos;
		string t = data.substr(startPos, count);
		v.push_back(t);
		startPos = foundPos + 2;
		foundPos = data.find(", ",startPos);
	}
	int count = data.length() - startPos;
	string t = data.substr(startPos, count);
	if (t.size() > 0)
		v.push_back(t);
	return v;
}
bool Helper::readEachNote(string name, NoteList & notelist, TagList & taglist, InvertedIndex& inverted)
{
// Cau truc file text
// Tags:A,B,C...
//	Detail......
	ifstream fin;
	fin.open("Note//" + name + ".txt");
	if (!fin.is_open()) return false;
	string data;
	getline(fin, data); //read Tags.
	if (data == "") return false;
	vector<string>v = TagTokenizer(data);
	string detail = "";
	while (!fin.eof())
	{
		string x;
		getline(fin, x);
		if (x.size() >= 1) detail += x + "\n";
	}
	fin.close();
	Note newNote(name, detail);
	for (auto it = v.begin(); it != v.end(); it++)
		newNote.setTag(*it);
	notelist.AddANote(newNote);
	notelist.AddNoteName(name);
	for (size_t i = 0; i < v.size(); i++)
	{
		int position = taglist.IsExistedTag(v[i]);
		if (position != -1)
		{
			taglist.getTagAddress(position)->addRelatedNote(newNote);
		}
		else
		{
			Tag tag(v[i]);
			tag.addRelatedNote(newNote);
			taglist.addTag(tag);
			taglist.addTagName(v[i]);
		}
	}
	ConvertLower(detail);
	vector<string>vt;
	map<string, int>m;
	wordTokenizer(detail, vt, m);
	inverted.addNewFile(name, vt, m);
	return true;
}
string Helper::inputData(char* p)
{
	vector<pair<int, int>> EnterPosition;
	int i = 0;
	char a;//a Temp char
	while (1)//infinite loop
	{
		a = _getch();//stores char typed in a
		if ((a >= 32 && a <= 126))
			//check if a is numeric or alphabet
		{
			p[i] = a;//stores a in pass
			++i;
			cout << a;
		}
		if (a == 13)
		{
			int x = Helper::wherex();
			int y = Helper::wherey();
			EnterPosition.push_back({ x,y });
			p[i] = '\n';
			++i;
			cout << "\n";
		}
		if (a == '\b' && i >= 1)//if user typed backspace
			//i should be greater than 1.
		{
			if (p[i-1] != '\n')
			{
				cout << "\b \b";//rub the character behind the cursor.
				--i;
			}
			else
			{
				gotoxy(EnterPosition[EnterPosition.size() - 1].first, EnterPosition[EnterPosition.size() - 1].second);
				EnterPosition.pop_back();
				--i;
			}
		}
		if (a == 27 || i == 999)//if enter is pressed
		{
			p[i] = '\0';//null means end of string.
			cout << endl;
			break;//break the loop
		}
	}
	string t = p;
	return t;
}
int Helper::wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int Helper::wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}
bool Helper::checkNumber(string data, int n, int&trans)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] < 48 || data[i] > 58) return false;
	}
	int num = stoi(data);
	if (num > n) return false;
	trans = num;
	return true;
}

void Helper::ConvertLower(string& data)
{
	for_each(data.begin(), data.end(), [](char& c)
		{
			c = ::tolower(c);
		});
}

void Helper::wordTokenizer(string data, vector<string>&v, map<string, int> &m)
{
	string word = "";
	for (size_t i = 0; i < data.length(); i++) // vi dua ve chu thuong het nen ko con chu hoa
	{
		if ((data[i] > 47 && data[i] < 58) || (data[i] > 96 && data[i] < 123))
		{
			word += data[i];
		}
		else
		{
			if (word.size() != 0)
			{
				if (m.find(word) == m.end())
				{
					m[word] = 1;
					v.push_back(word);
				}
				else 
					m[word]++;
				word = "";
			}
		}
	}
}
