// Savings_Account.h class definition
// By Aleksey Leshchuk CISP400

#ifndef SAVINGS_ACCOUNT_H
#define SAVING_ACCOUNT_H

#include "Account.h"

class Savings_Account: public Account {
    public:
	// Savings_Account constructor, initializes LastName, FirstName, Balance, InterestRate, OpenDate, UpdateDate
	Savings_Account(const char*, const char*, const double&, const double&, const Date&, const Date&);
	// calculateInterest() calculates interest for 1 period, returns the value
	double calculateInterest() const;
	// addInterest(Date) add interest for 1 period to the account, displays results, updates lastUpdate
	void addInterest(const Date&);
	// final virtual print() prints account information
	void print() const final;
	// setInterestRate(double) validates, sets the interest rate, set to 0 if invalid, print results
	void setInterestRate(const double&);
	// getInterestRate() returns interestRate
	double getInterestRate() const;
    private:
	double interestRate;
};
#endif
