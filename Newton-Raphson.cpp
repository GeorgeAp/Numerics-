// Newton-Raphson Method
// This is a root finding algorithm 

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x);     // function declaration
double f(double x){    // function definition
	
    double 	a = 3.0*x + sin(x) - pow(2.71828,x);
    return a;
}

double fprime(double x);     // function declaration
double fprime(double x){    // function definition
	
    double 	b = 3.0 + cos(x) - pow(2.71828,x);
    return b;
}

int main(){
	// declare variable used in this function
	double x, x1, e, fx, fx1;
	cout.precision(4);
	
	// take in the initial values of the variables
	cout<<"Enter the initial guess \n";
	cin>>x1;
	cout<<"Enter the desired accuracy \n";
	cin>> e;
	
	// setup the display screen 
	cout<<"x{i}"<< "   " << "x{i+1}" << "   " << "|x{i+1}-x{i}|" << endl;
	
	// statement to execute algorithm 
	do {
		x = x1;
		fx = f(x);
		fx1 = fprime(x);
		x1 = x - (fx/fx1);
		cout << x<< "   " << x1 <<"   " << abs(x1-x) << endl;
	} while (fabs(x1-x)>=e);
	
	cout<<"The root of the equation is " << x1 << endl;
	return 0;
}
 
 
