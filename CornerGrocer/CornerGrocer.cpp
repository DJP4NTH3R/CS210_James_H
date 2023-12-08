// CornerGrocer.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Coded by James Halmer
// CS210
//12/08/2023

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Records.h"

using namespace std;

// checks and validates input for the menu
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int input;
    bool ValidCoice = false;
    while (!ValidCoice) {
        cin >> input;
        if (input >= 1 && input <= maxChoice) {
            ValidCoice = true;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return input;
}

// print the menue as needed
void printMenu(std::vector<string>& strings, unsigned int numStrings, unsigned char width) { 

    cout << string(width, '*') << endl; // header filled with '*' 
    for (unsigned int i = 0; i < numStrings; i++) {
        cout << '*' << ' ' << i + 1 << " - " << strings[i] << string((width - 7) - strings[i].size(), ' ') << '*' << endl; // output the menue items as apropriate 
        if (i != numStrings - 1) { // prevents outputting a new line after the last element
            cout << endl;
        }
    }
    cout << string(width, '*') << endl; // footer filled with '*' 
}

// main menue function that calls functions of our object as necessary
void mainMenu(Records& InputRecord) {
    bool IsExit = false;
    string userWord; // string to hold the user's search term
    std::vector<string> menuItems = { "Search for a Word","Print the Word Frequency","Graph the Word Frequency","Exit Program" };
    printMenu(menuItems, 4, 32);
    while (!IsExit) {
        switch (getMenuChoice(4))
        {
        case 1:
            system("CLS"); // clearing the screen after a selection allows it to be redrawn and avoid a scrolling program
            cout << "Enter a word to search for: ";
            cin >> userWord; // could be changed to getline() if the word is longer than a single word
            // Printing out the frequency of the searched term. If not found, it will be 0.
            cout << "The word " << userWord << " appears " << InputRecord.frequencySearch(userWord) << " times." << endl << endl;
            system("pause");
            system("CLS");
            printMenu(menuItems, 4, 32); // print menue after every selection to prepare for next selection
            break;
        case 2:
            // calls the frequencyNum() function
            system("CLS");
            InputRecord.frequencyNum();
            system("pause");
            system("CLS");
            printMenu(menuItems, 4, 32);
            break;
        case 3:
            // calls the frequencyGraph() function
            system("CLS");
            InputRecord.frquencyGraph();
            system("pause");
            system("CLS");
            printMenu(menuItems, 4, 32);
            break;
        case 4:
            // exit the program with an exit message
            cout << endl << "Good bye!" << endl;
            IsExit = true;
            break;

        default:
            break;
        }
    }
}

int main()
{
    Records UserRecords;
    UserRecords.setInputFileName("CS210_Project_Three_Input_File.txt"); // sets the file name. Can be changed to be handled by user input if necessary
    UserRecords.initializeWordFrequency(); // initialize our map with the text file
    mainMenu(UserRecords); // pass the object to the main menu and run the function
    return 0;
}

