#include <iostream>
#include "UserData.h"
using namespace std;

// definitions for setter methods
void UserData::setInitialInvestment(double initInvestment)
{
	initialInvestment = initInvestment;
}

void UserData::setMonthlyDeposit(double monDeposit)
{
	monthlyDeposit = monDeposit;
}

void UserData::setNumYears(int numberYears)
{
	numYears = numberYears;
}

void UserData::setAnnualInterest(double annualInterest)
{
	yearlyInterest = annualInterest;
}

void UserData::setTotalWithDeposits(double totalWithDeposit)
{
	totalWithDeposits = totalWithDeposit;
}

void UserData::setTotalNoDeposits(double totalNoDeposit)
{
	totalNoDeposits = totalNoDeposit;
}
