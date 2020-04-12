/* 
=============================================================================================
Roll number:- 23260
Batch:- H 10

Problem Definition:- Write a C++ that creates an output file, writes information to it,
closes the file and opens it again as an input file and reads the information in it.

Date of Performance:- 26/09/2019
=============================================================================================
*/

#include<fstream>
#include<iostream>
#include<iomanip>
#define SIZE 100
using namespace std;

class Student
{
	private:
		int rollno;
		int marks;
		char name[SIZE];
	public:
		void accept();
		void display();
};


void Student::accept()
{
	cout<<"Enter the roll number:- ";
	cin>>rollno;
	cin.ignore();
	cout<<"Enter the name of the student:- ";
	cin.getline(name,SIZE);
	cout<<"Enter the marks:- ";
	cin>>marks;
}


void Student::display()
{
	cout<<"\t"<<rollno<<"\t "<<name<<"   \t"<<marks<<"\n";	
}



int create(int);
void display(int);
int add(int);

int main()
{
	int choice,i,flag,cntr=0;
	
	while(1)
	{
		cout<<"\nStudents Database"<<endl;
		cout<<"1. Create"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Add"<<endl;
		cout<<"4. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				cntr=create(cntr);
				break;
			}
					
			case 2:
			{
				display(cntr);
				break;
			}
			case 3:
			{
				if(cntr==0)
					cout<<"\nPlease build a master table first"<<endl;
				else
					cntr=add(cntr);	
				break;
			}
			case 4:
				return 0;
			default:
				cout<<"Error in choice,try again"<<endl;
		}
	}								
	return 0;
}

int create(int cntr)
{
	int rno;
	Student m;
	ofstream fout("recs.txt",ios::out);
	cntr=0;
	char ask = 'y';
	while(ask =='y' || ask=='Y')
	{
			m.accept();
			fout.write((char *)&m,sizeof(m));
			cntr++;
			cout<<"\nDo you want to add another record?(y/n):- ";
			cin>>ask;
	}
	fout.close();
	return cntr;
}

void display(int cntr)
{
	int i;
	Student m;
	if(cntr==0)
		cout<<"\nPlease build a master table first"<<endl;
	else
	{
		ifstream fin("recs.txt",ios::in);
		cout<<"\n-----------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Sr No. "<<setw(5)<<"Roll No.  ";
		cout<<"Name  ";
		cout<<"University Marks  "<<endl;
		cout<<"\n----------------------------------------------------------------------------------------------------------"<<endl;
		i=1;
		while(fin.read((char *)&m,sizeof(m)))
		{	
			cout<<"  "<<i<<"  ";
			m.display();
			i++;
		}
		fin.close();
	}
}

int add(int cntr)
{
	Student m;
	ofstream fout("recs.txt",ios::app);
	cout<<"Enter the details of the record you want to insert:- "<<endl;
	m.accept();
	fout.write((char *)&m,sizeof(m));
	fout.close();
	cntr++;
	cout<<"Record inserted successfully"<<endl;
	return cntr;
}
