// ProjectOneClock.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmed by: James Halmer
// Date: 11/9/2023
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// declaring some quasi global variables
// this makes sense and it doesn't. Since we aren't using classes its strange to use getter and setter methods
// none the less, these variables act as global variables accessible by all functions but arer mostly interacted with through the getter and setter methods
int hours;
int minutes;
int seconds;

// converts a single digit to a two digit string or two digits to a two digit string
string twoDigitString(unsigned int n) {
    // declare a string to store our new string
    string convertedString;
    // check to see if the number is in the range of 0 to 9
    if (n >= 0 && n < 10) {
        convertedString = "0" + to_string(n); // convert with the to_string() method
    }
    else { // any other circumstance we just convert
        convertedString = to_string(n);
    }
    return convertedString;
}
// function to fill a string with a set length, with a set character
string nCharString(size_t n, char c) {
    string filler(n, c); // define the string with the parameters
    return filler;
}
// function formats a string to 24 hour time format
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string output;
    output = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
    return output;
}
// function formats a string to 12 hour format. Appends AM and PM appropriately. 
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string output;
    string timeOfDay;
    int temp;
    if (h > 12) {
        temp = h - 12;
        timeOfDay = " P M";
    }
    else if (h == 12) {
        temp = h;
        timeOfDay = " P M";
    }
    else if (h == 0){
        temp = 12;
        timeOfDay = " A M";
    }
    else {
        temp = h;
        timeOfDay = " A M";
    }
    // could be more efficient but its giving me a headache
    // at least it is guaranteed to catch every case
    output = twoDigitString(temp) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + timeOfDay;
    return output;
}

// outputs the menu to the command line
void printMenu(std::vector<string>& strings, unsigned int numStrings, unsigned char width) { // switched from const char* array to vector as the usage was so cryptic

    cout << nCharString(width, '*') << endl; // header filled with '*'
    for (unsigned int i = 0; i < numStrings; i++) {
        cout << '*' << ' ' << i + 1 << " - " << strings[i] << nCharString((width - 7) - strings[i].size(), ' ') << '*' << endl; // output the menue items as apropriate
        if (i != numStrings - 1) { // prevents outputting a new line after the last element
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl; // footer filled with '*'
}
// checks and validates input for the menu
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int input;
    bool ValidCoice = false;
    while (!ValidCoice) {
        cin >> input;
        if (input >= 1 && input <= maxChoice) {
            ValidCoice = true;
        }
    }
    return input;
}
// displays the clocks in 12 hour and 24 hour format
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << '*' << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << '*' << "   ";
    cout << '*' << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << '*' << endl;
    cout << endl;
    cout << '*' << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << '*' << "   ";
    cout << '*' << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << '*' << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}

// getter and setter methods for the global variables
int getHour() {
    return hours;
}

int setHour(int h) {
    hours = h;
    return hours;
}

int getMinute() {
    return minutes;
}

int setMinute(int m) {
    minutes = m;
    return minutes;
}

int getSecond() {
    return seconds;
}

int setSecond(int s) {
    seconds = s;
    return seconds;
}

// functions to add an hour, minute, and a second.
void addOneHour() {
    int updateHour = getHour();
    if (updateHour >= 0 && updateHour <= 22) {
        updateHour = updateHour + 1;
        setHour(updateHour);
    }
    else {
        setHour(0);
    }
}

void addOneMinute() {
    int updateMinute = getMinute();
    if (updateMinute >= 0 && updateMinute <= 58) {
        updateMinute = updateMinute + 1;
        setMinute(updateMinute);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}

void addOneSecond() {
    int updateSecond = getSecond();
    if (updateSecond >= 0 && updateSecond <= 58) {
        updateSecond = updateSecond + 1;
        setSecond(updateSecond); 
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}

// main menu function that takes user input to add time 
void mainMenu() {
    bool IsExit = false;
    std::vector<string> menuItems = { "Add One Hour","Add One Minute","Add One Second","Exit Program" };
    while (!IsExit) {
        displayClocks(hours, minutes, seconds);
        printMenu(menuItems, 4, 26);
        switch (getMenuChoice(4))
        {
        case 1:
            addOneHour();
            system("CLS"); // clearing the screen after a selection allows it to be redrawn and avoid a scrolling program
            break;
        case 2:
            addOneMinute();
            system("CLS"); 
            break;
        case 3:
            addOneSecond();
            system("CLS"); 
            break;
        case 4:
            cout << endl << "Good bye!" << endl; 
            IsExit = true;
            break;

        default:
            break;
        }
    }
}

// custom initialization function that takes user input for the initial clock values
void initializeTime() {
    
    int userHours;
    int userMinutes; 
    int userSeconds; 
    bool ValidInput = false; 
    cout << "Please enter the initial time: " << endl; 
    cout << "Hours: ";
    cin >> userHours; 
    while (!ValidInput) {  // loop and check for valid input. Requires correct input to continue
        if (userHours >= 0 && userHours <= 24) { 
            setHour(userHours); 
            ValidInput = true; 
        }
        else {
            cout << "Hours must be between 0 and 24. Try again: " << endl; 
            cin >> userHours; 
        }
    }
    ValidInput = false; // reset our boolean so it can be re-used. 
    cout << endl; 
    cout << "Minutes: ";
    cin >> userMinutes; 
    while (!ValidInput) { 
        if (userMinutes >= 0 && userMinutes <= 59) { 
            setMinute(userMinutes); 
            ValidInput = true; 
        }
        else {
            cout << "Minutes must be between 0 and 59. Try again: " << endl; 
            cin >> userMinutes; 
        }
    }
    ValidInput = false; 
    cout << endl; 
    cout << "Seconds: "; 
    cin >> userSeconds; 
    while (!ValidInput) { 
        if (userSeconds >= 0 && userSeconds <= 59) { 
            setSecond(userSeconds); 
            ValidInput = true;
        }
        else {
            cout << "Seconds must be between 0 and 59. Try again: " << endl; 
            cin >> userSeconds; 
        }
    }
    ValidInput = false; // final reset may be unnecessary since we never re-enter this part of the program.

}
// main function simply executes the core functionality of the program as needed. Once the mainMenu() function is exited, the program exits
int main()
{
    
    initializeTime();
    system("CLS");
    mainMenu();

    return 0;
}
/*
* This exercise was quite challanging. 
* My biggest challange was overcoming car* arrays. I ended up replacing it as I was unable to find a more elegant solution. 
* I had a solution of casting the string array but that caused a catastrophic bug that spat out garbled characters
* As such, I opted for vectors instead.
* 
* Overall, considering the complexity of the program, dispite how simple it is, I question on how apropriate this level of challange was for the first project.
* Furthermore, this program would have been better served using classes. Getter and setter methods would also make far more sense in that circumstance. 
* I would have opted to create a clock object and a menu object instead. 
* I would appreciate some feedback on how I did and on my reflection here.
*/
