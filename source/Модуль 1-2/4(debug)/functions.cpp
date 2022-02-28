#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>
#include <cmath>

using namespace std;

// ввод вектора
void input(int size, double *p1, const char *vectorName)
{
	for (*p1 = size; --size; *++p1 = size);
}

// вывод вектора
void output(int size, double *p1, const char *vectorName)
{
	for (cout << vectorName << " = (" << *p1; --size; cout << "; " << *++p1);
	cout << ")\n";
}

// сумма векторов
double *sum(int size, double *p1, double *p2)
{
	double *c = new double[size]; // вектор суммы
	double *last = c + size - 1;
	for (*c = *p1 + *p2; c != last; *++c = *++p1 + *++p2);
	return c - size + 1;
}

// разность векторов
double *dif(int size, double *p1, double *p2)
{
	double *c = new double[size]; // вектор разности
	double *last = c + size - 1;
	for (*c = *p1 - *p2; c != last; *++c = *++p1 - *++p2);
	return c - size + 1;
}

// скалярное произведение векторов
double innerproduct(int size, double *p1, double *p2)
{
	double product = *p1 * *p2;
	for (; --size; product += *++p1 * *++p2);
	return product;
}

// длина вектора
double length(int size, double *p1)
{
	return sqrt(abs(innerproduct(size, p1, p1))); // |a|=sqrt((a*a))
}

// угол межу векторами
double vectorAngle(int size, double *p1, double *p2)
{
	return acos(innerproduct(size, p1, p2) / length(size, p1)/length(size, p2)); // угол между векторами в радианах
}

// векторное произведение
double *vectorProduct(int size, double *p1, double *p2)
{
	double *c = new double[size];
	//for (int i = 0; i < size; *c++ = *(p1 + (i + 1) % 3) * *(p2 + (i + 2) % 3) - *(p1 + (i + 2) % 3) * *(p2 + (i + 1) % 3), ++i);
	*c = *(p1 + 1) * *(p2 + 2) - *(p1 + 2) * *(p2 + 1);
	*++c = *(p1 + 2) * *p2 - *p1 * *(p2 + 2);
	*++c = *p1 * *(p2 + 1) - *(p1 + 1) * *p2;
	return c - size + 1;
}

// площадь параллелограмма
double areaParallelogram(int size, double *p1, double *p2)
{
	double *c = new double[size]; // вектор 
	return length(size, p1) * length(size, p2) * sin(vectorAngle(size, p1, p2));
}

// удаление динамических векторов с указателем на двумерный динамический массив
void vectorDelete(int size, double **pp)
{
	for (delete[] * pp; --size; delete[] *++pp);
}

// удаление динамических векторов
void vectorDelete(int n, ...)
{
	int *p = &n; // указатель на начало переданных параметров
	++p; // начало списка параметров-указателей
	// замена *p на **p
	union Pointer
	{
		double **pp;
		double *p0;
	};
	Pointer Change;
	Change.p0 = (double *)p;
	// удаление динамических массивов
	for (delete[] *Change.pp; --n; delete[] *++Change.pp);
}