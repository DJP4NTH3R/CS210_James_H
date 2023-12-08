#pragma once
class UserData
{
public: 
	// setter methods
	void setInitialInvestment(double initInvestment);
	void setMonthlyDeposit(double monDeposit);
	void setNumYears(int numberYears);
	void setAnnualInterest(double annualInterest);
	void setTotalWithDeposits(double totalWithDeposit);
	void setTotalNoDeposits(double totalNoDeposit);

	// getter methods have direct definitions
	double getInitialInvestment() { return initialInvestment; }
	double getMonthlyDeposit() { return monthlyDeposit; }
	int getNumYears() { return numYears; }
	double getAnnualInterest() { return yearlyInterest; }
	double getTotalWithDeposits() { return totalWithDeposits; }
	double getTotalNoDeposits() { return totalNoDeposits; }


private:
	double initialInvestment = 0.0;
	double monthlyDeposit = 0.0;
	double yearlyInterest = 0.0;
	int numYears = 0;
	double totalWithDeposits = 0.0;
	double totalNoDeposits = 0.0;
};

