/*
=============================================================================================
Roll No:- 23260
Batch:- H 10

Problem Definition:- Inheritance using Virtual function 
Create a base class shape with two double type values and member functions to input the data and compute_area() for calculating area of figure. 
Derive two classes’ triangle and rectangle.
Make compute_area() as a virtual function and redefine this function in the derived class to suit their requirements.
Write a program that accepts dimensions of triangle/rectangle and display calculated area.

Date of Performance:- 05/09/2019
============================================================================================
*/

#include<iostream>
using namespace std;


class Shape
{
	protected:
		double x,y;
	
	public:
		Shape(double,double);
		virtual double compute_area()=0;	//pure virtual function
};

class Rectangle:public Shape
{
	public:
		Rectangle(double,double);
		double compute_area();	//overriding
};

class Triangle:public Shape
{
	public:
		Triangle(double,double);
		double compute_area();
};

Shape::Shape(double dim1,double dim2)
{
	x=dim1;
	y=dim2;
}

Rectangle::Rectangle(double dim1,double dim2):Shape(dim1,dim2){}

double Rectangle::compute_area()
{
	return x*y;
}

Triangle::Triangle(double dim1,double dim2):Shape(dim1,dim2){}

double Triangle::compute_area()
{
	return 0.5*x*y;
}

int main()
{
	Shape *ptrs;
	double dim1,dim2;
	int choice;
	
	while(1)
	{
		cout<<"Computing area of shapes"<<endl;
		cout<<"1. Area of Rectangle"<<endl;
		cout<<"2. Area of Triangle"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter length of rectangle:- ";
				cin>>dim1;
				cout<<"Enter breadth of rectangle:- ";
				cin>>dim2;
				ptrs= new Rectangle(dim1,dim2);
				cout<<"Area of rectangle is:- "<<ptrs->compute_area()<<"\n"<<endl;		
				break;
			case 2:
				cout<<"Enter base of triangle:- ";
				cin>>dim1;
				cout<<"Enter height of triangle:- ";
				cin>>dim2;
				ptrs= new Triangle(dim1,dim2);
				cout<<"Area of triangle is:- "<<ptrs->compute_area()<<"\n"<<endl;		
				break;
			case 3:
				return 0;
			default:
				cout<<"Error in choice, try again\n"<<endl;
		}
	}		
	return 0;
}
	
