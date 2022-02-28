#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>

using namespace std;

int main()
{
	int dim; // размерность
	double *a, *b; // вектор a, b
	const char nameA[3] = "a"; // имена векторов
	const char nameB[3] = "b";
	double angle; // угол между векторами
	
	a = b = NULL;
	dim = angle = 0;

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
			
		// ввод и вывод векторов
		input(dim, a, nameA);
		input(dim, b, nameB);
		output(dim, a, nameA);
		output(dim, b, nameB);

		// длины векторов
		cout << "Vector(a) length is: " << length(dim, a) << '\n';
		cout << "Vector(b) length is: " << length(dim, b) << '\n';

		// угол межу векторами
		angle = vectorAngle(dim, a, b);
		cout << "The angle between the vectors is " << angle << " radian(s) or " << angle * 180 / M_PI << " degree(s).\n";

		vectorDelete(2, a, b);

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
