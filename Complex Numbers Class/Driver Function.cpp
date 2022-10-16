
#include <iostream>
#include <math.h>
#include "Complex.h"
using namespace std;
Complex& operator+(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;
	return c3;
}
Complex& operator-(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.real = c1.real - c2.real;
	c3.imag = c1.imag - c2.imag;
	return c3;
}
Complex& operator*(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.real = (c1.real * c2.real) - (c1.imag * c2.imag);    //minus because iota^2 = -1
	c3.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
	return c3;
}
Complex& operator/(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.real = c2.real;
	c3.imag = (-1) * c2.imag;        //minus because if c2=a+bi c1 has to be multiplied with (a - bi)
	Complex N;
	float D;
	N = c1 * c3;
	D = c2.real * c2.real + pow(c2.imag, 2);      //plus because minus of formula(a^2 +b^2) & minus of iota^2 = +1
	c3.real = (N.real / D);
	c3.imag = (N.imag / D);
	return c3;
}
istream& operator>>(istream& inObj, Complex& c)
{
	cout << "Enter the real part: ";
	inObj >> c.real;
	cout << "Enter the imaginary part: ";
	inObj >> c.imag;
	return inObj;
}
ostream& operator<<(ostream& outObj, Complex& c)
{
	if (c.imag >= 0)
		outObj << c.real << "+" << c.imag << "i" << endl;
	else
		outObj << c.real << c.imag << "i" << endl;
	return outObj;
}
int main()
{
	//Simple driver function to show the functioning of operators
	Complex c1(2, -1);
	Complex c2;
	cout << "Enter a complex number:" << endl;
	cin >> c2;
	Complex c3;
	c3 = c1 + c2;
	cout << "Addition: ";
	cout << c3;
	c3 = c1 - c2;
	cout << "Subtraction: ";
	cout << c3;
	c3 = c1 * c2;
	cout << "Multiplication: ";
	cout << c3;
	c3 = c1 / c2;
	cout << "Division: ";
	cout << c3;
}

