#include "song.h"

//default constructor
Song::Song()
{
	strcpy(name, "No particular Name");
	strcpy(artist, "No particular artist");
    min = 0;
    sec = 0;
	strcpy(album, "No particular Album");
}

//constructor with parameters
Song::Song(char initName[], char initArtist[], int initMin, int initSec, char initAlbum[])
{
	strcpy(name, initName);
    strcpy(artist, initArtist);
    min = initMin;
    sec = initSec;
	strcpy(album, initAlbum);
}

//accessor and mutator functions
//accessor functions
const void Song::getName(char targetName[])
{
	strcpy(targetName, name);
}
const void Song::getArtist(char targetArtist[]) {
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
const void Song::getAlbum(char targetAlbum[]) {
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
	cout << name << DELIMITER << artist << DELIMITER << min << DELIMITER << sec << DELIMITER << album << endl;
}

//print function to file
const void Song::printFile(ofstream &outFile)
{
	outFile << name << DELIMITER << artist << DELIMITER << min << DELIMITER << sec << DELIMITER << album << endl;
}