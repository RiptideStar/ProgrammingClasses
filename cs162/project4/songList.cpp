#include "songList.h"
#include "tools.h"

//default constructor
SongList::SongList()
{
    size = 0;
    list = new Song[CAP_SIZE];
}
//constructor from file
SongList::SongList(const char fileName[])
{
    ifstream inputFile;
    char tempName[MAX_CHARS];
    char tempArtist[MAX_CHARS];
    int tempMin = 0;
    int tempSec = 0;
    char tempAlbum[MAX_CHARS];
    size = 0;
    list = new Song[CAP_SIZE];

    inputFile.open(fileName);
    //get out if can't open file
    if (!inputFile)
    {
        cout << "File not found! Program terminating!!" << endl;
        exit(0);
    }

    //loop to populate the songs into list
    inputFile.get(tempName, MAX_CHARS, DELIMITER);
    while (!inputFile.eof())
    {
        //get the inputFile data into our temp variables
        inputFile.ignore(50, DELIMITER); //5?
        inputFile.get(tempArtist, MAX_CHARS, DELIMITER);
        inputFile.ignore(50, DELIMITER);
        inputFile >> tempMin;
        inputFile.ignore(50, DELIMITER);
        inputFile >> tempSec;
        inputFile.ignore(50, DELIMITER);
        inputFile.get(tempAlbum, MAX_CHARS, '\n');
        inputFile.ignore(50, '\n');

        //set next index with inputFile info
        list[size].setName(tempName);
        list[size].setArtist(tempArtist);
        list[size].setMin(tempMin);
        list[size].setSec(tempSec);
        list[size].setAlbum(tempAlbum);
        size++;
        //add the song to this class list
        //addASong(song);
        inputFile.get(tempName, MAX_CHARS, DELIMITER);
    }
    inputFile.close();
}

//destructor
SongList::~SongList()
{
    delete[] list;
}

//compares the passed in song to see if artist and name match any song,
//if not, adds the song to the list
bool SongList::addASong(Song &song)
{
    //temp variables
    char tempName1[MAX_CHARS], tempName2[MAX_CHARS], tempArtist1[MAX_CHARS], tempArtist2[MAX_CHARS];
    int i = 0;
    //checking for duplicate songs
    song.getName(tempName2);
    song.getArtist(tempArtist2);
    for (i = 0; i < size; i++)
    {
        list[i].getName(tempName1);
        list[i].getArtist(tempArtist1);
        if (strcmp(tempName1, tempName2) == 0 && strcmp(tempArtist1, tempArtist2) == 0)
            return false;
    }
    //add song to list and increase size
    char buffer[MAX_CHARS];

    song.getName(buffer);
    list[size].setName(buffer);

    song.getArtist(buffer);
    list[size].setArtist(buffer);

    list[size].setMin(song.getMin());

    list[size].setSec(song.getMin());

    song.getAlbum(buffer);
    list[size].setAlbum(buffer);

    size++;
    return true;
}



//deletes a movie from the list
void SongList::delSong()
{
    int selection = 0;
    displayList();
    cout << "Which song would you like to delete (look above) (1-" << size << ")?: ";
    selection = getIntInRange(1, size);
    int index = selection - 1;
    list[index].~Song(); //deallocate memory explicitly
    //shift everything down
    for (int i = index; i < size; i++)
    {
        list[i] = list[i+1];

        // char buffer[MAX_CHARS];

        // list[i+1].getName(buffer);
        // list[i].setName(buffer);

        // list[i+1].getArtist(buffer);
        // list[i].setArtist(buffer);

        // list[i].setMin(list[i+1].getMin());

        // list[i].setSec(list[i+1].getMin());

        // list[i+1].getAlbum(buffer);
        // list[i].setAlbum(buffer);
    }
    size--;
    cout << "Song deleted!" << endl;
}

//prints the whole song list
const void SongList::displayList()
{
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        num = i + 1;
        cout << num << ". ";
        list[i].printSong();
    }
    cout << endl;
}

//finds a movie in the list
const void SongList::findSong()
{
    char searchArtist[MAX_CHARS], tempArtist[MAX_CHARS];
    cout << "Enter an artist by which we will search our list for: ";
    getString(searchArtist, MAX_CHARS);
    convertCase(searchArtist);
    for (int i = 0; i < size; i++)
    {
        list[i].getArtist(tempArtist);
        convertCase(tempArtist);
        if (strcmp(searchArtist, tempArtist) == 0)
        {
            list[i].printSong();
        }
    }
    cout << endl;
}

//writes the data back to the file
void SongList::writeFile()
{
    ofstream outputFile;
    outputFile.open("songs.txt");
    //exit if outputfile doesn't open
    if (!outputFile)
    {
        cout << "File not found! Program terminating!!" << endl;
        exit(0);
    }

    //fill the file with the list contents
    for (int i = 0; i < size; i++)
    {
        list[i].printFile(outputFile);
    }
    outputFile.close();
}