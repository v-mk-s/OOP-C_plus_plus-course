#include "headers.h"
#include <iostream>

using namespace std;

int main()
{
	int dim; // размерность
	double *a, *b, *c, *d; // вектора
	double e; // скалярное произведение
	const char nameA[3] = "a"; // имена векторов
	const char nameB[3] = "b";
	const char nameC[3] = "c";
	const char nameD[3] = "d";
	
	a = b = c = d = NULL;
	dim = 0;

	cout << "Enter the dimension:\n";
	cin >> dim;
	while (dim < 0)
	{
		cout << "ERROR!\nEnter the dimension(>=0):\n";
		cin >> dim;
	}
	while (dim)
	{
		a = new double[dim];
		b = new double[dim];

		input(dim, a, nameA);
		input(dim, b, nameB);
		output(dim, a, nameA);
		output(dim, b, nameB);

		// сумма векторов
		c = sum(dim, a, b);
		cout << "\nSum is:\n";
		output(dim, c, nameC);

		// разность векторов
		d = dif(dim, a, b);
		cout << "Difference is (" << nameA  << '-' << nameB << "):\n";
		output(dim, d, nameD);

		// скалярное произведение векторов
		e = scalarProduct(dim, a, b);

		cout << "Scalar product is:\n" << e << '\n';

		vectorDelete(4, a, b, c, d);

		cout << "Enter the dimension:\n";
		cin >> dim;
		while (dim < 0)
		{
			cout << "ERROR!\nEnter the dimension(>=0):\n";
			cin >> dim;
		}
	}
	return 0;
}
