#include "headers.h"
#include <iostream>

using namespace std;

int main()
{
	int dim; // �����������
	double *a, *b, *c, *d; // �������
	double e; // ��������� ������������
	const char nameA[3] = "a"; // ����� ��������
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

		// ����� ��������
		c = sum(dim, a, b);
		cout << "\nSum is:\n";
		output(dim, c, nameC);

		// �������� ��������
		d = dif(dim, a, b);
		cout << "Difference is (" << nameA  << '-' << nameB << "):\n";
		output(dim, d, nameD);

		// ��������� ������������ ��������
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
