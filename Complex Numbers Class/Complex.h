#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
	float real, imag;
public:
	Complex(float a = 0, float b = 0);  //Constructor
	Complex(Complex& c);  //Copy Constructor
	friend Complex& operator+(Complex& c1, Complex& c2);  // overload binary + operator
	friend Complex& operator-(Complex& c1, Complex& c2);  // overload binary - operator
	friend Complex& operator*(Complex& c1, Complex& c2);  // overload binary * operator
	friend Complex& operator/(Complex& c1, Complex& c2);  // overload binary / operator
	friend ostream& operator<<(ostream& outObj, Complex& c);  // overload stream extraction operator
	friend istream& operator>>(istream& inObj, Complex& c);   // overload stream insertion operator
	Complex& operator=(Complex& c); // overload assignment operator
	float getReal() { return real; }  //Accessor for Real part
	float getImag() { return imag; }  //Accessor for Imaginary part
};

