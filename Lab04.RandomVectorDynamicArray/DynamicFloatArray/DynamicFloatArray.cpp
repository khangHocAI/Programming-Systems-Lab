#include"DynamicFloatArray.h"
DynamicArray::DynamicArray()
{
	_a = new float[INITIAL_SIZE];
	_length = 0;
	_maxsize = INITIAL_SIZE;
}
DynamicArray::~DynamicArray()
{
	delete[]_a;
}
void DynamicArray::push_back(float element)
{
	if (_length == _maxsize)
	{
		float *tmp = _a;
		_maxsize += SIZE_INCREASE_STEP;
		_a = new float[_maxsize];
		for (int i = 0; i < _length; i++)
			_a[i] = tmp[i];
		delete[]tmp;

	}
	_a[_length++] = element;
}
float DynamicArray::operator[](int index)
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