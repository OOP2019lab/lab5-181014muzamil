#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
string CustomerName;
int CustomerID;
float Currbalance;
float balancelimit;
float * transactions;
int maxtransactions;
int numberoftransactions;

public:
	void withdraw(float ammount);
	void deposit(float ammount);
	BankAccount();
	BankAccount(string name,int id,float balance=0);
	~BankAccount();
	void addintransitions(float ammount);
	void printaccount();
	void increaseTranCapacity();
	void changebalanceLimit(float ammount);
};