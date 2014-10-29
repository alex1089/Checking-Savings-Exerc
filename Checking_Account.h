// Checking_Account.h class definition
// Aleksey Leshchuk CISP400

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h" // include parent class
#include "Date.h"   // include Date member object definition

class Checking_Account: Account {
    public:
	// Checking_Account constructor, arguments: lName, fName, balance, fee, openDate, updateDate
	Checking_Account(const char*, const char*, const double&, const double&, const Date&, const Date&);
	bool debit(const double&, const Date&) final;
	void print() const final;
	void chargeFee();
	// setTransactionFee(double,Date) validates and sets the transaction fee
	void setTransactionFee(const double&, const Date&);
	// getTransactionFee() returns transaction fee
	double getTransactionFee() const 
    private:
	double transactionFee;
};

#endif
