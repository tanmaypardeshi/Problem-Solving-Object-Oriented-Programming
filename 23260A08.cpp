/*
=============================================================================================================
Roll number:- 23260
Batch:- H 10

Problem Definition:- Write a program in C++ using function/class template to read two matries of different 
data types such as integers and floating point values and perform simple arithmetic operators on matrices
seperately and display it.

Date of Performance:- 19/09/2019
=============================================================================================================
*/

#include<iostream>
#define SIZE 50
using namespace std;


template <class T>
class Matrix
{

	int r,c;
	T m[SIZE][SIZE];
	
	public:
		void getdata(int , int);
		void display(int , int);
		void add(Matrix <T>& , Matrix <T>&,int , int );
		void mul(Matrix <T>& , Matrix <T>&,int , int );
		void sub(Matrix <T>& , Matrix <T>&,int , int );

};



template<class T> 
void Matrix <T>::getdata(int r,int c)
{
	int i ,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			cout<<"Enter element ["<<i<<"]"<<"["<<j<<"]:- ";
			cin>>m[i][j];		
		}
}

template<class T> 
void Matrix <T>::display(int r,int c)
{
	int i ,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<m[i][j]<<"\t";		
		cout<<"\n";
	}
}

template <class T> 
void Matrix <T>::add (Matrix <T> &a ,Matrix<T> &b,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)		
			m[i][j]= a.m[i][j]+b.m[i][j];
}


template <class T> 
void Matrix <T>::sub (Matrix <T> &a ,Matrix<T> &b,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			 m[i][j]=a.m[i][j]-b.m[i][j];
}

template <class T> 
void Matrix <T>::mul(Matrix <T> &a ,Matrix<T> &b,int r,int c)
{
	int i,j,k;
	for(i=0;i<r;i++)		
		for(j=0;j<c;j++)
		{
			m[i][j]=0;
			for(k=0;k<c;k++)
				m[i][j]+= a.m[i][k]*b.m[k][j];
		} 
}

int main()
{
    int choice;
    int r1,c1,r2,c2;  
   
    Matrix<int> mat1,mat2,matr;
    
    cout<<"Enter rows 1st matrix:- ";
    cin>>r1; 
    cout<<"Enter columns 1st matrix:- ";
    cin>>c1;  
    cout<<"\nEnter 1st  matrix:- \n";
    mat1.getdata(r1,c1); 
    cout<<"Enter rows 2nd matrix:- ";
    cin>>r2; 
    cout<<"Enter columns 2nd matrix:- ";
    cin>>c2;  
    cout<<"\n Enter 2nd matrix:- \n";
    mat2.getdata(r2,c2);
   
    while(1)
    {
        cout<<"\nOperation on matrices:- "<<endl;
        cout<<"\n1.Addition of matrices";
        cout<<"\n2.Subtraction of matrices";
        cout<<"\n3.Multiplication of matrices";
        cout<<"\n4. Exit"<<endl;
        cout<<"\nEnter Your Choice:- ";
        
        cin>>choice;
        switch(choice)
        {
            case 1:
                if(r1==r2 && c1==c2) 
                {
		            cout<<"Addition is:- "<<endl;
		            matr.add(mat1,mat2,r1,c1);
		            matr.display(r1,c1);
		        }
		        else
		            cout<<"Addition is not possible"<<endl;
		    	break;
            case 2:
                if(r1==r2 && c1==c2) 
                {
		            cout<<"Subtraction is:- "<<endl;
		            matr.sub(mat1,mat2,r1,c1);
		            matr.display(r1,c1);
		        }
		        else
		            cout<<"Subtraction is not possible"<<endl;
		    	break;
            case 3:
                if (c1==r2)  
                {
		            cout<<"Multiplication is:- "<<endl;
		            matr.mul(mat1,mat2,r1,c2);
		            matr.display(r1,c2);
		        }
            	else
                	cout<<"Multiplication is not possible"<<endl;
            	break;
            case 4:
                return 0;
            default:
            	cout<<"Error in choice, try again"<<endl;
		}
    }
    return 0;
}
