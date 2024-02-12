/*
 Program Name: BankAccount.cpp
 Programmer: Moris
 Date: Saturday 02/10/2024
 Version Control: 1.0
 About: Week 1, CSCI 2.
 Description: Write class Bank Account w/ 2 private members: account # and account balance. we withdraw and deposit money and display balance.
*/

#include <iostream>
#include <string>
#include <iomanip> //for balance cout line 77-78.
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    double balance;
    
public:
    //create default constructor:
    BankAccount()
    {
        accountNumber = "None";
        balance = 0.0;
    } //end default constructor.
    
    //create constructor w/ 2 arguments:
    BankAccount(string accNo, double bal)
    {
        accountNumber = accNo;
        balance = bal;
    } //end default constructor.e
    
    //create accessors for each private member:
    string getAccountNumber()
    {
        return accountNumber; //from private members.
    }
    double getBalance()
    {
        return balance; //from private members.
    }
    
    //create mutators for each private member:
    void setBalance(double b)
    {
        balance = b;
    }
    void setAccountNumber(string acc)
    {
        accountNumber = acc; // modify to whatever acc is when called.
    }
    
    //deposit: still a mutator bc it changes a private member?
    void deposit(double amount)
    {
        balance = balance + amount;
    }
    
    //withdraw: still a mutator bc it changes a private member?
    void withDraw(double money)
    {
        if (balance < money)
        {
            cout << "insufficient funds." << endl;
        }
        else
        {
            balance = balance - money;
        }
    }
    
    //display balance and account number after transactions.
    void display()
    {
        cout << "account #: " << accountNumber << endl;
        cout << "balance: $" << balance << endl;
        
        //same as line 75 but making sure we get the 2 digits after decimal bc money units:
        cout << "balance: $" << fixed << setprecision(2) << balance << endl;
        
    }
}; //end BankAccount class.




int main() 
{
    BankAccount myAccount("12345", 150000); //construc w/ 2 arguments.
    myAccount.display();
    cout << "-------" << endl;
    
    //withraw 300,000.
    myAccount.withDraw(300000.00);
    myAccount.display();
    cout << "-------" << endl;
    
    //make new object w/ default constructor for user input:
    BankAccount myAccount2;
    
    string userAcc;
    double userBal;
    
    cout << "enter account number:";
    cin >> userAcc;
    cout << "enter balance:";
    cin >> userBal;
    
    myAccount2.setAccountNumber(userAcc);
    myAccount2.setBalance(userBal);
    myAccount2.display();
    cout << "-------" << endl;
    
    double userDepo;
    cout << "how much do you want to deposit?";
    cin >> userDepo;
    myAccount2.deposit(userDepo);
    myAccount2.display();
    
    return 0;
}
