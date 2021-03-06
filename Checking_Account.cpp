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
    bool success=false;	    // result of debit
    if (Account::debit(amount, updateDate)){ // if debit is successfull 
	chargeFee(updateDate);
	success=true;
    } 
    return success;	// retrun result of operation
}
void Checking_Account::print() const 
{
    cout<<"\nChecking Account:";
    Account::print();
    cout<<"\nTransaction Fee: $"<<getTransactionFee()<<endl;
}
// getTransactionFee() returns transaction fee
double Checking_Account::getTransactionFee() const 
{
    return transactionFee;
}
// chargeFee(Date) debits transactionFee from balance, prints confirmation
void Checking_Account::chargeFee(const Date& updateDate)
{
    if (Account::debit(transactionFee,updateDate)){    // if transfaction fee charged successfully
	cout<<"\n"<<getFirstName()<<" "<<getLastName();
	cout<<"\n$"<<transactionFee<<" transaction fee charged.\n";
    } else {
	cout<<"\nInsufficient funds, unable to charge transaction fee.\n\n";
    }
}
// setTransactionFee(double,Date) validates and sets the transaction fee
void Checking_Account::setTransactionFee(const double& transFee, const Date& updateDate)
{
    Account::setUpdateDate(updateDate); // update updateDate object
    if (transFee<0.0){	    // if transaction fee is less than 0
	cout<<Account::getFirstName()<<" "<<Account::getLastName()<<endl;
	cout<<"\nTransaction fee cannot be less than $0.00"<<endl<<endl;
	transactionFee=0.0;
    } else {		// if transaction fee is valid
	transactionFee=transFee;
    }
}
