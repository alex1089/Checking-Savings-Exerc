// CISP400 AD5 driver program
// Aleksey Leshchuk
// tests Savings_Account and Checking_Account classes
//
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Account.h"
#include "Date.h"
#include <iostream>
using namespace std;

int main(){
    // initialize 10 Account objects
    Date May5th2014(5,5,2014);
    Account *account_array[10];
    account_array[0]= new Savings_Account("Baker","Susan",25,0.03,Date(1,1,2009),Date(2,19,2010));
    account_array[1]= new Checking_Account("Jones","Robert",80,1,Date(2,29,2011),Date(3,19,2011));
    account_array[2]= new Savings_Account("Zulueta","Chao",100,0.04,Date(5,31,2013),Date(6,14,2014));
    account_array[3]= new Checking_Account("Ramirez","Kenneth",250,2,Date(6,6,2009),Date(12,12,2013));
    account_array[4]= new Savings_Account("Thomas","Vue",125,0.02,Date(11,30,2010),Date(2,24,2011));
    account_array[5]= new Checking_Account("Wilma","Angela",180,3,Date(3,27,2009),Date(2,19,2010));
    account_array[6]= new Savings_Account("Turner","Romeo",600,0.04,Date(4,19,2005),Date(3,19,2009));
    account_array[7]= new Checking_Account("Untalasco","Jimmy",255,3,Date(7,32,2009),Date(7,32,2009));
    account_array[8]= new Savings_Account("Udonkanga","Oscar",95,0.02,Date(10,10,2003),Date(5,6,2007));
    account_array[9]= new Checking_Account("Trocino","Terrence",80,1,Date(11,16,2009),Date(4,4,2011));

    // print all initialized accounts
    cout<<"\n*** Initial Account Information ***";
    for (const Account *i:account_array)
	i->print();

    // display adjustments to the accounts on 5/5/2014
    cout<<"\nOn 5/5/2014 accounts adjusted based on the following schedule:";
    cout<<"\n1. Susan Baker had a $40 debit.";
    cout<<"\n2. Robert Jones had a $40 debit.";
    cout<<"\n3. Chao Zulueta had a $30 credit.";
    cout<<"\n4. Kenneth Ramirez had a $50 credit.";
    cout<<"\n5. Vue Thomas had accrued interest for a period.";
    cout<<"\n6. Angela Wilma had a transaction fee charged.";
    cout<<"\n7. Romeo Turner had accrued interest for a period.";
    cout<<"\n8. Jimmy Untalaso had a transaction fee charged.";
    cout<<"\n9. Oscar Udonkanga had a $60 debit.";
    cout<<"\n10. Trocino Terrence had a $100 debit.\n";
    
    // make adjustments to each account
    account_array[0]->debit(40,May5th2014);
    account_array[1]->debit(40,May5th2014);
    account_array[2]->credit(30,May5th2014);
    account_array[3]->credit(50,May5th2014);
    // cast to call Savings_Account method on a base class pointer
    dynamic_cast<Savings_Account*>(account_array[4])->addInterest(May5th2014);
    // cast to call Checking_Account method on base class pointer
    dynamic_cast<Checking_Account*>(account_array[5])->chargeFee(May5th2014);
    // cast to call Savings_Account method on a base class pointer
    dynamic_cast<Savings_Account*>(account_array[6])->addInterest(May5th2014);
    // cast to call Checking_Account method on a base class pointer
    dynamic_cast<Checking_Account*>(account_array[7])->chargeFee(May5th2014);
    account_array[8]->debit(60,May5th2014);
    account_array[9]->debit(100,May5th2014);

    cout << "\n\n***After the 5/5/2014 update, the Accounts information***\n";
    // display account information for all accounts
    for (const Account* i:account_array)
	i->print();
    
    cout<<"\nOn 8/8/2013 all the saving used the same interest rate(0.05) and all the checking used the same transaction fee($5).\n"; 
    cout << "\n\n***After the 8/8/2013 update,\nthe Accounts information***\n";
    for ( Account* i:account_array){
	if ((dynamic_cast<Savings_Account*>(i))!=nullptr){
	    dynamic_cast<Savings_Account*>(i)->setInterestRate(0.05,Date(8,8,2013));
	} else {
	    dynamic_cast<Checking_Account*>(i)->setTransactionFee(5,Date(8,8,2013));
	}
	i->print();
    }
    
    for (Account* i:account_array){	// deallocate all account objects off heap
	delete i;
	i=nullptr;
    }
    return 0;
}
