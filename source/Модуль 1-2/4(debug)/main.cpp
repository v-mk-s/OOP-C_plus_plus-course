#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 100000000;
	for (int i = n; i <= n; ++i)
	{
		cout << '\n' << i << '\n';
		int dim; // �����������
		double *a, *b; // ������ a, b
		const char nameA[3] = "a"; // ����� ��������
		const char nameB[3] = "b";
		double angle; // ���� ����� ���������

		a = b = NULL;
		dim = angle = 0;

		dim = i;
			a = new double[dim];
			b = new double[dim];

			// ���� � ����� ��������
			input(dim, a, nameA);
			input(dim, b, nameB);

			// ����� ��������
			cout << "Vector(a) length is: " << length(dim, a) << '\n';
			cout << "Vector(b) length is: " << length(dim, b) << '\n';
		
			// ���� ���� ���������
			angle = vectorAngle(dim, a, b);
			cout << "The angle between the vectors is " << angle << " radian(s) or " << angle * 180 / M_PI << " degree(s).\n";

			vectorDelete(2, a, b);

		
	}
	return 0;
}