// This is a program for Secant Method 
// This algorithm is used to find the roots of an equation

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x); // declare the function to be used

// define the function to be used. This function returns 'a' 
double f(double x){
	double a = sin(x*x*x) - 8.0;  // the equation of the function
	return a;
}

// define the main part of the program 
int main(){
	// set the presicion of the display variables
	cout.precision(4);
	
	// declare variables
	double a, b, c, e; 
	int iter = 1;
	
	// Entry of initial guesses of the variables
	cout<<"Enter the initial guess \na = ";
	cin>> b; // this is because we want to use the inital value of 'b' as the initial value of 'c'
	cout<<"b = ";
	cin>> c;
	cout<<"Enter the degree of accuracy = ";
	cin>> e;
	
	// setup of the display screen 
	cout<<"Iter"<<setw(12)<<"a"<<setw(12)<<"b"<<setw(12)<<"c"<<setw(12)<<"f(c)"<<setw(12)<<"|cn-c|"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	
	// here the Secant Method starts 
	do
	{
		a = b;
		b = c;
		c = b - (b-a)/(f(b)-f(a))*f(b); // this calculates the new value of 'c'
		cout<<iter<<setw(12)<<a<<setw(12)<<b<<setw(12)<<c<<setw(12)<<f(c)<<setw(12)<<fabs(c-b)<<endl;
		
		// check for solution
		if (f(c)==0)
		{
			cout<<"The root of the equation is "<< c;
			return 0;
			
		}
		
		iter++;
		
	} while (abs(c-b)>e); // tolerance check 
	
	cout<<"The root of the equation is " << c<< endl;
	return 0;
	
}
