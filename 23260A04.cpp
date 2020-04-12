/*
=============================================================================================
Roll No:- 23260
Batch:- H 10

Problem Definition:- Design a base class with name, date of birth, blood group and another 
base class consisting of the data members such as height and weight. 
Design one more base class consisting of the insurance policy number and contact address. 
The derived class contains the data members’ telephone numbers and driving license number.
Write a menu driven program to carry out the following things:
i. Build a master table
ii.  Display Record
iii.  Insert  a record
iv.  Delete record
v.  Edit  record
vi.  Search  for a record

Date of Performance:- 22/08/2019
============================================================================================
*/

#include<iostream>
#include<iomanip>
#define SIZE 50
using namespace std;


class Base1
{
	char name[SIZE];
	int dd,mm,yyyy;
	char blood_grp[10];
	
	protected:
		void get_data();
		void put_data();
};

class Base2
{
	float weight,height;
	
	protected:
		void get_data();
		void put_data();
};

class Base3
{
	int insurance_number;
	char address[SIZE];
	
	protected:
		void get_data();
		void put_data();
		int get_insurance();
		void modify();
};

class Derived: public Base1,public Base2,public Base3
{
	long telephone;
	int driving;
	
	public:
		void get_data();
		void put_data();
		void modify();
		int get_insurance();
};

void Base1::get_data()
{
	cin.ignore();
	cout<<"Enter the name:- ";
	cin.getline(name,SIZE);
	cout<<"Enter date of month:- ";
	cin>>dd;
	cout<<"Enter month number:- ";
	cin>>mm;
	cout<<"Enter the the year of birth:- ";
	cin>>yyyy;
	cin.ignore();
	cout<<"Enter the blood group:- ";
	cin.getline(blood_grp,SIZE);
}

void Base1::put_data()
{
	cout<<name<<"  "<<dd<<"/"<<mm<<"/"<<yyyy<<"  "<<blood_grp<<"         ";
}

void Base2::get_data()
{
	cout<<"Enter weight in kilograms:- ";
	cin>>weight;
	cout<<"Enter height in centimetres:- ";
	cin>>height;
}

void Base2::put_data()
{
	cout<<weight<<"         "<<height<<"         ";
}

void Base3::get_data()
{
	cout<<"Enter the insurance number:- ";
	cin>>insurance_number;
	cin.ignore();
	cout<<"Enter the address:- ";
	cin.getline(address,SIZE);
}

void Base3::put_data()
{
	cout<<insurance_number<<"         "<<address<<"     ";
}


int Base3::get_insurance()
{
	return insurance_number;
}

void Base3::modify()
{
	cin.ignore();
	cout<<"Enter the address:- ";
	cin.getline(address,SIZE);
}

void Derived::get_data()
{
	Base1::get_data();
	Base2::get_data();
	Base3::get_data();
	
	cout<<"Enter the telephone number:- ";
	cin>>telephone;
	cout<<"Enterthe driving license number:- ";
	cin>>driving;
}

void Derived::put_data()
{
	Base1::put_data();
	Base2::put_data();
	Base3::put_data();
	
	cout<<telephone<<"  "<<driving<<endl;
}

void Derived::modify()
{
	Base1::get_data();
	Base2::get_data();
	Base3::modify();
	
	cout<<"Enter the telephone number:- ";
	cin>>telephone;
	cout<<"Enterthe driving license number:- ";
	cin>>driving;
}

int Derived::get_insurance()
{
	return Base3::get_insurance();
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
		cout<<"4. Delete a record"<<endl;
		cout<<"5. Edit a record"<<endl;
		cout<<"6. Search a record"<<endl;
		cout<<"7. Exit program"<<endl;
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
					cout<<"DoB  "<<"Blood Group  ";
					cout<<"Weight(kg)  "<<"Height(cm)  ";
					cout<<"Insurance No.  "<<"Address  ";
					cout<<"Telephone No.  "<<"License No.  "<<endl;
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
				cout<<"Enter the insurance number to record you want to delete:- ";
				cin>>ins_no;
				flag=0;
				for(i=0;i<cntr;i++)
				{
					if(ins_no == d[i].get_insurance())
					{
						flag=1;
						for(j=i;j<cntr;j++)
						{
							d[j]=d[j+1];
						}
						cntr--;
						cout<<"Record with insurance number "<<ins_no<<" deleted successfully"<<endl;
						
					}
				}
				if(!flag)
					cout<<"Record with insurance number "<<ins_no<<" not found"<<endl;				
				break;
			
			case 5:
				cout<<"Enter the insurance number of record you want to edit:- "<<endl;
				cin>>ins_no;
				flag=0;
				for(i=0;i<cntr;i++)
				{
					if(ins_no==d[i].get_insurance())
					{
						flag=1;
						cout<<"Enter new details for insurance number "<<ins_no<<":- "<<endl;
						d[i].modify();
					}
				}
				if(!flag)
					cout<<"The record with insurance number "<<ins_no<<" was not found"<<endl;
				break;
			
			case 6:
				cout<<"Enter the insurance number of record you want to search:- "<<endl;
				cin>>ins_no;
				flag=0;
				for(i=0;i<cntr;i++)
					if(ins_no==d[i].get_insurance())
					{
						cout<<"Search successful! Record with insurance number "<<ins_no<<" found"<<endl;
						flag=1;
					}
				if(!flag)
					cout<<"The record with insurance number "<<ins_no<<" was not found"<<endl;
				break;
			
			case 7:
				return 0;
			
			default:
				cout<<"Error in choice,try again"<<endl;
		}
	}								
	return 0;
}
				
	

