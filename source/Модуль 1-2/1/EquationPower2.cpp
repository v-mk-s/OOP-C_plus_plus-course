#include "headers.h"

#include <cmath>

int Equation_pow2(double a, double b, double c, double *p1, double *p2)
{
	double x1, x2;
	short n;
	//cout.setf(ios_base::fixed); //задаёт формат вывода

	double d = b*b - 4 * a*c; //дискриминант
	if (d < 0)
		return 0;
	else if (d > 0)
	{
		d = sqrt(d);
		x1 = (-b - d) / (2 * a);
		x2 = (-b + d) / (2 * a);
		n = 2;
	}
	else
	{
		x2 = x1 = -b / (2 * a);
		n = 1;
	}

	if (p1) *p1 = x1;
	if (p2) *p2 = x2;
	return n;

}