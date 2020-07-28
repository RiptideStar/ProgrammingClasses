#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//constants
const int MAX_CHARS = 101;
const char DELIMITER = ';';

//Class data type for the Video object
class Song
{
private:
    char* name;
    char* artist;
    int min;
    int sec;
    char* album;
public:
    //constructors
    Song();
    Song(char initName[], char initArtist[], int initMin, int initSec, char initAlbum[]);
    //deconstructor
    ~Song();
    //setters and getters functions
    const void getName(char targetName[]);
    const void getArtist(char targetArtist[]);
    const int getMin();
    const int getSec();
    const void getAlbum(char targetAlbum[]);
    void setName(char newName[]);
    void setArtist(char newArtist[]);
    void setMin(int newMin);
    void setSec(int newSec);
    void setAlbum(char newAlbum[]);
    //print function
    const void printSong();
    const void printFile(ofstream &outFile);
};
#endif