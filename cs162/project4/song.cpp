#include "song.h"

//default constructor
Song::Song()
{
	//setting the name to noParticularName
	char noParticularName[] = "No particular Name";
	int lenName = strlen(noParticularName) + 1;
	name = new char[lenName];
	strcpy(name, noParticularName);

	//setting artist to noParticularArtist
	char noParticularArtist[] = "No particular Artist";
	int lenArtist = strlen(noParticularArtist) + 1;
	artist = new char[lenArtist];
	strcpy(artist, noParticularArtist);

	//initializing the int variables min and sec
	min = 0;
	sec = 0;

	//setting album to noParticularAlbum
	char noParticularAlbum[] = "No particular Album";
	int lenAlbum = strlen(noParticularAlbum) + 1;
	album = new char[lenAlbum];
	strcpy(album, noParticularAlbum);
}

//constructor with parameters
Song::Song(char initName[], char initArtist[], int initMin, int initSec, char initAlbum[])
{
	//initializing name
	int lenName = strlen(initName) + 1;
	name = new char[lenName];
	strcpy(name, initName);

	//initializing artist
	int lenArtist = strlen(initArtist) + 1;
	artist = new char[lenArtist];
	strcpy(artist, initArtist);

	//initializing the int variables min and sec
	min = initMin;
	sec = initSec;

	//initializing album
	int lenAlbum = strlen(initAlbum) + 1;
	album = new char[lenAlbum];
	strcpy(album, initAlbum);
}

//deconstructor: deallocate memory
Song::~Song()
{
	delete[] name;
	delete[] artist;
	delete[] album;
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
	strcpy(name, newName);
}
void Song::setArtist(char newArtist[])
{
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
	strcpy(album, newAlbum);
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