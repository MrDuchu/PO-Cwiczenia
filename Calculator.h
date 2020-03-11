#pragma once
enum ERROR {SUCCESS, DIVIDE_BY_ZERO, NO_ROOTS, SINGLE_ROOT, INVALID_PARAMETER};

class Calculator
{
protected:
	double result;

public:
	void Add(const double x, const double y);
	void Subtract(const double x, const double y);
	void Multiply(const double x, const double y);
	ERROR Divide(const double x, const double y);
	ERROR Roots(const double a, const double b, const double c, double& x1, double& x2);

	double GetResult();
};

