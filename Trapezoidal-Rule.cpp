// Trapezoidal Rule for the evaluation of definite integrals
#include <iostream>
#include <cmath>

using namespace std;

// defining function to be used 
double f(double x);
double f(double x){
	double a = 1/(1+x*x);
	return a; 
}

// defining the main program 
int main(){
	int n, i; // the variable 'n' is for subinternals and 'i' for loops
	double a, b, h, sum = 0, integral;
	
	cout<< "Enter the limits of integration \n limit a = ";
	cin>> a;
	cout<< "limit b = ";
	cin>> b;
	cout<<"Enter the number of subintervals n = ";
	cin>> n;
	
	// define arrays for x and y
	double x[n+1], y[n+1];
	// calculate the width of the subinterval
	h = (b-a)/n;
	
	for (i = 0; i<=n; i++){
		
		x[i] = a + i * h;   // loop to evaluate x
		y[i] = f(x[i]);     // then store values in arrays 
		
	}
	
	// loop to evaluate sum
	for (i = 1; i < n; i++){
		
		sum  = sum + h * y[i];
		
	}
	
	integral = h/2.0*(y[0]+y[n])+sum;    // h/2+[y0 + yn + 2(y1+y2+...+yn-1)]
	cout << "The definite integral is " << integral << endl;
	return 0;
	
}
