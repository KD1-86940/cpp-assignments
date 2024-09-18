#include<iostream>
using namespace std;
int accTypemenu();
enum accTypeMenu
{
    Saving=1,
	Current=2,
	Dmat=3
};
class InsufficientFundsException
{
	int accno;
	double currentBalance;
	double withdrawAmount;
	public : 
	    InsufficientFundsException(int accno,double currentBalance,double withdrawAmount)
	    {
	    	this->accno=accno;
	    	this->currentBalance=currentBalance;
	    	this->withdrawAmount=withdrawAmount;
		}
		void display()
		{
			if(withdrawAmount<0)
			  cout<<"Amount is negative ("<<withdrawAmount<<" )."<<endl;
			if(currentBalance<withdrawAmount)
			{
				cout<<"Sufficient balance is not available ("<<currentBalance<<" )."<<endl;
			}
		}
};
class Account
{
	const int accno;
	string accountType;
	double balance;
	static int generateAccNO;
	public : 
	    Account():accno(++generateAccNO)
	    {
	    	this->accountType;
	    	this->balance;
		}
		Account(string accountType,double balance):accno(++generateAccNO)
	    {
	    	this->accountType=accountType;
	    	this->balance=balance;
		}
		void setAccountType(string accountType)
		{
			this->accountType=accountType;
		}
		void setBalance(double balance)
		{
			this->balance=balance;
		}
		string getAccountType()
		{
			return accountType;
		}
		double getBalance()
		{
			return balance;
		}
		int getAccno()
		{
			return accno;
		}
		void accept()
		{
			int choice;
			double balance;
			string accountType;
			cout<<"Enter Account Details : "<<endl;
			cout<<"\tAccount Number  : "<<getAccno()<<endl;
			cout<<"\tAccount Type    : "<<endl;
			choice=accTypemenu();
			    switch(accTypeMenu(choice))
			    {
				    case Saving :accountType="Saving";
				                break;
	                case Current:accountType="Current";
				                break;
	                case Dmat   :accountType="Dmat";
				                break;
				    default     :accountType="Not Defined";
				                break;
			    }
		    setAccountType(accountType);
			cout<<"\tAccount Balance : ";
			cin>>balance;
			setBalance(balance);
		}
		void display()
		{
			
		    cout<<"Account Details : "<<endl;
			cout<<"\tAccount Number  : "<<getAccno()<< endl;
			cout<<"\tAccount Type    : "<<getAccountType()<< endl;
			cout<<"\tAccount Balance : "<<getBalance()<< endl;	
		}
		void deposit(double amount)
		{
			double balance=getBalance();
			if(amount<0)
			  throw InsufficientFundsException(accno,balance,amount);
			else
			{
				balance=balance+amount;
				setBalance(balance);
				cout << "********************************" << endl;
				cout<<"Amount Deposited"<<endl;
			}
		}
		void withdraw(double amount)
		{
			double balance=getBalance();
			if(balance<amount)
			  throw InsufficientFundsException(accno,balance,amount);
			else
			{
				balance=balance-amount;
				setBalance(balance);
				cout << "********************************" << endl;
				cout<<"Amount withdrawed"<<endl;
			}
		}
};
int Account :: generateAccNO=1000;
enum aMenu
{
	EXIT,
    Accept,
	Deposit,
	Withdraw,
	Display
};
int amenu()
{
    int choice;
    cout << "********************************" << endl;
    cout << "How can i help you....? " << endl;
    cout << "\t0. Exit" << endl;
    cout << "\t1. Create New Account" << endl;
    cout << "\t2. Deposit Money" << endl;
    cout << "\t3. Withdraw Money" << endl;
    cout << "\t4. Display Account Details" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << "********************************" << endl;
    return choice;
}
int accTypemenu()
{
    int choice;
    cout << "\t-------------------------------" << endl;
    cout << "\tChoose Type of Account....? " << endl;
    cout << "\t\t1. Saving" << endl;
    cout << "\t\t2. Current" << endl;
    cout << "\t\t3. Dmat" << endl;
    cout << "\tEnter your choice - ";
    cin >> choice;
    cout << "\t-------------------------------" << endl;
    return choice;
}
int findAccount(Account *arr[], int index)
{
	int an;
	cout<<"Enter Your Account Number : ";
	cin >> an;
	for(int i=0;i<=index;i++)
	{
		if(an == arr[i]->getAccno())
		return i;
	}
	return -1;
}
int main()
{
	Account *arr[5];
	int index=0,choice,temp=0;
	double balance,amount;
		while((choice=amenu())!=EXIT)
		{
			try
			{
			switch(aMenu(choice))
			{
				case Accept:if(index<5)
				            {
					            arr[index] = new Account(); 
				                arr[index]->accept();
				            }
				            else
				                cout<<"Account Registration Closed"<<endl;
				                break;
	            case Deposit:temp=findAccount(arr,index);
				            if(temp!=-1)
				            {
				            	cout<<"Enter Amount to Deposit : ";
				                cin>>amount;
				                arr[temp]->deposit(amount);
							}
							else
							    cout<<"Enter a valid account number."<<endl;
				            break;
	            case Withdraw:temp=findAccount(arr,index);
				            if(temp!=-1)
				            {
				            	cout<<"Enter Amount to Withdraw : ";
				                cin>>amount;
				                arr[temp]->withdraw(amount);
							}
							else
							    cout<<"Enter a valid account number."<<endl;
				            break;
				case Display :temp=findAccount(arr,index);
				            if(temp!=-1)
				            {
				                arr[temp]->display();
							}
							else
							    cout<<"Enter a valid account number."<<endl;
				            break;
				default:cout << "Invalid choice ! " << endl;
                            break;
			}
		    }
		    catch(InsufficientFundsException e)
	        {
	          	e.display();
	        }
	   }
	
	
}
