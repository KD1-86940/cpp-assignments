#include<iostream>
using namespace std;
class Student
{
	   const int roll_no;
	   string name;
	   string gender;
	   int marks[3];
	   static int generate_roll_no;
	public :
		Student():roll_no(++generate_roll_no)
		{
			this->name="";
			this->gender="";
			for(int i=0;i<3;i++)
			   marks[i]=0;
		}
	    Student(string name,char gender,int m1,int m2,int m3):roll_no(++generate_roll_no)
	    {
	    	this->name=name;
	    	this->gender=gender;
	    	for(int i=0;i<3;i++)
			   marks[i]=0;
		}
		void setName(string name)
		{
			this->name=name;
		}
		void setGender(string gender)
		{
			this->gender=gender;
		}
		void setMarks(int n,int m,int o)
		{
			this->marks[0]=n;
			this->marks[1]=m;
			this->marks[2]=o;
		}
		string getName()
		{
			return name;
		}
		string getGender()
		{
			return gender;
		}
		void acceptPerson()
		{
		  string name,gender;
		  cout<<"------------------------------\n";
          cout<<"Enter Student Details :"<<endl;
          cout<<"\tName     : ";
          getline(cin,name);
          setName(name);
          cout<<"\tGender   : ";
          getline(cin,gender);
          setGender(gender);
          cout<<"Enter Marks   : "<<endl;
          for(int i=0;i<3;i++)
          {
          	cout<<"\tSubject "<<i+1<<" : ";
          	cin>>marks[i];
		  }
		  setMarks(marks[0],marks[1],marks[2]);
		  cout<<"------------------------------\n";
		}
		void printPerson()
		{
		  float n=0;
		  cout<<"------------------------------\n";
          cout<<"Student Details :"<<endl;
          cout<<"\tRoll no    : "<<roll_no<<endl;
          cout<<"\tName       : "<<getName()<<endl;
          cout<<"\tGender     : "<<getGender()<<endl;
          for(int i=0;i<3;i++)
          {
            cout<<"\tSubject "<<i+1<<"  : "<<marks[i]<<endl;
            n=n+marks[i];
          }
          
          cout<<"\tPercentage : "<<(n/300)*100<<endl;
          cout<<"------------------------------\n";
		}
		int menu()
        {
          int choice;
          cout<<"------------------------------";
          cout<<"\n\tMenu:\n\t1.Add Student\n\t2.Display Students\n\t3.Search Student\n\t4.Exit\nEnter Choice : ";
          cin>>choice;
          getchar();
          return choice;
        }
        bool searchStudent(string name)
        {
        	if(name==this->name)
        	    return true;
        	else
        	    return false;
		}
};
int Student::generate_roll_no = 86900;
int main()
{
	int choice,counter=0,size;
	string name;
	bool flag=false;
	cout<<"How many students are there : ";
	cin>>size;
	Student **ptr=new Student *[size];
	for(int i=0;i<size;i++)
	   ptr[i]=new Student;
	while((choice=ptr[counter]->menu())!=5)
	{
	    switch(choice)
	    {
	    	case 1 :ptr[counter++]->acceptPerson();
	                break;
	        case 2 :for(int i=0;i<counter;i++)
	                  ptr[i]->printPerson();
			        break;
	        case 3 :cout<<"\tEnter name of student to search : ";
                    getline(cin,name);
			        for(int i=0;i<size;i++)
			        {
			         flag=ptr[i]->searchStudent(name);
			         if(flag==true)
			           {
			           	cout<<"\nStudent record present on : "<<i<<endl;
			           	break;
					   }
			        }  
			        if(flag==false)
			          cout<<"Student Record is not present in list";
			        break;
	        default:cout<<"Enter a valid choice !"<<endl;
		}
	}
}
