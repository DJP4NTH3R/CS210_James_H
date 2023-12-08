// BankingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Coded by James Halmer
// CS 210
// 11/24/2023

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include "UserData.h"
#include "DataCalculation.h"
using namespace std;

// user input method to print the initial prompt and collect the initial data in to UserData object
void getUserInput(UserData &investmentData) {
    
    double initialInvestment = 0.0;
    double monthlyDeposit = 0.0;
    double annualIntrest = 0.0;
    int numYears = 0;

    cout << string(34, '*') << endl;
    cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
    cout << "Initial Investment Amount:" << endl;
    cin >> initialInvestment;
    investmentData.setInitialInvestment(initialInvestment);
    cout << "Monthly Deposit:" << endl;
    cin >> monthlyDeposit;
    investmentData.setMonthlyDeposit(monthlyDeposit);
    cout << "Annual Interest:" << endl;
    cin >> annualIntrest;
    investmentData.setAnnualInterest(annualIntrest);
    cout << "Number of Years:" << endl;
    cin >> numYears;
    investmentData.setNumYears(numYears);

}

// print the collected user data by accessing the UserData object
void printUserInput(UserData &investmentData) {

    cout << string(34, '*') << endl;
    cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
    cout << "Initial Investment Amount:  $" << fixed << setprecision(2) << investmentData.getInitialInvestment() << endl;
    cout << "Monthly Deposit:  $" << setprecision(2) << investmentData.getMonthlyDeposit() << endl;
    cout << "Annual Interest:  " << setprecision(1) << investmentData.getAnnualInterest() << "%" << endl;
    cout << "Number of Years:  " << investmentData.getNumYears() << setprecision(2) << endl;
}

// Prints the tables for yearly balances with and without deposits
// Note: Proper consistant formatting is not fully present in this implementation
void printTables(UserData& investmentData) {
    // we can declare a new data calculation object in the method instead of passing it through as it does not need to store data beyond it
    DataCalculation dataCalc;
    cout << string(5, ' ') << "Balance and Interest Without Additional Monthly Deposits" << string(5, ' ') << endl;
    cout << string(66, '=') << endl;
    cout << "  Year" << string(10, ' ') << "Year End Balance" << string(5, ' ') << "Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;
    // initialize our balance without deposit
    investmentData.setTotalNoDeposits(investmentData.getInitialInvestment());

    for (int i = 1; i <= investmentData.getNumYears(); i++) {
        cout << string(5, ' ') << i;
        cout << string(21, ' ') << "$" << dataCalc.calculateTotalNoDeposits(investmentData);
        cout << string(21, ' ') << "$" << dataCalc.getCumilativeInterest() << endl;
    }

    system("pause");
    cout << endl;
    // omitted system("CLS") so user can compare both tables

    cout << string(6, ' ') << "Balance and Interest With Additional Monthly Deposits" << string(6, ' ') << endl;
    cout << string(66, '=') << endl;
    cout << "  Year" << string(10, ' ') << "Year End Balance" << string(5, ' ') << "Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;
    // initialize our balance with deposit
    investmentData.setTotalWithDeposits(investmentData.getInitialInvestment());

    for (int i = 1; i <= investmentData.getNumYears(); i++) {
        cout << string(5, ' ') << i;
        cout << string(21, ' ') << "$" << dataCalc.calculateTotalWithDeposits(investmentData);
        cout << string(21, ' ') << "$" << dataCalc.getCumilativeInterest() << endl;
    }
}

// main function
int main()
{
    // declare our UserData object to store input and data
    UserData investmentData;
    //declare variables for the loop
    bool isRunning = true;
    char userInput;

    // program loop
    while (isRunning) {
        // call the functions in order and pass through our object where needed
        // a pause and clear screen system function is inserted to produce the "any key" and keep the interface clean
        getUserInput(investmentData);
        system("pause");
        system("CLS");
        printUserInput(investmentData);
        system("pause");
        system("CLS");
        printTables(investmentData);

        // prompt for input for another calculation 
        cout << endl << "Calculate another table? Y/N: " << endl;
        cin >> userInput;
        if (userInput == 'Y' || userInput == 'y') {
            isRunning = true;
            system("CLS");
        }
        else {
            isRunning = false;
        }
    }
   
    return 0;
}
