#include<iostream>
using namespace std;
class Date{
	int day;
	int month;
	int year;
	public :
		Date()
		{
			day=0;
			month=0;
			year=0;
		}
		Date(int day,int month,int year)
		{
			this->day=day;
			this->month=month;
			this->year=year;
		}
		void setDay(int day)
		{
			this->day=day;
		}
		void setMonth(int month)
		{
			this->month=month;
		}
		void setYear(int year)
		{
			this->year=year;
		}
		int getDay()
		{
			return day;
		}
		int getMonth()
		{
			return month;
		}
		int getYear()
		{
			return year;
		}
		void acceptDate()
		{
          cout<<"Enter Birth Date :"<<endl;
          cout<<"\tDay    : ";
          cin>>day;
          setDay(day);
          cout<<"\tMonth  : ";
          cin>>month;
          setMonth(month);
          cout<<"\tYear   : ";
          cin>>year;
          setYear(year);
		}
		void PrintDate()
		{
			cout<<"\tBirthdate : "<<day<<"/"<<month<<"/"<<year;
		}
};
class Person
{
	string name;
	string address;
    Date d;
    public :
    	Person()
    	{
    		this->name="";
    		this->address="";
		}
		Person(string name,string address,int day,int month,int year)
		{
			this->name=name;
			this->address=address;
			this->d.setDay(day);
			this->d.setMonth(month);
			this->d.setYear(year);
		}
		void setName(string name)
		{
		    this->name=name;
		}
		void setAddress(string address)
		{
		    this->address=address;
		}
		string getName()
		{
			return name;
		}
		string getAddress()
		{
			return address;
		}
		void acceptPerson()
		{
		  cout<<"------------------------------\n";
          cout<<"Enter Person Details :"<<endl;
          cout<<"\tName     : ";
          getline(cin,name);
          setName(name);
          cout<<"\tAddress  : ";
          getline(cin,address);
          setAddress(address);
          d.acceptDate();
		}
		void printPerson()
		{
		  cout<<"------------------------------\n";
          cout<<"Person Details :"<<endl;
          cout<<"\tName     : "<<getName()<<endl;
          cout<<"\tAddress  : "<<getAddress()<<endl;
          d.PrintDate();
          cout<<"\n------------------------------\n";
		}
};
int main()
{
	Person p;
	p.acceptPerson();
	p.printPerson();
	return 0;
}
