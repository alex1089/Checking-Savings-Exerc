// Checking_Account.h class definition
// Aleksey Leshchuk CISP400

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h" // include parent class
#include "Date.h"   // include Date member object definition

class Checking_Account: public Account {
    public:
	// Checking_Account constructor, arguments: lName, fName, balance, fee, openDate, updateDate
	Checking_Account(const char*, const char*, const double&, const double&, const Date&, const Date&);
	// debit() overloaded debit charges transaction fee on sucessful debit
	bool debit(const double&, const Date&) final;
	// print display account information
	void print() const final;
	// charges a transaction fee from balance
	void chargeFee(const Date&);
	// setTransactionFee(double,Date) validates and sets the transaction fee
	void setTransactionFee(const double&, const Date&);
	// getTransactionFee() returns transaction fee
	double getTransactionFee() const;
    private:
	double transactionFee;
};

#endif
