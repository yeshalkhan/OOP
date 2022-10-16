#include "Complex.h"
Complex::Complex(float a, float b)
{
	real = a;
	imag = b;
}
Complex::Complex(Complex& c)
{
	this->real = c.real;
	this->imag = c.imag;
}
Complex& Complex::operator=(Complex& c)
{
	real = c.real;
	imag = c.imag;
	return *this;
}
