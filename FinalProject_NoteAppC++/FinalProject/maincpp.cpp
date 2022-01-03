#include"Note.h"
#include"Tag.h"
#include"Method.h"
#include"Screen.h"
#include"Helper.h"
#include"InvertedIndex.h"
int main()
{
	
	InvertedIndex inverted;
	NoteList notelist;
	TagList taglist;
	Method method;
	bool isOk = method.Load(notelist, taglist, inverted);
	Screen screen;
	screen.Menu(notelist,taglist,inverted);
	
	
	
	return 0;
}