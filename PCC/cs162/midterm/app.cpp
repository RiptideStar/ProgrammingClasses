// Kyle Zhang CS162 Midterm
// 7/22/2020
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_CHARS = 101;

int getInt();
int getNum();
void stringInfo(const char myString[], int &vowels, int &spaces);

int main()
{
    cout << "Start of program!" << endl;
    int x = getNum();
    cout << "You entered: " << x << endl;
    const char sentence[100] = "Test sentence for CS162 midterm";
    int numVowels = 0, numSpaces = 0;
    stringInfo(sentence, numVowels, numSpaces);
    cout << "'" << sentence << "' Has " << numVowels << " vowels and "
         << numSpaces << " spaces." << endl;
    return 0;
}

/*
getInt looks for illegal input, make sure it is a number
*/
int getInt()
{
    int num;

    cin >> num;
    //check for illegal input
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

int getNum()
{
    int num;

    cout << "Enter a number greater than zero: ";
    num = getInt();
    //check if number isn't greater than zero
    while (num <= 0)
    {
        cout << "The number must be greater than 0"
             << endl;
        cout << "Please try again: ";
        num = getInt();
    }
    return num;
}

void stringInfo(const char myString[], int &vowels, int &spaces)
{
    for (int i = 0; i < (int)strlen(myString); i++)
    {
        //lowercase
        char loweredLetter = tolower(myString[i]);
        //check for vowels
        if (loweredLetter == 'a' || loweredLetter == 'e' || loweredLetter == 'i' || loweredLetter == 'o' || loweredLetter == 'u')
        {
            vowels++;
        }
        //check for spaces
        if (isblank(loweredLetter))
        {
            spaces++;
        }
    }
}
