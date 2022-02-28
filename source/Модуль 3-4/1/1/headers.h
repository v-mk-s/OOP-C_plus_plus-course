#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/*void input(int size, double *p1, const char *vectorName); // ввод вектора
void output(int size, double *p1, const char *vectorName); // вывод вектора
double *sum(int size, double *p1, double *p2); // сумма векторов
double *dif(int size, double *p1, double *p2); // разность векторов
double scalarProduct(int size, double *p1, double *p2); // скалярное произведение векторов
double length(int size, double *p1); // длина вектора
double vectorAngle(int size, double *p1, double *p2); // угол межу векторами
double *vectorProduct(int size, double *p1, double *p2); // векторное произведение
double areaParallelogram(int size, double *p1, double *p2); // площадь параллелограмма
void vectorDelete(int size, double **pp); // удаление динамических векторов с указателем на двумерный динамический массив
// удаление динамических векторов, n - количество указателей, указатели ...
void vectorDelete(int n, ...);
*/


// ввод вектора
template <typename T> 
void input(int size, T *p1, const char *vectorName)
{
	for (cout << "Enter vector " << vectorName << ":\n", cin >> *p1; --size; cin >> *++p1);
}

// вывод вектора
template <typename T>
void output(int size, T *p1, const char *vectorName)
{
	for (cout << vectorName << " = (" << *p1; --size; cout << "; " << *++p1);
	cout << ")\n";
}

// сумма векторов
template <typename T>
T *sum(int size, T *p1, T *p2)
{
	T *c = new T[size]; // вектор суммы
	T *last = c + size - 1;
	for (*c = *p1 + *p2; c != last; *++c = *++p1 + *++p2);
	return c - size + 1;
}

// разность векторов
template <typename T>
T *dif(int size, T *p1, T *p2)
{
	T *c = new T[size]; // вектор разности
	T *last = c + size - 1;
	for (*c = *p1 - *p2; c != last; *++c = *++p1 - *++p2);
	return c - size + 1;
}

// скалярное произведение векторов
template <typename T>
T scalarProduct(int size, T *p1, T *p2)
{
	T product = *p1 * *p2;
	for (; --size; product += *++p1 * *++p2);
	return product;
}

// длина вектора
template <typename T>
T length(int size, T *p1)
{
	return sqrt(scalarProduct(size, p1, p1)); // |a|=sqrt((a*a))
}

// угол межу векторами
template <typename T>
double vectorAngle(int size, T *p1, T *p2)
{
	return acos(scalarProduct(size, p1, p2) / (length(size, p1)*length(size, p2))); // угол между векторами в радианах
}

// векторное произведение
template <typename T>
T *vectorProduct(int size, T *p1, T *p2)
{
	T *c = new T[size];
	//for (int i = 0; i < size; *c++ = *(p1 + (i + 1) % 3) * *(p2 + (i + 2) % 3) - *(p1 + (i + 2) % 3) * *(p2 + (i + 1) % 3), ++i);
	*c = *(p1 + 1) * *(p2 + 2) - *(p1 + 2) * *(p2 + 1);
	*++c = *(p1 + 2) * *p2 - *p1 * *(p2 + 2);
	*++c = *p1 * *(p2 + 1) - *(p1 + 1) * *p2;
	return c - size + 1;
}

// площадь параллелограмма
template <typename T>
T areaParallelogram(int size, T *p1, T *p2)
{
	T *c = vectorProduct(size, p1, p2); // вектор
	T len = length(size, c);
	delete[] c;
	return len;
}

// удаление динамических векторов с указателем на двумерный динамический массив
template <typename T>
void vectorDelete(int size, T **pp)
{
	for (delete[] * pp; --size; delete[] *++pp);
}

// удаление динамических векторов
template <typename T>
void vectorDelete(int n, ...)
{
	int *p = &n; // указатель на начало переданных параметров
	++p; // начало списка параметров-указателей
	// замена *p на **p
	union Pointer
	{
		T **pp;
		T *p0;
	};
	Pointer Change;
	Change.p0 = (T *)p;
	// удаление динамических массивов
	for (delete[] *Change.pp; --n; delete[] *++Change.pp);
}