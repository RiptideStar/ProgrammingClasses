#include "songList.h"
#include "tools.h"

//default constructor
SongList::SongList()
{
    head = NULL;
    tail = NULL;
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
    head = NULL;
    tail = NULL;
    // size = 0;
    // list = new Song[CAP_SIZE];

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

        Song song;

        //set next index with inputFile info and add the song
        song.setName(tempName);
        song.setArtist(tempArtist);
        song.setMin(tempMin);
        song.setSec(tempSec);
        song.setAlbum(tempAlbum);
        // cout << "read: ";(*song).printSong();

        addASong(song);
        inputFile.get(tempName, MAX_CHARS, DELIMITER);
    }
    inputFile.close();
}

//destructor
SongList::~SongList()
{
    //if there is a list
    if (head)
    {
        songNode *current = head;
        //delete everything going up until final element
        while (current->next != NULL)
        {
            songNode *temp = current;
            current = current->next;
            delete temp;
        }
        //final element deletion
        delete current;
    }
}

//compares the passed in song to see if artist and name match any song,
//if not, adds the song to the list
bool SongList::addASong(Song &song)
{
    //Make a new node for LL
    songNode *node = new songNode;
    node->songDat = song; //operator= overlaod

    if (head)
    {
        songNode *current = head;

        //assign temp variables to song names
        char currentName[MAX_CHARS];
        char nodeSongName[MAX_CHARS];
        current->songDat.getName(currentName);
        node->songDat.getName(nodeSongName);

        //check where we should put this node
        //make current iterate toward end if current's name should be ahead (before) of the song's name
        while (strcmp(currentName, nodeSongName) < 0)
        {
            if (current->next)
            {
                current = current->next;
                current->songDat.getName(currentName);
            }
            else
            {
                //tail adding
                node->prev = current;
                //assign the end after to the node
                current->next = node;
                node->next = NULL;
                tail = node;
                return true;
            }
        }

        //check if it is a duplicate song
        char currentArtist[MAX_CHARS];
        char nodeSongArtist[MAX_CHARS];
        current->songDat.getArtist(currentArtist);
        node->songDat.getArtist(nodeSongArtist);
        if (strcmp(currentName, nodeSongName) == 0 && strcmp(currentArtist, nodeSongArtist) == 0)
            return false;

        //we get to here if the node should be before current
        //check if current is the head
        if (current == head)
        {
            head = node;
        }
        node->next = current;
        node->prev = current->prev;
        //if current was the head, there is node before it, so it fine
        if (current->prev)
            current->prev->next = node;
        current->prev = node;
    }

    //if no list
    else
    {
        node->prev = NULL;
        node->next = NULL;
        head = node;
        tail = node;
    }

    return true;
}

//deletes a song from the list
//if index is larger than the size of list, last song is removed
void SongList::delSong()
{
    int selection = 0;
    displayList();
    cout << endl << "Which song would you like to delete from the above? ";
    selection = getIntAboveMinimum(1);
    int index = selection - 1;

    if (head)
    {
        songNode *current = head;

        //have current get to the correct node to delete
        for (int i = 0; i < index; i++)
        {
            if (current->next)
            {
                current = current->next;
            }
        }

        //check if it is the first element being removed
        if (current == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        //otherwise, we set adjacent nodes to point to each other
        else
        {
            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;
            current->prev->next = current->next;
        }

        //deallocate memory
        delete current;

        cout << "Song deleted!" << endl;
    }
    //no list, no delete
    else
    {
        cout << "The song list is empty, try adding a song first." << endl;
    }
}

//prints the whole song list
const void SongList::displayList()
{
    int i = 1;
    if (head)
    {
        songNode *current = head;
        cout << i << ". ";
        current->songDat.printSong();
        i++;
        //loop to keep printing the node data
        while (current->next != NULL)
        {
            current = current->next;
            cout << i << ". ";
            current->songDat.printSong();
            i++;
        }
    }
    else
    {
        cout << "No Songs in List, try adding a song" << endl;
    }
}

//finds a movie in the list
const void SongList::findSongByArtist()
{
    char searchArtist[MAX_CHARS], tempArtist[MAX_CHARS];
    cout << "Enter an artist by which we will search our list for: ";
    getString(searchArtist, MAX_CHARS);
    convertCase(searchArtist);

    if (head)
    {
        songNode *current = head;

        do
        {
            current->songDat.getArtist(tempArtist);
            convertCase(tempArtist);
            if (strcmp(searchArtist, tempArtist) == 0)
            {
                current->songDat.printSong();
            }

            //if statement we need to check if the list has a size of 1
            if (current->next)
            {
                current = current->next;
            }
        } while (current->next);

        //we still need to check the last node (current)
        current->songDat.getArtist(tempArtist);
        convertCase(tempArtist);
        if (strcmp(searchArtist, tempArtist) == 0)
        {
            current->songDat.printSong();
        }
    }
    else
    {
        cout << "No Songs in List, trying adding a song" << endl;
    }
}

const void SongList::findSongByAlbum()
{
    char searchAlbum[MAX_CHARS], tempAlbum[MAX_CHARS];
    cout << "Enter an album by which we will search our list for: ";
    getString(searchAlbum, MAX_CHARS);
    convertCase(searchAlbum);

    if (head)
    {
        songNode *current = head;

        do
        {
            current->songDat.getAlbum(tempAlbum);
            convertCase(tempAlbum);
            if (strcmp(searchAlbum, tempAlbum) == 0)
            {
                current->songDat.printSong();
            }

            //if statement we need to check if the list has a size of 1
            if (current->next)
            {
                current = current->next;
            }
        } while (current->next);

        //we still need to check the last node (current)
        current->songDat.getAlbum(tempAlbum);
        convertCase(tempAlbum);
        if (strcmp(searchAlbum, tempAlbum) == 0)
        {
            current->songDat.printSong();
        }
    }
    else
    {
        cout << "No Songs in List, trying adding a song" << endl;
    }
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
    if (head)
    {
        songNode *current = head;
        current->songDat.printFile(outputFile);
        //loop to keep printing the node data
        while (current->next != NULL)
        {
            current = current->next;
            current->songDat.printFile(outputFile);
        }
    }
    else
    {
        cout << "No Songs in List" << endl;
    }
    outputFile.close();
}