// Savings_Account.cpp class implementation
// By Aleksey Leshchuk CISP400

#include <iostream>
#include <iomanip>
#include "Savings_Account.h"
using namespace std;

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
    setInterestRate(interRate,uDate);
}
// calculateInterest() calculates interest for 1 period, returns the value
double Savings_Account::calculateInterest() const {
    return getInterestRate()*getBalance();
}
// addInterest(Date) add interest for 1 period to the account, displays results, updates lastUpdate
void Savings_Account::addInterest(const Date& uDate) {
    cout<<endl<<getFirstName()<<" "<<getLastName();
    cout<<setprecision(2)<<fixed<<"\nBalance: "<<getBalance()<<" Interest rate: "<<interestRate;
    cout<<"\nInterest "<<calculateInterest()<<" added into balance";
    credit(calculateInterest(),uDate);
    cout<<"\nThe new balance is $"<<getBalance()<<endl;
}
// final virtual print() prints account information
void Savings_Account::print() const {
    cout<<"\nSavings Account:";
    Account::print();
    cout<<"\nInterest Rate: "<<getInterestRate()<<endl;
}
// setInterestRate(double) validates, sets the interest rate, set to 0 if invalid, print results
void Savings_Account::setInterestRate(const double& interRate, const Date& uDate){
    Account::setUpdateDate(uDate);
    if (interRate>0.0){
	interestRate=interRate;
    } else {		// if interest rate is <0, set to 0 and display account info
	interestRate=0;
	print();
    }
}

// getInterestRate() returns the current interest rate
double Savings_Account::getInterestRate() const {
    return interestRate;
}
