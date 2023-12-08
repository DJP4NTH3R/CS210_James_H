#pragma once
#include "UserData.h"

class DataCalculation
{
public:
	// calc the interest functions
	double calculateInterestNoDeposits(UserData &investmentData);
	double calculateInterestWithDeposits(UserData &investmentData);

	// getter and setter method to extract the cumilative interest from another method
	void setCumilativeInterest(double cumilativeInterest);
	double getCumilativeInterest() { return cumilativeInterestTotal; }

	// calc with and without deposits
	double calculateTotalNoDeposits(UserData &investmentData);
	double calculateTotalWithDeposits(UserData &investmentData);

private:
	double cumilativeInterestTotal = 0.0;
};

