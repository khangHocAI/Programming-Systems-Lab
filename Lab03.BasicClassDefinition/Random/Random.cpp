#include"Random.h"

Random::Random()
{
	try
	{
		srand(time(0));
	}
	catch (exception &ex)
	{
		cout << ex.what();
	}
}
string Random::toString()
{
	stringstream ss;
	ss << next();
	return ss.str();
}
int Random::next()
{
	return rand();
}
int Random::next(int value)
{
	return rand()%(value+1);
}