#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>

using namespace std;

int main()
{
	cout.precision(6);

	int dim; // размерность введенная
	const int dim3 = 3; // размерность по условию
	double *a, *b, *c; // вектор a, b, c;
	char nameA[3] = "a";
	char nameB[3] = "b";
	char nameC[3] = "c";

	a = b = c = NULL;
	dim = 0;

	cout << "Enter the dimension:\n";
	cin >> dim;
	while (dim != 2 && dim != 3 && dim)
	{
		cout << "ERROR!\nEnter the dimension(2 or 3):\n";
		cin >> dim;
	}
	while (dim)
	{
		a = new double[dim3];
		b = new double[dim3];
		*(a + 2) = *(b + 2) = 0;

		// ввод и вывод векторов
		input(dim, a, nameA);
		input(dim, b, nameB);
		dim = 3;
		output(dim, a, nameA);
		output(dim, b, nameB);

		// векторное произведение
		c = vectorProduct(dim, a, b);
		output(dim, c, nameC);

		// площадь параллелограмма
		cout << "The parallelogram area is " << areaParallelogram(dim, a, b) << ".\n";

		// 3
		vectorDelete(3, a, b, c);
		// 1 способ удаления
		/*
		delete[] a;
		delete[] b;
		delete[] c;
		*/

		// 2
		/*
		double **pp = new double*[dim];
		*pp++ = a;
		*pp++ = b;
		*pp++ = c;
		pp -= dim;
		vectorDelete(dim, pp);
		delete[] pp;
		*/
		
		cout << "Enter the dimension:\n";
		cin >> dim;
		while (dim != 2 && dim != 3 && dim)
		{
			cout << "ERROR!\nEnter the dimension(2 or 3):\n";
			cin >> dim;
		}
	}
	return 0;
}