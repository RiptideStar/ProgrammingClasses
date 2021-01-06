#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int &size)
{
	//shift everything up
	for (int i = size; i > position; i--)
	{
		intList[i] = intList[i - 1];
	}
	//set position to value
	intList[position] = val;
	//we are incrementing the size of the array
	size++;
	return true;
}

bool remove(int position, int &val, int intList[], int &size)
{
	//check for out-of-bounds
	if (position >= size || position < 0) {
		return false;
	}
	//Decrement Size
	size--;
	//Return the value that will be deleted
	val = intList[position];
	//Shift everything down
	for (int i = position; i < size; i++)
	{
		intList[i] = intList[i + 1];
	}
	//Reset last element to default (I don't think this is necessary, but for aesthetics)
	intList[size] = 0;
	return true;
}

void print(const int intList[], int size)
{
	cout << endl
		 << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}
