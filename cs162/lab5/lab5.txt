#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char ** names;

	//write code here to allocate memory for at most 10 names
	names = new char*[10];
	
	//write code here to allocate memory and populate the first name as "charlie"
	//it has to be just big enough for "charlie" which is 8 chars including '\0'
	names[0] = new char[8];
	strcpy(names[0], "charlie");

	//write code here to allocate memory and populate the second name as "sarah"
	//it has to be just big enough for "sarah"
	names[1] = new char[6];
	strcpy(names[1], "sarah");
	
	//write code here to print the names
	cout << "First name: " << names[0] << endl;
	cout << "Second name: " << names[1] << endl;

	//write code here to deallocate memory for the names
	delete [] names[0];
	delete [] names[1];
	delete [] names;

	return 0;
}

