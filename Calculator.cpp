#include <math.h>
#include "Calculator.h"

void Calculator::Add(const double x, const double y)
{
	result = x + y;
}

void Calculator::Subtract(const double x, const double y)
{
	result = x - y;
}

void Calculator::Multiply(const double x, const double y)
{ 
	result = x * y;
}

ERROR Calculator::Divide(const double x, const double y)
{
	if (y == 0) { 
		return DIVIDE_BY_ZERO; 
	}
	else {
		result = x / y;
		return SUCCESS;
	}

	

	return SUCCESS;
}

ERROR Calculator::Roots(const double a, const double b, const double c, double& x1, double& x2)
{
	double delta;
	if (a == 0) {
		return INVALID_PARAMETER;
	}

	delta = (b * b) - (4 * a * c);

	if (delta < 0) {
		return NO_ROOTS;
	}
	else if (delta == 0) {
		return SINGLE_ROOT;
	}

	x1 = (-b - sqrt(delta))/(2 * a);
	x2 = (-b + sqrt(delta)) / (2 * a);

	return SUCCESS;
}

double Calculator::GetResult()
{
	return result;
}
