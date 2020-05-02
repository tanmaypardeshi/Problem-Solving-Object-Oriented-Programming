/*
=======================================================================================
Roll No:- 23260
Batch:- H 10

Problem Definition:- Create a class named weaather report that holds a daily weather 
report with data members day_of_month, hightemp, lowtemp, amount_rain, amount_snow. 
Use different types of constructors to initialize the objects. Also include a function 
that prompts the user and sets the value for each field so that you can override the 
default values. Write a menu driven program in C++ with options toenter data and generate 
a monthly report that displays average of each attribute. (The contructor initialises the 
fields with default values: 99 for day_of_month, 999 for hightemp, -999 for lowtemp, and 
0 for amount_rain and amount_snow).

Date of Performance:- 20/06/2019
========================================================================================
*/
 
#include<iostream>
using namespace std;

float avgh=0,avgl=0,avgr=0,avgs=0;
int sumh=0,suml=0,sumr=0,sums=0,cntr=0;

class Weather
{
	int day_of_month;
	float hightemp,lowtemp,amount_rain,amount_snow;
	
	public:
		Weather()
		{
			day_of_month=99;
			hightemp=999;
			lowtemp=-999;
			amount_rain=0;
			amount_snow=0;
			
		}
		void update();
		void display();
		void average();
};

void Weather::update()
{
	cout<<"Enter day number:- ";
	cin>>day_of_month;
	cout<<"Enter highest and lowest temperature respectively:- ";
	cin>>hightemp>>lowtemp;
	cout<<"Enter amount of rain:- ";
	cin>>amount_rain;
	cout<<"Enter amount of snow:- ";
	cin>>amount_snow;
}

void Weather::display()
{
	static int i=1;
	cout<<i<<"\t"<<day_of_month<<"\t\t";
	cout<<hightemp<<"\t\t"<<lowtemp<<"\t\t";
	cout<<amount_rain<<"\t\t"<<amount_snow<<endl;
	i++;
	
}

void Weather::average()
{	
	if(day_of_month != 99)
	{
		cntr++;
		sumh+=hightemp;
		suml+=lowtemp;
		sumr+=amount_rain;
		sums+=amount_snow;
	}
	
	if(cntr>0)
	{
		avgh=(float)sumh/cntr;
		avgl=(float)suml/cntr;
		avgr=(float)sumr/cntr;
		avgs=(float)sums/cntr;
	}
}

int main()
{
	Weather w[30];
	int choice,i;
	
	while(1)
	{
		cout<<"\nWEATHER REPORT"<<endl;
		cout<<"1.Enter weather details"<<endl;
		cout<<"2.Display weather details"<<endl;
		cout<<"3.Average weather record"<<endl;
		cout<<"4.Exit"<<endl;

		cout<<"\nEnter your choice:- ";
		cin>>choice;
	
		switch(choice)
		{

			case 1:
				cout<<"Enter the position of record to be updated:- ";
				cin>>i;
				w[i-1].update();
				break;
			case 2:
				cout<<"\t\t                  WEATHER REPORT"<<endl;
				cout<<"-------------------------------------------------------------------------------------"<<endl;
				cout<<"Sr.no\tDay\t\tHightemp\tLowtemp";
				cout<<"\t\tRainfall\tSnowfall\n";
				cout<<"-------------------------------------------------------------------------------------"<<endl;
				for(i=0;i<30;i++)
					w[i].display();
				cout<<"-------------------------------------------------------------------------------------"<<endl;
				for(i=0;i<30;i++)
					w[i].average();
				cout<<"Average:- \t\t"<<avgh<<"\t\t"<<avgl<<"\t\t"<<avgr<<"\t\t"<<avgs<<endl;
				cout<<"-------------------------------------------------------------------------------------"<<endl;
				break;
			case 3:
				for(i=0;i<30;i++)
					w[i].average();
				cout<<"\nAverage high temperature:- "<<avgh<<endl;
				cout<<"Average low temperature:- "<<avgl<<endl;
				cout<<"Average rainfall:- "<<avgr<<endl;
				cout<<"Average snowfall:- "<<avgs<<endl;
				break;
			case 4:
				return 0;
		}
	}
	return 0;
}
