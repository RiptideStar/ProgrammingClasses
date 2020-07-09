/* Kyle Zhang
Project 2

Sources: None
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char DELIMITER = ';';
const int MAX_SIZE = 50;
const int MAX_CHARS = 101;

struct Song
{
  char name[MAX_CHARS];
  char artist[MAX_CHARS];
  //Duration
  int min;
  int sec;

  char album[MAX_CHARS];
};

// Function Declaration
int getInt();
int getIntInRange(int min, int max);
void getString(char string[], int maxChars);
int getIntAboveMin(int min);
void menu();
void loadInSongs(Song songs[], const char fileNameIn[], char songName[], char artist[], int &min, int &sec, char album[], int &indexCap);
void addSong(Song songs[], char songName[], char artist[], int &min, int &sec, char album[], int &biggestIndex);
void printSongs(const Song songs[], int sizeLimit);
void deleteSong(Song songs[], int &biggestIndex);
void searchSongsByArtist(const Song songs[], int biggestIndex);
void printASong(const Song songs[], int i);
void saveSongs(const Song songs[], int &biggestIndex, const char fileNameOut[]);

int main()
{
  // Song defaultSong;
  // strcpy(defaultSong.name, "DO NOT NAME YOUR SONG THIS! UNDER NO CONDITIONS");
  // strcpy(defaultSong.artist, "DO NOT NAME YOUR ARTIST THIS! UNDER NO CONDITIONS");
  // defaultSong.min = -1;
  // defaultSong.sec = -1;
  // strcpy(defaultSong.album, "DO NOT NAME YOUR ALBUM THIS! UNDER NO CONDITIONS");

  Song songs[MAX_SIZE];

  //The database of songs
  char fileNameIn[MAX_CHARS] = "songs.txt";
  char fileNameOut[MAX_CHARS] = "songs.txt";

  char songName[MAX_CHARS];
  char artist[MAX_CHARS];
  int min;
  int sec;
  char album[MAX_CHARS];
  int biggestIndex = 0;

  int response;

  //Load Songs from File
  loadInSongs(songs, fileNameIn, songName, artist, min, sec, album, biggestIndex);

  //User Interaction
  menu();
  response = getIntInRange(0, 4);

  //Loop
  while (response != 0)
  {
    if (response == 1)
      addSong(songs, songName, artist, min, sec, album, biggestIndex);
    if (response == 2)
      printSongs(songs, biggestIndex);
    if (response == 3)
      deleteSong(songs, biggestIndex);
    if (response == 4)
      searchSongsByArtist(songs, biggestIndex);
    menu();
    response = getIntInRange(0, 4);
  }

  //Write array into output file
  saveSongs(songs, biggestIndex, fileNameOut);

  return 0;
}

void menu()
{
  cout << "Please enter a number: (1) Enter a New Song, (2) See all the Songs in our List,"
          "(3) Remove a song by index, (4) Search for songs by artist, (0) Quit: ";
}

void loadInSongs(Song songs[], const char fileNameIn[], char songName[], char artist[], int &min, int &sec, char album[], int &indexCap)
{
  ifstream inputFile;
  Song currentSong;
  int index = 0;
  //char string[MAX_CHARS];
  inputFile.open(fileNameIn);

  //Check for failure
  if (!inputFile)
  {
    cerr << "Failed to open " << fileNameIn << " for input." << endl;
    exit(1);
  }

  inputFile.get(songName, MAX_CHARS, DELIMITER);
  while (!inputFile.eof())
  {

    inputFile.get(); //delimiter
    inputFile.get(artist, MAX_CHARS, DELIMITER);
    inputFile.get(); //delimiter
    inputFile >> min;
    inputFile.get(); //delimiter
    inputFile >> sec;
    inputFile.get(); //delimiter
    inputFile.get(album, MAX_CHARS, '\n');
    inputFile.ignore(MAX_CHARS, '\n');

    //Assign newly gathered info to currentSong
    strcpy(currentSong.name, songName);
    strcpy(currentSong.artist, artist);
    currentSong.min = min;
    currentSong.sec = sec;
    strcpy(currentSong.album, album);

    //Add currentSong to the array
    songs[index] = currentSong;
    index++;

    inputFile.get(songName, MAX_CHARS, ';');
  }
  indexCap = index - 1;
  inputFile.close();
}

void addSong(Song songs[], char songName[], char artist[], int &min, int &sec, char album[], int &biggestIndex)
{
  Song newSong;
  //user interaction
  cout << "Please enter a name for the song: ";
  getString(songName, MAX_CHARS);
  cout << "Please enter an artist name: ";
  getString(artist, MAX_CHARS);
  cout << "Please enter the duration (minutes) (don't worry, I will let you type in seconds later): ";
  min = getIntAboveMin(0);
  cout << "Just like I promised, enter in the duration for the seconds: ";
  sec = getIntInRange(0, 59);
  cout << "Lastly, enter the album: ";
  getString(album, MAX_CHARS);

  //Assign newly gathered info to newSong
  strcpy(newSong.name, songName);
  strcpy(newSong.artist, artist);
  newSong.min = min;
  newSong.sec = sec;
  strcpy(newSong.album, album);

  //Assign newSong to array at left off spot
  biggestIndex++;
  songs[biggestIndex] = newSong;

  cout << "Your song has been added to the list." << endl;
}

void printSongs(const Song songs[], int indexLimit)
{
  for (int i = 0; i <= indexLimit; i++)
  {
    cout << "Index " << i << ": ";
    printASong(songs, i);
  }
}

void deleteSong(Song songs[], int &biggestIndex)
{
  //User Interaction
  cout << "Enter an index of the song you wish to delete (0-" << biggestIndex << "): ";
  int index = getIntInRange(0, biggestIndex);

  //Shift everything forward
  for (int i = index; i < biggestIndex; i++)
  {
    songs[index] = songs[index + 1];
  }

  //Reset largest index back to default
  strcpy(songs[biggestIndex].name, "");
  strcpy(songs[biggestIndex].artist, "");
  songs[biggestIndex].min = 0;
  songs[biggestIndex].sec = 0;
  strcpy(songs[biggestIndex].album, "");

  //the array just shrunk -1
  biggestIndex--;

  cout << "Index " << index << " has been removed." << endl;
}

void searchSongsByArtist(const Song songs[], int biggestIndex)
{
  char artist[MAX_CHARS];
  //User Interaction
  cout << "Please enter an artist by which I will search for: ";
  getString(artist, MAX_CHARS);

  int count = 1;
  //THE SEARCH! and print if match
  for (int i = 0; i <= biggestIndex + 1; i++)
  {
    if (strcmp(songs[i].artist, artist) == 0)
    {
      cout << count << ": ";
      printASong(songs, i);
      count++;
    }
  }
  if (count == 1)
  {
    cout << "No songs were found from the artist " << artist << endl;
  }
}

void printASong(const Song songs[], int i)
{
  if (songs[i].sec < 10)
    cout << songs[i].name << " by " << songs[i].artist << " (" << songs[i].min << ":0" << songs[i].sec
         << ") inside the album: " << songs[i].album << endl;
  else
    cout << songs[i].name << " by " << songs[i].artist << " (" << songs[i].min << ":" << songs[i].sec
         << ") inside the album: " << songs[i].album << endl;
}

void saveSongs(const Song songs[], int &biggestIndex, const char fileNameOut[])
{
  ofstream outputFile;

  outputFile.open(fileNameOut);

  //Check for errors with the file
  if (!outputFile)
  {
    cerr << "Error with opening " << fileNameOut << " for output" << endl;
    exit(1);
  }

  for (int i = 0; i <= biggestIndex; i++)
  {
    if (songs[i].sec < 10)
      outputFile << songs[i].name << DELIMITER << songs[i].artist << DELIMITER << songs[i].min << DELIMITER << "0" << songs[i].sec
                 << DELIMITER << songs[i].album << endl;
    else
      outputFile << songs[i].name << DELIMITER << songs[i].artist << DELIMITER << songs[i].min << DELIMITER << songs[i].sec
                 << DELIMITER << songs[i].album << endl;
  }
  outputFile.close();
}

int getInt()
{
  int num;

  cin >> num;
  while (!cin)
  {
    cin.clear();
    cin.ignore(MAX_CHARS, '\n');

    cout << "You entered an illegal number. Please try again: ";
    cin >> num;
  }
  cin.ignore(MAX_CHARS, '\n');
  return num;
}

int getIntAboveMin(int min)
{
  int num;

  num = getInt();
  while (num < min)
  {
    cout << "The number must be greater than " << min
         << endl;
    cout << "Please try again: ";
    num = getInt();
  }
  return num;
}

int getIntInRange(int min, int max)
{
  int num;

  num = getInt();
  while (num < min || num > max)
  {
    cout << "The number must be between (inclusive) " << min << " and " << max
         << endl;
    cout << "Please try again: ";
    num = getInt();
  }
  return num;
}

void getString(char string[], int maxChars)
{
  cin.get(string, maxChars, '\n');
  while (!cin)
  {
    cin.clear();
    cin.ignore(maxChars, '\n');

    cout << "You forgot to enter in something! Please try again: ";
    cin.get(string, maxChars, '\n');
  }
  cin.ignore(maxChars, '\n');
}
