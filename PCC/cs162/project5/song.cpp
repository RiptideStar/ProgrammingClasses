#include "song.h"

//default constructor
Song::Song()
{
	name = NULL;
	artist = NULL;
	min = 0;
	sec = 0;
	album = NULL;
}

//constructor with parameters
Song::Song(char *initName, char *initArtist, int initMin, int initSec, char *initAlbum)
{
	name = new char[strlen(initName) + 1];
	artist = new char[strlen(initArtist) + 1];
	album = new char[strlen(initAlbum) + 1];

	strcpy(name, initName);
	strcpy(artist, initArtist);
	min = initMin;
	sec = initSec;
	strcpy(album, initAlbum);
}

//copy constructor and assignment operator overload
Song::Song(Song &song2)
{
	if (name)
		delete[] name;
	if (artist)
		delete[] artist;
	if (album)
		delete[] album;

	char buffer[MAX_CHARS];
	song2.getName(buffer);
	name = new char[strlen(buffer) + 1];
	strcpy(name, buffer);

	song2.getArtist(buffer);
	artist = new char[strlen(buffer) + 1];
	strcpy(artist, buffer);

	song2.getAlbum(buffer);
	album = new char[strlen(buffer) + 1];
	strcpy(album, buffer);

	min = song2.getMin();
	sec = song2.getSec();
}

void Song::operator=(Song &song2) {
	if (name)
		delete[] name;
	if (artist)
		delete[] artist;
	if (album)
		delete[] album;

	char buffer[MAX_CHARS];
	song2.getName(buffer);
	name = new char[strlen(buffer) + 1];
	strcpy(name, buffer);

	song2.getArtist(buffer);
	artist = new char[strlen(buffer) + 1];
	strcpy(artist, buffer);

	song2.getAlbum(buffer);
	album = new char[strlen(buffer) + 1];
	strcpy(album, buffer);

	min = song2.getMin();
	sec = song2.getSec();
}

//accessor and mutator functions
//accessor functions
const void Song::getName(char targetName[])
{
	strcpy(targetName, name);
}
const void Song::getArtist(char targetArtist[])
{
	strcpy(targetArtist, artist);
}
const int Song::getMin()
{
	return min;
}
const int Song::getSec()
{
	return sec;
}
const void Song::getAlbum(char targetAlbum[])
{
	strcpy(targetAlbum, album);
}

//mutator functions
void Song::setName(char newName[])
{
	if (name != NULL)
		delete[] name;
	name = new char[(int)strlen(newName) + 1];
	strcpy(name, newName);
}
void Song::setArtist(char newArtist[])
{
	if (artist != NULL)
		delete[] artist;
	artist = new char[(int)strlen(newArtist) + 1];
	strcpy(artist, newArtist);
}
void Song::setMin(int newMin)
{
	min = newMin;
}
void Song::setSec(int newSec)
{
	sec = newSec;
}
void Song::setAlbum(char newAlbum[])
{
	if (album != NULL)
		delete[] album;
	album = new char[(int)strlen(newAlbum) + 1];
	strcpy(album, newAlbum);
}

//deconstructor
Song::~Song()
{
	delete[] name;
	delete[] artist;
	delete[] album;
}

//print function to screen
const void Song::printSong()
{
	if (sec < 10)
		cout << name << DELIMITER << artist << DELIMITER << min << DELIMITER << "0" << sec << DELIMITER << album << endl;
	else
	{
		cout << name << DELIMITER << artist << DELIMITER << min << DELIMITER << sec << DELIMITER << album << endl;
	}
}

//print function to file
const void Song::printFile(ofstream &outFile)
{
	if (sec < 10)
		outFile << name << DELIMITER << artist << DELIMITER << min << DELIMITER << "0" << sec << DELIMITER << album << endl;
	else
		outFile << name << DELIMITER << artist << DELIMITER << min << DELIMITER << sec << DELIMITER << album << endl;
}