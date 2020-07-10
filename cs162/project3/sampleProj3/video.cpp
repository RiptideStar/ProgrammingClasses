//This is the implememtation file for video.h
#include "video.h"

//constructors
//default constructor
Video::Video()
{
	strcpy(title, "No title");
	qty = 0;
	strcpy(genre, "No genre");
}

//constructor with parameters
Video::Video(char initTitle[], int initQty, char initGenre[])
{
	strcpy(title, initTitle);
	qty = initQty;
	strcpy(genre, initGenre);
}

//accessor and mutator functions
//accessor functions
const void Video::getTitle(char returnTitle[])
{
	strcpy(returnTitle, title);
}
const int Video::getQty()
{
	return qty;
}
const void Video::getGenre(char returnGenre[])
{
	strcpy(returnGenre, genre);
}
//mutator functions
void Video::setTitle(char newTitle[])
{
	strcpy(title, newTitle);
}
void Video::setQty(int newQty)
{
	qty = newQty;
}
void Video::setGenre(char newGenre[])
{
	strcpy(genre, newGenre);
}

//print function to screen
const void Video::printVideo()
{
	cout << title << ';' << qty << ';' << genre << endl;
        
}

//print function to file
const void Video::printFile(ofstream &outFile)
{
	outFile << title << ';' << qty << ';' << genre << endl;
}
