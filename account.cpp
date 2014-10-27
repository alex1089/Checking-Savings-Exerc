// Aleksey Leshchuk
// Account class implementation
// CISP400 AD5

#include "Date.h"
#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>  // for strlen()
using namespace std;


// Account constructor. Arguments lastName, firstName, initial balance, openDate, updateDate
Account::Account(const char* lName, const char* fName, const double& bal, const Date& sDate, const Date& uDate):
    openDate(sDate),	// initialize start date
    updateDate(uDate)	// initialize last updateDate
{
    setLastName(lName);
    setFirstName(fName);
    setBalance(bal);
}

// credit() adds an amount to the balance, throws invalid argument on error
bool Account::credit(const double& amount, const Date& uDate){
	updateDate=uDate;   // update the date of update
    if (amount>0){ // if is valid
	balance+=amount;   // add amount to balance if positive number entered 
	return true;
    } else {
	return false;
    }
}
// debit(const int&, const Date&) debits account and updates the updateDate
bool Account::debit(const double& amount, const Date& uDate){
    updateDate=uDate;
    if (amount>=balance){
	balance+=amount;
	return true;
    } else {
	return false;
    }
}
// getBalance() returns the current balance
double Account::getBalance() const{
    return balance;
}
// print() displays the current account info
void Account::print() const{
    cout<<firstName<<" "<<lastName<<endl;
    cout<<"\nA/C Open "; openDate.print();
    cout<<"\nA/C Updated "; updateDate.print();
    cout<<"\nA/C Balance "<<balance<<endl;
}
// setLastName(std::string) validates and initalizes lastName
void Account::setLastName(const char* lName){
    if (strlen(lName)<=15) // limit last name for 15 characters
	lastName.assign(lName);
    else 
	lastName.assign(lName,15);
}
// setFirstName(std::firstName) validates and sets firstName
void Account::setFirstName(const char* fName){
    if (strlen(fName)<=10) // limit first name to 10 chars
	firstName.assign(fName);
    else 
	firstName.assign(fName,10);
}
// setBalance(count double&) validate and initialize balance
void Account::setBalance(const double& bal){
    if (bal>0){		// if balance is more than 0
	balance=bal;
    }else {
	balance=0.0;
	cout<<"Invalid balance entered, reset to $0.0\n";
    }
}
// getFirstName() returns firstName string object
std::string Account::getFirstName() const{
    return firstName;
}
// getLastName() returns lastName string object
std::string Account::getLastName() const{
    return lastName;
}
