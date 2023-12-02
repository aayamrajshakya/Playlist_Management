/*
Name: Aayam Raj Shakya          NetID: as5160
Date: 22 April 2023         Due Date: 22 April 2023
Description: This C++ program defines a Playlist class with several member functions to manage a list of songs.
            The program is designed to provide basic functionality for managing a playlist of songs, including shuffling
             and searching for songs, as well as sorting them by title in either ascending or descending order.
*/


#include "playlist.h"

// constructor and destructor (given to you)
Playlist::Playlist()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Playlist::~Playlist()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// display and add functions (given to you)
void Playlist::display()
{
    // starts temporary Node at the beginning (head)
    Node *temp = head;

    while(temp != nullptr)
    {
        // displays information
        cout << temp->title << " - " << temp->artist << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void Playlist::append(string title, string artist)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node;

        head->title = title;
        head->artist = artist;
        head->next = nullptr;

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node;

        temp->title = title;
        temp->artist = artist;
        temp->next = nullptr;

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

void Playlist::shuffle()
{
    // seeds random number
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        int num = rand() % size;

        // swaps current "index" with random "index"

        // gets node at current position
        Node *current = head;
        for(int j = 0; j < i; j++)
        {
            current = current->next;
        }

        // gets node at random position
        Node *random = head;
        for(int j = 0; j < num; j++)
        {
            random = random->next;
        }

        // stores the current Node's information
        string tempTitle = current->title;
        string tempArtist = current->artist;

        // reassigns the random Node's information to the current
        current->title = random->title;
        current->artist = random->artist;

        // and the stored current information to the random Node
        random->title = tempTitle;
        random->artist = tempArtist;
    }
}

// ****************************************************************
// ** you should make **
// all of these should work on a TITLE of the song basis
// ****************************************************************

int Playlist::binarySearch(string title)
{
    Node* current = head;
    int index = 1;

    while (current != nullptr)
    {
        if (current->title == title)
        {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}

// algorithm of choice:
// any links to resources to make it work:
void Playlist::sort()
{
// perform bubble sort on the playlist
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Node* current = head;
        for (int i = 1; i < size; i++)
        {
            Node* next = current->next;
            if (current->title > next->title)
            {
                std::swap(current->title, next->title);
                std::swap(current->artist, next->artist);
                swapped = true;
            }
            current = next;
        }
    }
    // playlist is now sorted
}

// algorithm of choice:
// any links to resources to make it work:
void Playlist::reverseSort()
{
    // perform bubble sort on the playlist
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Node* current = head;
        for (int i = 1; i < size; i++)
        {
            Node* next = current->next;
            if (current->title < next->title)
            {
                std::swap(current->title, next->title);
                std::swap(current->artist, next->artist);
                swapped = true;
            }
            current = next;
        }
    }
    // playlist is now reverse sorted
}


// ****************************************************************
// ****************************************************************


// HONORS / BONUS credit
// optional unless you're honors
// if not implementing, just leave it here
void Playlist::sortByArtist()
{

}
