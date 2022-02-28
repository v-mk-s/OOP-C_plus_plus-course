//4
#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>

using namespace std;

template <typename T> 
int mymain()
{
	int dim; // �����������
	T *a, *b; // ������ a, b
	const char nameA[3] = "a"; // ����� ��������
	const char nameB[3] = "b";
	double angle; // ���� ����� ���������
	
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
		a = new T[dim];
		b = new T[dim];
			
		// ���� � ����� ��������
		input(dim, a, nameA);
		input(dim, b, nameB);
		output(dim, a, nameA);
		output(dim, b, nameB);

		// ����� ��������
		cout << "Vector(a) length is: " << length(dim, a) << '\n';
		cout << "Vector(b) length is: " << length(dim, b) << '\n';

		// ���� ���� ���������
		angle = vectorAngle(dim, a, b);
		cout << "The angle between the vectors is " << angle << " radian(s) or " << angle * 180 / M_PI << " degree(s).\n";

		vectorDelete<T>(2, a, b);

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
		mymain <double>();
		return 0;
	}