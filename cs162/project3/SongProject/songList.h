#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

//constants
const int CAP_SIZE = 100;
//class data type for the VideoList object
class SongList
{
private:
	Song list[CAP_SIZE];
	int size;
public:
	//constructor
	SongList();
	SongList(const char fileName[]);
	//destructor
	~SongList();
	//other list functions
	bool addASong(Song &aSong);
	const void displayList();
	const void findSong();
	void delSong();
	void writeFile();
};

#endif