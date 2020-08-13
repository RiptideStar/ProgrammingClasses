/*
Kyle Zhang
CS162 Project 4
*/

#include "tools.h"
#include <cstring>
#include <cstdlib>

int main()
{
	//instantiate list object and then feed in the file to read
	SongList LinkedList("songs.txt");
	char op;
	cout << "Welcome to Kyle's Song Workshop:" << endl;
	do
	{
		displayMenu();
		op = readCharOption();
		exeCmd(op, LinkedList);
	} while (tolower(op) != 'q');

	return 0;
}