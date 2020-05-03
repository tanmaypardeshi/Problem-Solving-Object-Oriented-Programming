/*
=============================================================================================
Roll No:- 23260
Batch:- H 10

Problem Definition:- Write a program to design a class 'Complex' with data members for real 
and imaginary parts. Provide default and parameterised constructors. Wrtie a program to perform 
arithmetic operations of 2 complex numbers using operator overloading.
i. Addition and Subtraction using friend function
ii. Multiplication and Division using member function.

Date of Performance:- 01/08/2019
============================================================================================
*/
#include<iostream>
#include<iomanip>
using namespace std;

class Complex
{
   	float x,y;
	
	public:
		Complex()
		{
			x=0;
			y=0;
		}
		Complex(float real, float img)
		{
			x=real;
			y=img;
		}
		friend Complex operator +(Complex &,Complex &);
		friend Complex operator -(Complex &,Complex &);
		Complex operator *(Complex);
		Complex operator /(Complex);
		friend ostream &operator<<(ostream &output, const Complex &obj)
		{
			if(obj.y>0)
				cout<<setprecision(2)<<obj.x<<"+"<<setprecision(2)<<obj.y<<"i"<<endl;
			else
			cout<<setprecision(2)<<obj.x<<setprecision(2)<<obj.y<<"i"<<endl;
		}
};

Complex operator +(Complex & a,Complex & b)
{
	Complex z;
	z.x = a.x + b.x;
	z.y = a.y + b.y;
	return z;
}

Complex operator -(Complex & a,Complex & b)
{
	Complex z;
	z.x = a.x - b.x;
	z.y = a.y - b.y;
	return z;
}

Complex Complex::operator *(Complex b)
{
	Complex z;
	z.x = (x*b.x-y*b.y);
	z.y = (x*b.y+b.x*y);
	return z;
}

Complex Complex::operator /(Complex b)
{
	Complex z;
	z.x = ((x*b.x)+(y*b.y))/(b.x*b.x+b.y*b.y);
	z.y = ((y*b.x)-(x*b.y))/(b.x*b.x+b.y*b.y);
	return z;
}
 

int main()
{
	Complex a,b,c;
	int choice;
	float real,img;
	
	while(1)
	{
		cout<<"\nOperations on Complex Numbers"<<endl;
		cout<<"1. Accept 2 Complex Numbers"<<endl;
		cout<<"2. Addition of complex numbers"<<endl;
		cout<<"3. Subtraction of complex numbers"<<endl;
		cout<<"4. Multiplication of complex numbers"<<endl;
		cout<<"5. Division of complex numbers"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter the real part of Complex Number A:- ";
				cin>>real;
				cout<<"Enter the imaginary part of Complex Number A:- ";
				cin>>img;
				a=Complex(real,img);
				cout<<"Enter the real part of Complex Number B:- ";
				cin>>real;
				cout<<"Enter the imaginary part of Complex Number B:- ";
				cin>>img;
				b=Complex(real,img);
				cout<<"Complex Numbers stored Successfully"<<endl;
				break;
			case 2:
				c = a+b;
				cout<<"Complex Number A is ";
				cout<<a;
				cout<<"Complex Number B is ";
				cout<<b;
				cout<<"\nAddition of A and B is ";
				cout<<c;
				break;
				
			case 3:
				c = a-b;
				cout<<"Complex Number A ";
				cout<<a;
				cout<<"Complex Number B is ";
				cout<<b;
				cout<<"\nSubtraction of A and B is ";
				cout<<c;
				break;
				
			case 4:			
				c = a*b;	
				cout<<"Complex Number A ";
				cout<<a;
				cout<<"Complex Number B is ";
				cout<<b;
				cout<<"\nMultiplication of A and B is ";
				cout<<c;
				break;
			
			case 5:
				c = a/b;	
				cout<<"Complex Number A ";
				cout<<a;
				cout<<"Complex Number B is ";
				cout<<b;
				cout<<"\nDivision of A and B is ";
				cout<<c;
				break;
				
			case 6:
				return 0;
			
			default:
				cout<<"Error in choice, try again"<<endl;
			
		}
	}
	return 0;
}
