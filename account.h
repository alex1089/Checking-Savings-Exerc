// Account class header
// By Aleksey Leshchuk
// CISP400 AD5

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Date.h"

class Account {
    public:
	// Account constructor. Arguments lastName, firstName, initial balance, openDate, updateDate
	Account(const char*, const char*, const double&, const Date&, const Date&);
	// credit() adds an amount to the balance
	virtual bool credit(const double&, const Date&);
	// debit(const int&, const Date&) debits account and updates the updateDate
	virtual bool debit(const double&, const Date&);
	// getBalance() returns the current balance
	double getBalance() const;
	// print() displays the current account info
	virtual void print() const;
	// getFirstName() returns firstName string object
	std::string getFirstName() const;
	// getLastName() returns lastName string object
	std::string getLastName() const;
    private:
	// setLastName(std::string) validates and initalizes lastName
	void setLastName(const char*);
	// setFirstName(std::firstName) validates and sets firstName
	void setFirstName(const char*);
	// setBalance(count double&) validate and initialize balance
	void setBalance(const double&);
	std::string lastName;
	std::string firstName;
	double balance;
	const Date openDate;
	Date updateDate;
};
#endif
