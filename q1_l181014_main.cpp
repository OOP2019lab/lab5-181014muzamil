#include"class.h";

int main(){
	BankAccount myAccount("JohnDeo",549002,2000);
	myAccount.withdraw(500);
	myAccount.deposit(2000);
	myAccount.deposit(7000);
	myAccount.deposit(5000);
	myAccount.withdraw(1000);
	myAccount.deposit(1000);
	myAccount.withdraw(2000);
	myAccount.deposit(50000);
	myAccount.printaccount();
	system("pause");
}