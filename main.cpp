#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "playlist.h"

using namespace std;

void processFile(Playlist &songs);

int main()
{
    Playlist songs;

    // sets up playlist
    processFile(songs);

    cout << "\nInitial playlist: " << endl;
    songs.display();

    cout << endl << "Welcome to the playlist display manager." << endl << endl;

    while(1)
    {
        string option;

        cout << "0. Exit" << endl;
        cout << "1. Sort Playlist" << endl;
        cout << "2. Reverse Sort Playlist" << endl;
        cout << "3. Search Playlist" << endl;
        cout << "4. Shuffle Playlist" << endl;
        //cout << "5. Sort Playlist by Artist" << endl;
        cout << "Which option would you like? ";
        cin >> option;

        cout << endl;

        // exiting
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // sorting
        else if(option == "1")
        {
            songs.sort();
            songs.display();
        }

        // reversing
        else if(option == "2")
        {
            songs.reverseSort();
            songs.display();
        }

        // searching
        else if(option == "3")
        {
            string title;

            cout << "What song title would you like to search? ";
            cin.ignore();
            getline(cin, title);

            int result = songs.binarySearch(title);

            if(result > 0)
            {
                cout << endl << "Song found at position " << result << endl;
            }

            else
            {
                cout << endl << "Song not found." << endl;
            }
        }

        // shuffle
        else if(option == "4")
        {
            songs.shuffle();
            songs.display();
        }

        // sort playlist by artist
        // honors / bonus credit
        /*else if(option == "5")
        {
            songs.sortByArtist();
            songs.display();
        }*/

        // incorrect option
        else
        {
            cout << "That's not a valid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

void processFile(Playlist &songs)
{
    ifstream infile;
    string line;

    infile.open("songs.txt");

    if(infile.is_open())
    {
        cout << "Successful songs opening." << endl;
    }

    else
    {
        cout << "Couldn't locate file. Program closing." << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(infile, line))
    {
        // first line --> song
        // second line --> artist

        if(line != "")
        {
            string song, artist;

            song = line;

            getline(infile, artist);

            songs.append(song, artist);
        }
    }
}
