#include"class.h";

BankAccount::BankAccount()
{
	CustomerName="";
	CustomerID=-1;
	Currbalance=0;
	transactions=nullptr;
	numberoftransactions=0;
	maxtransactions=0;
}

BankAccount::BankAccount(string name,int id,float balance)
{
	CustomerName=name;
	CustomerID=id;
	Currbalance=balance;
	balancelimit=200000;
	transactions=new float [10];
	numberoftransactions=0;
	maxtransactions=10;
}

void BankAccount::increaseTranCapacity()
{
	float * temp=new float [maxtransactions*2];
	for(int i=0;i<numberoftransactions;i++)
	{
		temp[i]=transactions[i];
	}
	temp=transactions;
	delete [] transactions;
}

void BankAccount::printaccount()
{
	cout<<"Account Holders Name :"<<CustomerName<<endl;
	cout<<"Account Holders ID :"<<CustomerID<<endl;
	cout<<"Current Balance :"<<Currbalance<<endl;
	cout<<"Number of Transactions :"<<numberoftransactions<<endl;
	cout<<"transactions :"<<endl;
	for(int i=0;i<numberoftransactions;i++)
	{
		cout<<transactions[i]<<" ";
	}
	cout<<endl;
}

void BankAccount::addintransitions(float ammount)
{
	if(numberoftransactions>=maxtransactions)
	{
	increaseTranCapacity();
	transactions[numberoftransactions]=ammount;
	numberoftransactions++;
	maxtransactions=maxtransactions*2;
	}
	else
	{
	transactions[numberoftransactions]=ammount;
	numberoftransactions++;
	}
}

void BankAccount::withdraw(float ammount)
{
	if(ammount<Currbalance)
	{
		Currbalance=Currbalance-ammount;
		addintransitions(-ammount);
        cout<<"Transaction Successful"<<endl;	
	}
	else
	cout<<"Transaction Unsuccessful: Insufficient balance"<<endl;
}

void BankAccount::deposit(float ammount)
{
	if(ammount+Currbalance<=balancelimit)
	{
		Currbalance=Currbalance+ammount;
		addintransitions(+ammount);
        cout<<"Transaction Successful"<<endl;	
	}
	else
	cout<<"Transaction Unsuccessful: Insufficient balance"<<endl;
}

void BankAccount::changebalanceLimit(float ammount)
{
	cout<<"Your balance limit has been changed Successfully"<<endl;
	Currbalance=ammount;
}

BankAccount::~BankAccount()
{
	delete [] transactions;
}