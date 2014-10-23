// Account class header
// By Aleksey Leshchuk
// CISP400 AD5

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <Date.h>

class Account {
    public:
	// Account constructor. Arguments lastName, firstName, initial balance, openDate, updateDate
	Account(const char*, char*, const double&, const Date&, const Date&);
	// credit() adds an amount to the balance
	virtual void credit(const int&, const Date&);
	// debit(const int&, const Date&) debits account and updates the updateDate
	virtual void debit(const int&, const Date&);
	// getBalance() returns the current balance
	double getBalance() const;
	// print() displays the current account info
	virtual void print() const;
    private:
	// setLastName(std::string) validates and initalizes lastName
	void setLastName(const char*);
	// setFirstName(std::firstName) validates and sets firstName
	void setFirstName(const char*);
	// setBalance(count double&) validate and initialize balance
	void setBalance(const double*);
	std::string lastName;
	std::string firstName;
	double balance;
	const Date openDate;
	Date updateDate;
};
#endif
