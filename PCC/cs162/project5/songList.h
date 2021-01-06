#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

//node for LL capabilities
struct songNode
{
	Song songDat;
	songNode *next;
	songNode *prev;
};

//class data type for the SongList object
class SongList
{
private:
	// Song* list;
	// int size;
	songNode *head;
	songNode *tail;

public:
	//constructor
	SongList();
	SongList(const char fileName[]);
	//destructor
	~SongList();
	//other list functions
	bool addASong(Song &aSong);
	const void displayList();
	const void findSongByArtist();
	const void findSongByAlbum();
	void delSong();
	void writeFile();
};

#endif