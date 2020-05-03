/*
========================================================================
Roll No:- 23260
Batch:- H 10

Problem Definition:- A Book shop maintains the inventory of books that are 
being sold at the shop. The list includes details such as title, author, 
publisher, price and available stock. Write a program in C++ which will have 
a class called books with suitable member functions for
1.Add
2.Update
3.Search a book
4.Purchase a book (update the stock and display the total cost)
5.Record number of successful/unsuccessful transactions
(use static data members to keep count of transactions)
Use new operator in constructors to allocate memory space required.  

Date of Performance:-  04/07/2019
=========================================================================
*/

#include<iostream>
#include<string.h>
#include<iomanip>
#define SIZE 50
using namespace std;

class Books
{
	char *title, *author, *publisher;
	int *stock,*isbn;
	float *price;
	static int unsuccess;
	static int success;
	
	public:
		Books();
		void add_book();
		void display_book();
		void update_book();
		int search_book(int &);
		int search_book(char []);
		int search_book(char [],int);
		void purchase_book();
		static int getsuccess();
		static int getunsuccess();
		~Books();
};

int Books::unsuccess;
int Books::success;

Books::Books()
{
	title= new char[SIZE];
	author= new char[SIZE];
	publisher= new char[SIZE];
	stock= new int;
	isbn= new int;
	price= new float;
}

void Books::add_book()
{
	cin.ignore();
	cout<<"Enter the book number:- ";
	cin>>*isbn;
	cin.ignore();
	cout<<"Enter title of the book:- ";
	cin.getline(title,SIZE);
	cout<<"Enter author of the book:- ";
	cin.getline(author,SIZE);
	cout<<"Enter publisher of the book:- ";
	cin.getline(publisher,SIZE);
	cout<<"Enter the price of the book:- ";
	cin>>*price;
	cout<<"Enter the stock available:- ";
	cin>>*stock;
}

void Books::display_book()
{
		static int i=1;
		cout<<i<<"\t"<<*isbn<<"\t"<<title<<"\t"<<author<<"\t"<<publisher<<"\t\t"<<*price<<"\t\t"<<*stock<<endl;
		i++;
}

void Books::update_book()
{
	cout<<"\nEnter New details";
	cout<<"\nISBN:- "<<*isbn<<endl;
	cin.ignore();
	cout<<"Title of Book:- ";
	cin.getline(title,SIZE);
	cout<<"Author of Book:- ";
	cin.getline(author,SIZE);
	cout<<"Publisher of Book:- ";
	cin.getline(publisher,SIZE);
	cout<<"Enter the price of the book:- ";
	cin>>*price;
	cout<<"Enter the stock available:- ";
	cin>>*stock;
	cout<<"\nBook with ISBN "<<*isbn<<" has been updated successfully"<<endl;
}

int Books::search_book(int & isbno)
{	
	if(isbno==*isbn)
		return 1;
	return 0;
}

int Books::search_book(char t[])
{
	if(strcmp(t,title)==0)
		return 1;
	return 0;
}

int Books::search_book(char a[],int x)
{
	if(strcmp(a,author)==0)
		return 1;
	return 0;
}
				

void Books::purchase_book()
{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)
	{
		success++;
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully"<<endl;
		cout<<"Details of the book are:- "<<endl;
		cout<<"ISBN:- "<<*isbn<<endl;
		cout<<"Title:- "<<title<<endl;
		cout<<"Author:- "<<author<<endl;
		cout<<"Price of 1 book:- "<<*price<<endl;
		cout<<"Number of books bought:- "<<count<<endl;
		cout<<"\nTotal amount is:- "<<(*price)*count<<endl;
	}
	else
	{
		cout<<"\nRequired Copies not in Stock"<<endl;
		unsuccess++;
	}
	cout<<"Available stock is:- "<<*stock<<endl;
}


int Books::getsuccess()
{
	return success;
}

int Books::getunsuccess()
{
	return unsuccess;
}

Books::~Books()
{
	delete [] title;
	delete [] author;
	delete [] publisher;
	delete price;
	delete isbn;
	delete stock;
}

int main()
{
	Books *b[SIZE];
	int j,choice,i,flag=1,d=1;
	int isbno;
	char ch,t[SIZE],a[SIZE];
	
	for(i=0;i<SIZE;i++)
		b[i]=new Books;
	i=0;
	
	while(1)
	{
		cout<<"\nBook Shop"<<endl;
		cout<<"1. Add a book"<<endl;
		cout<<"2. Display Book Inventory"<<endl;
		cout<<"3. Update a book"<<endl;
		cout<<"4. Search a book"<<endl;
		cout<<"5. Purchase a book"<<endl;
		cout<<"6. Display successful and unsuccessful transactions"<<endl;
 		cout<<"7. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				if(i<SIZE)
				{
					b[i]->add_book();
					i++;
				}
				else
					cout<<"No more books can be added"<<endl;
				
				break;	
			case 2:
				cout<<"\t\t\tBOOK INVENTORY"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Sr.No\tISBN\tTitle\t\tAuthor\t\tPublisher\tPrice\t\tStock"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------"<<endl;
				for(j=0;j<i;j++)
					b[j]->display_book();
				cout<<"------------------------------------------------------------------------------------------------------"<<endl;
				break;
			case 3:
				flag=1;
				cout<<"Enter the ISBN of the book to update:- ";
				cin>>isbno;
				for(j=0;j<i;j++)
				{	
					if(b[j]->search_book(isbno))
					{
						flag=0;
						b[j]->update_book();
						break;
					}
				}
				if(flag)
					cout<<"\nThe book you want to update was not found"<<endl;
				break;
			case 4:
				while(d==1)
				{
					cout<<"\nBOOK SEARCH"<<endl;
					cout<<"a. Search by ISBN"<<endl;
					cout<<"b. Search by book title"<<endl;
					cout<<"c. Search by book author"<<endl;
					cout<<"d. Stop search"<<endl;
					cout<<"\nEnter your choice:- ";
					cin>>ch;
					
					switch(ch)
					{
						case 'a':
						case 'A':
							flag=1;
							cout<<"Enter the ISBN of the book to search:- ";
							cin>>isbno;
							for(j=0;j<i;j++)
							{
								if(b[j]->search_book(isbno))
								{
									cout<<"\nSEARCH SUCCESSFUL"<<endl;
									flag=0;
								}
							}
							if(flag==1)
								cout<<"BOOK NOT FOUND"<<endl;
							break;
						case 'b':
						case 'B':
							flag=1;
							cout<<"Enter the title of the book to search:- ";
							cin.ignore();
							cin.getline(t,SIZE);
							for(j=0;j<i;j++)
							{
								if(b[j]->search_book(t))
								{
									cout<<"\nSEARCH SUCCESSFUL\n"<<endl;
									flag=0;
								}
							}
							if(flag==1)
								cout<<"BOOK NOT FOUND"<<endl;
							break;
						case 'c':
						case 'C':
							flag=1;
							cout<<"Enter the author of the book to search:- ";
							cin.ignore();
							cin.getline(a,SIZE);
							for(j=0;j<i;j++)
							{
								if(b[j]->search_book(a,0))
								{
									cout<<"\nSEARCH SUCCESSFUL\n"<<endl;
									flag=0;
								}
							}
							if(flag==1)
								cout<<"\nBOOK NOT FOUND"<<endl;
							break;
						case 'd':
						case 'D':
							d=0;
							break;
						default:
							cout<<"Error in choice,try again\n";
							break;
					}
				}
				break;									
			
			case 5:
				flag=1;
				cout<<"Enter the ISBN of the book to purchase:- ";
				cin>>isbno;
				for(j=0;j<i;j++)
				{	
					if(b[j]->search_book(isbno))
					{
						flag=0;
						b[j]->purchase_book();
						break;
					}
				}
				if(flag)
					cout<<"\nThe book you want to purchase was not found"<<endl;
				break;
			
			case 6:
				cout<<"The number of successful transacions are:- ";
				cout<<b[1]->getsuccess();
				cout<<"\nThe number of unsuccessful transactions are:- ";
				cout<<b[1]->getunsuccess()<<endl;
				break;
			case 7:
				return 0;
		}
	}
	return 0;
}
						
			
			
			
			
			
			
			
			
			
			
			
			
