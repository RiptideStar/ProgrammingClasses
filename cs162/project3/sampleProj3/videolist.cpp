//This is the implementation file for VideoList class
#include "videolist.h"
#include "tools.h"

//VideoList implementation functions
//default constructor
VideoList::VideoList()
{
	size = 0;
}
//constructor from file
VideoList::VideoList(const char fileName[])
{
	ifstream inFile;
	Video aVideo;
	char tempTitle[MAXCHAR], tempGenre[MAXCHAR];
	int tempQty = 0;
	inFile.open(fileName);
	if (!inFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	size = 0;
	inFile.get(tempTitle, MAXCHAR, ';');
	while (!inFile.eof())
	{
		inFile.ignore(5, ';');
		inFile >> tempQty;
		inFile.ignore(5, ';');
		inFile.get(tempGenre, MAXCHAR, '\n');
		inFile.ignore(5, '\n');
		//populate aVideo with all the information
		aVideo.setTitle(tempTitle);
		aVideo.setQty(tempQty);
		aVideo.setGenre(tempGenre);
		this->addVideo(aVideo);
		inFile.get(tempTitle, MAXCHAR, ';');
	}
	inFile.close();
}

//destructor
VideoList::~VideoList()
{
	//nothing here
}
//adds a video to the list
bool VideoList::addVideo(Video &aVideo)
{
	char tempTitle1[MAXCHAR], tempTitle2[MAXCHAR];
	//insert sorted into the list like lab2
	int i = 0, j = 0;
	//checks for duplicate title
	aVideo.getTitle(tempTitle2);
	for (i = 0; i < size; i++)
	{
		list[i].getTitle(tempTitle1);
		if (strcmp(tempTitle1, tempTitle2) == 0)
			return false;
	}
	//finds the right position
	for (i = 0; i < size; i++)
	{
		list[i].getTitle(tempTitle1);
		if (strcmp(tempTitle1, tempTitle2) > 0)
			break;
	}
	//copies everything one down
	for (j = size; j >= i; j--)
	{
		list[j + 1] = list[j];
	}
	list[i] = aVideo;
	size++;
	return true;
}

//deletes a movie from the list
void VideoList::delVideo()
{
	int selection = 0;
	displayList();
	cout << "Which movie would you like to delete?: ";
	cin >> selection;
	for (int i = selection - 1; i < size; i++)
	{
		list[i] = list[i + 1];
	}
	size--;
	displayList();
}


//prints the list
const void VideoList::displayList()
{       
	int num=0;
	for (int i = 0; i < size; i++)
	{       
                cout << ++num << ". "; 
		list[i].printVideo();
	}
	cout << endl;
}

//finds a movie in the list
const void VideoList::findVideo()
{
	char srchTitle[MAXCHAR], tempTitle[MAXCHAR];
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	convertCase(srchTitle);
	for (int i = 0; i < size; i++)
	{
		list[i].getTitle(tempTitle);
		convertCase(tempTitle);
		if (strstr(tempTitle, srchTitle))
		{
			list[i].printVideo();
		}
	}
	cout << endl;
}

//writes the data back to the file
void VideoList::writeFile()
{
	ofstream outFile;
	outFile.open("movies.txt");
	if (!outFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	for (int i = 0; i < size; i++)
	{
		list[i].printFile(outFile);
	}
	outFile.close();
}
