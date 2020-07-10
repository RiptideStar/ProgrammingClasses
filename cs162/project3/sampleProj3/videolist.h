#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "video.h"
//constants
const int CAP = 100;
//class data type for the VideoList object
class VideoList
{
private:
	Video list[CAP];
	int size;
public:
	//constructor
	VideoList();
	VideoList(const char fileName[]);
	//destructor
	~VideoList();
	//other list functions
	bool addVideo(Video &aVideo);
	const void displayList();
	const void findVideo();
	void delVideo();
	void writeFile();
};

#endif
