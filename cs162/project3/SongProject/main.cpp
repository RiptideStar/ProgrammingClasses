#include "tools.h"
#include <cstring>
#include <cstdlib>
//main
int main()
{
	//create the list object
	SongList list("movies.txt");
	char option;
	//display the menu
	do
	{
		displayMenu();
		option = readCharOption();
		exeCmd(option, list);
	} while (tolower(option) != 'q');

	return 0;
}