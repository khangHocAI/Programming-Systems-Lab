#include"Dice.h"

int main()
{
	srand(time(NULL));
	Dice d;
	int A[3], B[3];
	int Awin = 0, Bwin = 0;
	for (int i = 0; i < 3; i++)
	{
		A[i] = d.Roll();
		cout << "A roll " << A[i] << endl;
		B[i] = d.Roll();
		cout << "B roll " << B[i] << endl;
		if (A[i] > B[i]) Awin++;
		else if (A[i] < B[i]) Bwin++;
	}
	cout << Awin << " - " << Bwin << endl;
	system("pause");
	return 0;
}