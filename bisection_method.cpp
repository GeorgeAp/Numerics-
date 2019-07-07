// This is a code for Bisection Method 
// This method is used to find the root of an equation

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x); // declares a function for the given equation

double f(double x){
	double a = x*x - 4.0;
	return a;
}

int main(){
	
	cout.precision(5); // sets the number of values to be displayed on the screen
	//cout.self(ios::fixed); // same as former 
	
	// declare variables to be used
	double a, b, c, e, fa, fb, fc;
	
	// setup initial variables intake
	a:cout << "Enter the initial guesses: \n a = "; // enter value of 'a'
	cin >> a;
	cout << "\n b = "; // enter value of 'b'
	cin >> b;
	cout << "\n Enter the degree of accuracy " << endl;
	cin >> e;
	
	int iter = 0; // initialise variable for iteration
	
	if(f(a)*f(b) > 0){
		cout<< "Please enter a different initial guess " << endl;
		goto a; // returns to line 25, note this is a bad style of coding 
	}
	else{
		cout<<"Iter"<<setw(12)<<"a"<<setw(12)<<"b"<<setw(12)<<"c"<<setw(12)<<"f(c)"<<setw(12)<<"|a-b|"<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		
		// implementing the Bisection Method algorithm 
		while (fabs(a-b) >= e){
			c = (a+b)/2.0;
			fa = f(a);
			fb = f(b);
			fc = f(c);
			iter++;
			
			cout<<iter<<setw(12)<<a<<setw(12)<<b<<setw(12)<<c<<setw(12)<<fc<<setw(12)<<fabs(a-b)<<endl;
			//return 0;
			
			if (fc==0){
				cout<<"The root of the equation is "<< c <<endl;
				return 0;
			}
			
			if (fa*fc > 0){
				a = c;
			}
			
			if(fa * fc < 0 ){
				b = c;	
			}
			
		}
	}
		
	cout << "The root of the equation is "<< c <<endl;
	return 0;
}

