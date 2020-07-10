#ifndef TOOLS_H
#define TOOLS_h

#include "songList.h"

//function prototypes
int getInt();
void displayMenu();
char readOption();
void exeCmd(char option, SongList &list);
void populateSongFromUser(Song &aSong);
void convertCase(char tempStr[]);

#endif