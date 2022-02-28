#include "headers.h"

#include <cmath>

int Equation_pow2(double a, double b, double c, double *p1, double *p2)
{
	//cout.setf(ios_base::fixed); //задаёт формат вывода

	double d = b*b - 4 * a*c; //дискриминант
	if (d < 0)
		return 0;
	if (d > 0)
	{
		d = sqrt(d);
		*p1 = (-b - d) / (2 * a);
		*p2 = (-b + d) / (2 * a);
		return 2;
	}

	*p1 = -b / (2 * a);
	return 1;
}