//This is the driver file for sample project 3

#include "tools.h"
#include <cstring>
#include <cstdlib>
//main
int main()
{
	//create the list object
	VideoList store("movies.txt");
	char option;
	//display the menu
	do
	{
		displayMenu();
		option = readOption();
		exeCmd(option, store);
	} while (tolower(option) != 'q');

	return 0;
}
