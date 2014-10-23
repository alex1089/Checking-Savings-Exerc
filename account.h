// Aleksey Leshchuk
// Account class implementation
// CISP400 AD5

#include "Date.h"
#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Account constructor. Arguments lastName, firstName, initial balance, openDate, updateDate
Account::Account(const char* lName, const char* fName, const double& bal, const Date& sDate, const Date& uDate):
    openDate(sDate),
    updateDate(uDate)
{
    setLastName(lName);
    setFirstName(fName);
    setBalance(bal);
}

// credit() adds an amount to the balance, throws invalid argument on error
void Account::credit(const int& amount, const Date& uDate){
    if (amount>0 && uDate>updateDate){ // if date and amount are valid
	balance+=amount;   // add amount to balance if positive number entered 
    } else {
	throw invalid_argument("\nInvalid credit argument for: "<<firstName<<" "<<lastName<<"\n");
    }
}
// debit(const int&, const Date&) debits account and updates the updateDate
void Account::debit(const int& amount, const Date& uDate);
// getBalance() returns the current balance
double Account::getBalance() const;
// print() displays the current account info
void Account::print() const;
// setLastName(std::string) validates and initalizes lastName
void Account::setLastName(const char* lName);
// setFirstName(std::firstName) validates and sets firstName
void Account::setFirstName(const char* fName);
// setBalance(count double&) validate and initialize balance
void Account::setBalance(const double& bal);
