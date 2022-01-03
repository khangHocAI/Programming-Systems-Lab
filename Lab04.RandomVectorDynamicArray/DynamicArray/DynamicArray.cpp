#include"DynamicArray.h"
DynamicArray::DynamicArray()
{
	_a = new int[INITIAL_SIZE];
	_length = 0;
	_maxsize = INITIAL_SIZE;
}
DynamicArray::~DynamicArray()
{
	delete[]_a;
}
void DynamicArray::push_back(int element)
{
	if (_length == _maxsize)
	{
		int *tmp = _a;
		_maxsize += SIZE_INCREASE_STEP;
		_a = new int[_maxsize];
		for (int i = 0; i < _length; i++)
			_a[i] = tmp[i];
		delete[]tmp;
		
	}
	_a[_length++] = element;
}
int DynamicArray::operator[](int index)
{
	if (index < _length)
	{
		return _a[index];
	}
	else
	{
		throw runtime_error("Index out of range");
	}
}