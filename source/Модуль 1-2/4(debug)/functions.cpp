#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>
#include <cmath>

using namespace std;

// ���� �������
void input(int size, double *p1, const char *vectorName)
{
	for (*p1 = size; --size; *++p1 = size);
}

// ����� �������
void output(int size, double *p1, const char *vectorName)
{
	for (cout << vectorName << " = (" << *p1; --size; cout << "; " << *++p1);
	cout << ")\n";
}

// ����� ��������
double *sum(int size, double *p1, double *p2)
{
	double *c = new double[size]; // ������ �����
	double *last = c + size - 1;
	for (*c = *p1 + *p2; c != last; *++c = *++p1 + *++p2);
	return c - size + 1;
}

// �������� ��������
double *dif(int size, double *p1, double *p2)
{
	double *c = new double[size]; // ������ ��������
	double *last = c + size - 1;
	for (*c = *p1 - *p2; c != last; *++c = *++p1 - *++p2);
	return c - size + 1;
}

// ��������� ������������ ��������
double innerproduct(int size, double *p1, double *p2)
{
	double product = *p1 * *p2;
	for (; --size; product += *++p1 * *++p2);
	return product;
}

// ����� �������
double length(int size, double *p1)
{
	return sqrt(abs(innerproduct(size, p1, p1))); // |a|=sqrt((a*a))
}

// ���� ���� ���������
double vectorAngle(int size, double *p1, double *p2)
{
	return acos(innerproduct(size, p1, p2) / length(size, p1)/length(size, p2)); // ���� ����� ��������� � ��������
}

// ��������� ������������
double *vectorProduct(int size, double *p1, double *p2)
{
	double *c = new double[size];
	//for (int i = 0; i < size; *c++ = *(p1 + (i + 1) % 3) * *(p2 + (i + 2) % 3) - *(p1 + (i + 2) % 3) * *(p2 + (i + 1) % 3), ++i);
	*c = *(p1 + 1) * *(p2 + 2) - *(p1 + 2) * *(p2 + 1);
	*++c = *(p1 + 2) * *p2 - *p1 * *(p2 + 2);
	*++c = *p1 * *(p2 + 1) - *(p1 + 1) * *p2;
	return c - size + 1;
}

// ������� ���������������
double areaParallelogram(int size, double *p1, double *p2)
{
	double *c = new double[size]; // ������ 
	return length(size, p1) * length(size, p2) * sin(vectorAngle(size, p1, p2));
}

// �������� ������������ �������� � ���������� �� ��������� ������������ ������
void vectorDelete(int size, double **pp)
{
	for (delete[] * pp; --size; delete[] *++pp);
}

// �������� ������������ ��������
void vectorDelete(int n, ...)
{
	int *p = &n; // ��������� �� ������ ���������� ����������
	++p; // ������ ������ ����������-����������
	// ������ *p �� **p
	union Pointer
	{
		double **pp;
		double *p0;
	};
	Pointer Change;
	Change.p0 = (double *)p;
	// �������� ������������ ��������
	for (delete[] *Change.pp; --n; delete[] *++Change.pp);
}