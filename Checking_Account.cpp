// Checking_Account.cpp class implementation
// Aleksey Leshchuk CISP400

#include "Checking_Account.h"
#include <iostream> 
#include <iomanip>
using namespace std;

// constructor initializes all data members
Checking_Account::Checking_Account(
	const char* lName,	    // lastName
	const char*fName,	    // firstName
	const double& balance,	    // balance
	const double& fee,	    // fee 
	const Date& openDate,	    // openDate
	const Date& updateDate):    // updateDate
    Account(lName, fName, balance, openDate, updateDate)
{
    setTransactionFee(fee, updateDate);	    // validate and set transaction fee 
}
bool Checking_Account::debit(const double& amount, const Date& updateDate)
{
    if (Account::debit(amount, updateDate)) // if debit is successfull 
	chargeFee();
}
void Checking_Account::print() const 
{
    cout<<"\nChecking Account:\n";
    Account::print();
    cout<<"Transaction Fee: $"<<getTransactionFee();
}
// getTransactionFee() returns transaction fee
double Checking_Account::getTransactionFee() const 
{
    return transactionFee;
}
// chargeFee() debits transactionFee from balance, prints confirmation
void Checking_Account::chargeFee()
{
    if (Account::debit(transactionFee,getUpdateDate())){    // if transfaction fee charged successfully
	cout<<"\n $"<<transactionFee<<" transaction fee charged.\n";
    } else {
	cout<<"\nInsufficient funds, unable to charge transaction fee.\n";
    }
}
// setTransactionFee(double,Date) validates and sets the transaction fee
void Checking_Account::setTransactionFee(const double& transFee, const Date& updateDate)
{
}
 
