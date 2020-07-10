//This is the implementation file for tools.h
#include "tools.h"

//Function implementations


//displays the menu
void displayMenu()
{
	cout << "Welcome to the VideoStore:" << endl << endl;
	cout << "Pick an option" << endl;
	cout << "[A-a]: Add a movie" << endl;
	cout << "[D-d]: Display the List" << endl;
	cout << "[F-f]: Find a movie" << endl;
	cout << "[R-r]: Delete a movie" << endl;
	cout << "[Q-q]: Quit" << endl;
}

//read the option from the user
char readOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//execute the option
void exeCmd(char option, VideoList &store)
{
	Video aVideo;
	switch (tolower(option))
	{
	case 'a':
		populateVideoFromUser(aVideo);
		if (store.addVideo(aVideo))
		{
			cout << "Movie added!" << endl;
		}
		else
		{
			cout << "Duplicate title! Movie not added!" << endl;
		}

		break;
	case 'd':
		store.displayList();
		break;
	case 'r':
		store.delVideo();
		break;
	case 'f':
		store.findVideo();
		break;
	case 'q':
		store.writeFile();
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int readInt()
{
	int temp = 0;
	cin >> temp;
	//data validation
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> temp;
	}
	cin.ignore(100, '\n');

	return temp;
}

//standalone overloaded addVideo function
//populate aVideo from the user
void populateAVideoFromUser(Video &aVideo)
{
        char tempTitle[MAXCHAR];
	int tempQty = 0;
	char tempGenre[MAXCHAR];
	cout << "Enter a movie name:";
	cin.get(tempTitle, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter Quantity:";
	tempQty = readInt();
	cout << "Enter movie genre:";
	cin.get(tempGenre, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	//populate aVideo
	aVideo.setTitle(tempTitle);
	aVideo.setQty(tempQty);
	aVideo.setGenre(tempGenre);
}

//converts all text to upper case
void convertCase(char tempStr[])
{
	//for(int i = 0; tempStr[i] != '\0'; i++)

	for (int i = 0; i < strlen(tempStr); i++)
	{
		tempStr[i] = toupper(tempStr[i]);
	}
}
