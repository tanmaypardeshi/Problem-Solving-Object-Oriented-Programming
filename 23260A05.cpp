/*
=============================================================================================
Roll No:- 23260
Batch:- H 10

Problem Definition:- Multiple Inheritance
Create employee bio-data using following classes
i. Personal record 
ii. Professional record 
iii. Academic record 
Assume appropriate data members and member function to accept required
data & print bio-data. Create bio-data using multiple inheritance using C++.

Date of Performance:- 29/08/2019
============================================================================================
*/

#include<iostream>
#include<iomanip>
#define SIZE 50
using namespace std;

class Personal
{
	char name[SIZE];
	int age;
	
	protected:
		void get_data();
		void put_data();
};

class Professional
{
	int id;
	float salary;
	
	protected:
		void get_data();
		void put_data();
};

class Academic
{
	float percentage;
	int marks;
	
	protected:
		void get_data();
		void put_data();
};

class Derived: public Personal,public Professional,public Academic
{
	public:
		void get_data();
		void put_data();
};

void Personal::get_data()
{
	cin.ignore();
	cout<<"Enter the name:- ";
	cin.getline(name,SIZE);
	cout<<"Enter the age:- ";
	cin>>age;
}

void Personal::put_data()
{
	cout<<name<<"  "<<age<<"     ";
}

void Professional::get_data()
{
	cout<<"Enter ID:- ";
	cin>>id;
	cout<<"Enter the salary:- ";
	cin>>salary;
}

void Professional::put_data()
{
	cout<<id<<"\t  "<<salary<<"\t";
}

void Academic::get_data()
{
	cout<<"Enter the percentage:- ";
	cin>>percentage;
	cout<<"Enter the marks:- ";
	cin>>marks;
}

void Academic::put_data()
{
	cout<<percentage<<"         "<<marks<<"     "<<endl;
}

void Derived::get_data()
{
	Personal::get_data();
	Professional::get_data();
	Academic::get_data();
}

void Derived::put_data()
{
	Personal::put_data();
	Professional::put_data();
	Academic::put_data();
}

int main()
{
	int choice,i,j,cntr,ins_no,flag;
	Derived d[SIZE];
	char ask;
	
	while(1)
	{
		cout<<"\nRecords Database"<<endl;
		cout<<"1. Add a master table"<<endl;
		cout<<"2. Display record"<<endl;
		cout<<"3. Insert a record"<<endl;
		cout<<"4. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				ask = 'y';
				cntr=0;
				while(ask =='y' || ask=='Y')
				{
					if(cntr<SIZE)
					{
						d[cntr].get_data();
						cout<<"\nDo you want to add another record?(y/n):- ";
						cin>>ask;
						cntr++;					
					}					
				}
				if(cntr>=SIZE)
					cout<<"No more records can be added"<<endl;
				break;
			
			case 2:
				if(cntr==0)
					cout<<"\nPlease enter a record first"<<endl;
				else
				{
					cout<<"\n-----------------------------------------------------------------------------------------------------------"<<endl;
					cout<<"Sr No. "<<setw(5)<<"Name  ";
					cout<<"Age   "<<"ID\t  ";   
					cout<<"Salary\t"<<"Percentage  ";
					cout<<"Marks  "<<endl;
						cout<<"\n----------------------------------------------------------------------------------------------------------"<<endl;
					for(i=0;i<cntr;i++)
					{	
						cout<<"  "<<i+1<<"  ";
						d[i].put_data();
					}
				}
				break;
			
			case 3:
				cout<<"Enter the details of the record you want to insert:- "<<endl;
				d[cntr].get_data();
				cntr++;
				cout<<"Record inserted successfully"<<endl;;
				break;
			case 4:
				return 0;
			
			default:
				cout<<"Error in choice,try again"<<endl;
		}
	}								
	return 0;
}
				
	

