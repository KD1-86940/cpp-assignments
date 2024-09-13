#include<iostream>
using namespace std;
class Time{
	int hr;
	int min;
	int sec;
	public :
		Time()
		{
			hr=0;
			min=0;
			sec=0;
		}
		Time(int h,int m,int s)
		{
			this->hr=hr;
			this->min=min;
			this->sec=sec;
		}
		void setHr(int hr)
		{
			this->hr=hr;
		}
		void setMins(int min)
		{
			this->min=min;
		}
		void setSec(int sec)
		{
			this->sec=sec;
		}
		int getHr()
		{
			return hr;
		}
		int getMin()
		{
			return min;
		}
		int getSec()
		{
			return sec;
		}
		void acceptTime()
		{
	      cout<<"------------------------------\n";
          cout<<"Enter Time :"<<endl;
          cout<<"\tHours    : ";
          cin>>hr;
          setHr(hr);
          cout<<"\tMinutes  : ";
          cin>>min;
          setMins(min);
          cout<<"\tSeconds  : ";
          cin>>sec;
          setSec(sec);
		}
		void printTime()
        {
          cout<<"------------------------------\n";
          cout<<"\tTime : "<<hr<<":"<<min<<":"<<sec<<endl;
        }
};
int main()
{
	Time **ptr=new Time *[5];
	for(int i=0;i<5;i++)
	   ptr[i]=new Time;
	for(int i=0;i<5;i++)
	   ptr[i]->acceptTime();
	for(int i=0;i<5;i++)
	   ptr[i]->printTime();
	for(int i=0;i<5;i++)
	{
		delete ptr[i];
		ptr[i]=NULL;
	}
	delete ptr;
	ptr=NULL;
	return 0;
}
