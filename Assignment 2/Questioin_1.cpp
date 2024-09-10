#include<stdio.h>
#include<conio.h>
struct Date{
	int day;
	int month;
	int year;
};
void initDate(struct Date* ptrDate); 
void printDateOnConsole(struct Date* ptrDate); 
void acceptDateFromConsole(struct Date* ptrDate); 
int main()
{
	int choice=1;
	struct Date d1;
	initDate(&d1);
	while(choice!=0)
	{
		printf("\----------------------------------------------");
		printf("\n\tMenu:\n\t1.Set Date\n\t2.Display Date\n\t3.Exit\nEnter Choice : ");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1 :acceptDateFromConsole(&d1);
	    	        break;
	        case 2 :printDateOnConsole(&d1);
	                break;
	        case 3 :printf("----------------- Exit program ----------------------\n");
	                break;
	        default:printf("Enter a valid choice !");
		}
	}
	
}

void initDate(struct Date* ptrDate)
{
 	ptrDate->day=0;
	ptrDate->month=0;
	ptrDate->year=0;	
}

void acceptDateFromConsole(struct Date* ptrDate)
{
	printf("-------------------------------------------\n");
	printf("Enter Current Date :\n");
	printf("\tDay : ");
	scanf("%d",&ptrDate->day);
	printf("\tMonth : ");
	scanf("%d",&ptrDate->month);
	printf("\tYear : ");
	scanf("%d",&ptrDate->year);
	if(ptrDate->day<=31 && ptrDate->month<=12 && ptrDate->year==2024){
		printf("Date and Time updated.\n");
     }
    else{
         printf("Please Enter valid date and time.\n");
         acceptDateFromConsole(ptrDate);
	    } 
}

void printDateOnConsole(struct Date* ptrDate)
{
  	printf("------------------------------------------\n");
  	printf("\tCurrent Date : %d/%d/%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}
