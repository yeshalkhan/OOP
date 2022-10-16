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
	friend Complex& operator+(Complex& c1, Complex& c2);  //Addition operator
	friend Complex& operator-(Complex& c1, Complex& c2);  //Subtraction operator
	friend Complex& operator*(Complex& c1, Complex& c2);  //Multiplication operator
	friend Complex& operator/(Complex& c1, Complex& c2);  //Division operator
	friend ostream& operator<<(ostream& outObj, Complex& c);  //Stream Extraction operator
	friend istream& operator>>(istream& inObj, Complex& c);   //Stream Insertion operator
	Complex& operator=(Complex& c); //Assignment operator
	float getReal() { return real; }  //Accessor for Real part
	float getImag() { return imag; }  //Accessor for Imaginary part
};

