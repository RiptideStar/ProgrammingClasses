#include "tools.h"

//Function implementations

//displays the menu
void displayMenu()
{
	cout << endl;
	cout << "Pick an option" << endl;
	cout << "(a): Add a Song" << endl;
	cout << "(d): Display the List" << endl;
	cout << "(f): Find a song by artist" << endl;
	cout << "(r): Delete a song" << endl;
	cout << "(q): Quit" << endl;
}

//read the option from the user
char readCharOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//execute the option
void exeCmd(char option, SongList &list)
{
	Song aSong;
	switch (tolower(option))
	{
	case 'a':
		populateSongFromUser(aSong);
		if (list.addASong(aSong))
		{
			cout << "Song added!" << endl;
		}
		else
		{
			cout << "Duplicate Song! Song not added!" << endl;
		}
		break;
	case 'd':
		list.displayList();
		break;
	case 'r':
		list.delSong();
		break;
	case 'f':
		list.findSong();
		break;
	case 'q':
		list.writeFile();
		break;
	default:
		cout << "Illegal input, please try again!" << endl;
	}
}

//Returns an int from user input, with error check
int getInt()
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

int getIntAboveMinimum(int min)
{
	int num;

	num = getInt();
	while (num < min)
	{
		cout << "The number must not be less than " << min
			 << endl;
		cout << "Please try again: ";
		num = getInt();
	}
	return num;
}

int getIntInRange(int min, int max)
{
	int num;

	num = getInt();
	while (num < min || num > max)
	{
		cout << "The number must be between (inclusive) " << min << " and " << max
			 << endl;
		cout << "Please try again: ";
		num = getInt();
	}
	return num;
}

/* 
Puts input string into string[] and also returns the size of the string
*/
int getStringAndSize(char string[], int maxChars) {
	getString(string, maxChars);
	return strlen(string) + 1; //there will be a '\0' char at the end, to add to the "length"
}

void getString(char string[], int maxChars)
{
	cin.get(string, maxChars, '\n');
	while (!cin)
	{
		cin.clear();
		cin.ignore(maxChars, '\n');

		cout << "You forgot to enter in something! Please try again: ";
		cin.get(string, maxChars, '\n');
	}
	cin.ignore(maxChars, '\n');
}

//fill out a song (parameterized) upon user interaction
void populateSongFromUser(Song &aSong)
{
	char name[MAX_CHARS];
	char artist[MAX_CHARS];
	int min = 0;
	int sec = 0;
	char album[MAX_CHARS];

	//User Interaction
	cout << "Enter a name of the song: ";
	int nameLen = getStringAndSize(name, MAX_CHARS); //	TODO

	cout << "Enter an artist for the song: ";
	int artistLen = getStringAndSize(artist, MAX_CHARS); // TODO

	cout << "Enter the minute value for the song (will later ask for seconds value): ";
	min = getIntAboveMinimum(0);

	cout << "Enter the seconds value for the song: ";
	sec = getIntInRange(0, 59);

	cout << "Enter the album for the song: ";
	getString(album, MAX_CHARS);

	//populate aSong
	aSong.setName(name);
	aSong.setArtist(artist);
	aSong.setMin(min);
	aSong.setSec(sec);
	aSong.setAlbum(album);
}

//converts string to uppercase
void convertCase(char tempStr[])
{
	for (int i = 0; i < strlen(tempStr); i++)
	{
		tempStr[i] = toupper(tempStr[i]);
	}
}