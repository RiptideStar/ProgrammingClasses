/*
Kyle Zhang
CS162 Project 3

Sources: sampleproject3.tar from d2l server
*/

#include "tools.h"
#include <cstring>
#include <cstdlib>

int main()
{
	//instantiate list object and then feed in the file to read
	SongList list("songs.txt");
	char op;
	cout << "Welcome to Kyle's Song Workshop:" << endl;
	do
	{
		displayMenu();
		op = readCharOption();
		exeCmd(op, list);
	} while (tolower(op) != 'q');

	return 0;
}