#include <iostream>
#include "DataCalculation.h"

// interest functions are essentially the same. Kept seperate to avoid confusion
double DataCalculation::calculateInterestNoDeposits(UserData &investmentData)
{
	return investmentData.getTotalNoDeposits() * ((investmentData.getAnnualInterest() / 100.00) / 12.00);
}

double DataCalculation::calculateInterestWithDeposits(UserData &investmentData)
{
	return investmentData.getTotalWithDeposits() * ((investmentData.getAnnualInterest() / 100.00) / 12.00);
}

// setter method for the extracted cumilative interest
void DataCalculation::setCumilativeInterest(double cumilativeInterest)
{
	cumilativeInterestTotal = cumilativeInterest;
}

// calculates the end of year balance compounded monthly
double DataCalculation::calculateTotalNoDeposits(UserData &investmentData)
{

	double totalInvestment = investmentData.getTotalNoDeposits();
	double monthlyInterest = calculateInterestNoDeposits(investmentData);
	double interestYTD = 0.0;

	// compounding monthly interest loop
	for (int i = 1; i <= 12; i++) {
		totalInvestment = totalInvestment + monthlyInterest;
		investmentData.setTotalNoDeposits(totalInvestment);
		interestYTD += monthlyInterest;
		setCumilativeInterest(interestYTD); // extract the cumilative interest from this method
	}
	

	return totalInvestment;
}

// calculates the end of year balance with monthly deposits with compounded monthly interest
double DataCalculation::calculateTotalWithDeposits(UserData &investmentData)
{

	double totalInvestment = investmentData.getTotalWithDeposits();
	double monthlyDeposit = investmentData.getMonthlyDeposit();
	double monthlyInterest = calculateInterestWithDeposits(investmentData);
	double interestYTD = 0.0;
	setCumilativeInterest(interestYTD); // resets the cumilative interest to 0.0
	
	// compounding monthly interest loop
	for (int i = 1; i <= 12; i++) {

		totalInvestment = totalInvestment + monthlyDeposit;
		investmentData.setTotalWithDeposits(totalInvestment);
		monthlyInterest = calculateInterestWithDeposits(investmentData);
		interestYTD += monthlyInterest;
		totalInvestment = totalInvestment + monthlyInterest;
		setCumilativeInterest(interestYTD); 
		
	}
	// update with finalized numbers after iterations
	investmentData.setTotalWithDeposits(totalInvestment); 
	setCumilativeInterest(interestYTD); 

	return totalInvestment;
}
