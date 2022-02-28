//3
#include "headers.h"

template <typename T>
int mymain()
{
	cout.precision(6);

	int dim; // размерность
	T *a, *b, *c, *d; // вектора
	T e; // скалярное произведение
	const char nameA[3] = "a"; // имена векторов
	const char nameB[3] = "b";
	const char nameC[3] = "c";
	const char nameD[3] = "d";
	double angle;

	a = b = c = d = NULL;
	angle = dim = 0;

	cout << "Enter the dimension:\n";
	cin >> dim;
	while (dim < 0)
	{
		cout << "ERROR!\nEnter the dimension(>=0):\n";
		cin >> dim;
	}
	while (dim)
	{
		a = new T[dim];
		b = new T[dim];

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
		cout << "Difference is (" << nameA << '-' << nameB << "):\n";
		output(dim, d, nameD);

		// скалярное произведение векторов
		e = scalarProduct(dim, a, b);

		cout << "Scalar product is:\n" << e << '\n';

		// длины векторов
		cout << "Vector(a) length is: " << length(dim, a) << '\n';
		cout << "Vector(b) length is: " << length(dim, b) << '\n';

		// угол межу векторами
		angle = vectorAngle(dim, a, b);
		cout << "The angle between the vectors is " << angle << " radian(s) or " << angle * 180 / M_PI << " degree(s).\n";

		// векторное произведение
		if ((dim == 2) || (dim == 3))
		{
			c = vectorProduct(dim, a, b);
			output(dim, c, nameC);

			// площадь параллелограмма
			cout << "The parallelogram area is " << areaParallelogram(dim, a, b) << ".\n";
		}

		vectorDelete<T>(4, a, b, c, d);

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


int main()
{
	mymain <int>();
	return 0;
}