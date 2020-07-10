#ifndef TOOLS_H
#define TOOLS_h

#include "videolist.h"

//function prototypes
int readInt();
void displayMenu();
char readOption();
void exeCmd(char option, VideoList &store);
void populateVideoFromUser(Video &aVideo);
void convertCase(char tempStr[]);

#endif
