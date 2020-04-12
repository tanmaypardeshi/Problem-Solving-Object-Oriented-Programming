/* 
===============================================================================================================
Roll number:- 23260
Batch:- H 10

Problem Definition:- Write a program in C++ which inlcudes the code for the following operations:
i.   A function to read two double type values from the keyboard.
ii.  A function to calculate division the division of these two numbers.
iii. A try block to detect and throw an execution if the condition of "divide by zero" occurs
iv.  Appropriate catch block to handle the exception

Date of Performance:- 12/09/2019

===============================================================================================================
*/

#include<iostream>
using namespace std;


class Division
{
	double dividend,divisor;
	
	public:
		void getdata();
		void display(double );
		double divide();
};

void Division::getdata()
{
	cout<<"Enter the value of dividend:- ";
	cin>>dividend;
	cout<<"Enter the value of divisor:- ";
	cin>>divisor;
}


void Division::display(double quotient)
{
	cout<<dividend<<" / "<<divisor<<" = "<<quotient<<"\n"<<endl;
}

double Division::divide()
{
	if(divisor==0)
		throw -1;
	return double(dividend/divisor);
}


int main()
{
	Division objd;
	double quotient;
	int choice,i;
	
	while(1)
	{
		cout<<"Exception Handling Example"<<endl;
		cout<<"1. Divide two numbers"<<endl;
		cout<<"2. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				objd.getdata();
				try
				{
					quotient = objd.divide();
					objd.display(quotient);
				}
				catch(int i)
				{
					if(i==-1)
					{
						cout<<"\nDivide by zero error"<<endl;
						cout<<"Please enter new numbers\n"<<endl;
					}
				}
				break;
			case 2:
				return 0;
			default:
				cout<<"Error in choice, try again"<<endl;
		}
	}
}
				
		
	
		
