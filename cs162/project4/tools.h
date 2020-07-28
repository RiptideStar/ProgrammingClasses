#ifndef TOOLS_H
#define TOOLS_h

#include "songList.h"

//function prototypes
int getInt();
int getIntAboveMinimum(int min);
int getIntInRange(int min, int max);
int getStringAndSize(char string[], int maxChars);
void getString(char string[], int maxChars);
void displayMenu();
char readCharOption();
void exeCmd(char option, SongList &list);
void populateSongFromUser(Song &aSong);
void convertCase(char tempStr[]);

#endif