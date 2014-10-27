// Savings_Account.cpp class implementation
// By Aleksey Leshchuk CISP400

#include <iostream>
#include <iomanip>
#include "Savings_Account.h"

// Savings_Account constructor, initializes LastName, FirstName, Balance, InterestRate, OpenDate, UpdateDate
Savings_Account::Savings_Account(
	const char* lName, 
	const char* fName, 
	const double& balance,
	const double& interRate,
	const Date& oDate, 
	const Date& uDate
	):
    Account(lName,fName,balance,oDate,uDate)
{
    setInterestRate(interRate);
}
// calculateInterest() calculates interest for 1 period, returns the value
double Savings_Account::calculateInterest() const {
    return interestRate*getBalance();
}
// addInterest(Date) add interest for 1 period to the account, displays results, updates lastUpdate
void Savings_Account::addInterest(const Date& uDate) {
    credit(getBalance()*interestRate,uDate);
}
// final virtual print() prints account information
void Savings_Account::print() const {}
// setInterestRate(double) validates, sets the interest rate, set to 0 if invalid, print results
void Savings_Account::setInterestRate(const double&){}
	
