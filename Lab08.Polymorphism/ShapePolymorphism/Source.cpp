#include"ShapePolymorphism.h"

int main()
{
	srand(time(NULL));
	Random rd;
	int n = rd.MakeRandom(10);
	Shape *s;
	for (int i = 0; i < n; i++)
	{
		int type = rd.MakeRandom(3);
		if (type == 1)
		{
			 Circle c(rd.MakeRandom());
			 s = &c;
			 s->print();
			 cout << " - " << s->perimeter() << " - " << s->area() << endl;
			
		}
		else if (type == 2)
		{
			Triangle t(rd.MakeRandom(), rd.MakeRandom());
			s = &t;
			s->print();
			cout << " - " << s->perimeter() << " - " << s->area() << endl;
		}
		else
		{
			Rectangle r(rd.MakeRandom(), rd.MakeRandom());
			s = &r;
			s->print();
			cout << " - " << s->perimeter() << " - " << s->area() << endl;
		}
	}
	system("pause");
	return 0;
}