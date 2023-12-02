#include <string>
#include <iostream>

// random number
#include <time.h>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;

#ifndef PLAYLIST_H
#define PLAYLIST_H


class Playlist
{
    private:
        struct Node
        {
            string title;
            string artist;
            Node *next;
        };

        Node *head, *tail;
        int size;

    public:
        // constructor and destructor (given to you)
        Playlist();
        ~Playlist();

        // display and add functions (given to you)
        void display();
        void append(string title, string artist);

        // given to you
        void shuffle();

        // **** you should complete these ****
        // all of these should work on a TITLE of the song basis
        int binarySearch(string title);
        void sort();            // sorting algorithm of your choice
        void reverseSort();     // DIFFERENT sorting algorithm of your choice


        // HONORS / BONUS credit
        // optional unless you're honors
        // if not implementing, just leave it here
        void sortByArtist();    // DIFFERENT sorting algorithm of your choice
};

#endif // PLAYLIST_H
