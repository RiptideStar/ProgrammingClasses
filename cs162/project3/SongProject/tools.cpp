#include "tools.h"

//Function implementations


//displays the menu
void displayMenu()
{
	cout << "Welcome to Kyle's Song Workshop:" << endl << endl;
	cout << "Pick an option" << endl;
	cout << "(a): Add a Song" << endl;
	cout << "(d): Display the List" << endl;
	cout << "(f): Find a song by artist" << endl;
	cout << "(r): Delete a song" << endl;
	cout << "(q): Quit" << endl;
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
void exeCmd(char option, SongList &list)
{
	Song aSong;
	switch (tolower(option))
	{
	case 'a':
		populateSongFromUser(aSong);
		if (list.addASong(aSong))
		{
			cout << "Movie added!" << endl;
		}
		else
		{
			cout << "Duplicate title! Movie not added!" << endl;
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
	cin.get(name, MAX_CHARS, '\n');
	cin.ignore(100, '\n');

    cout << "Enter an artist for the song: ";
    cin.get(artist, MAX_CHARS, '\n');
	cin.ignore(100, '\n');

	cout << "Enter the minute value for the song (will later ask for seconds value): ";
	min = getInt();

    cout<< "Enter the seconds value for the song: ";
    sec = getInt();

	cout << "Enter the album for the song: ";
	cin.get(album, MAX_CHARS, '\n');
	cin.ignore(100, '\n');

	//populate aVideo
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