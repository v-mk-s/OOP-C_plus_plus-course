#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/*void input(int size, double *p1, const char *vectorName); // ���� �������
void output(int size, double *p1, const char *vectorName); // ����� �������
double *sum(int size, double *p1, double *p2); // ����� ��������
double *dif(int size, double *p1, double *p2); // �������� ��������
double scalarProduct(int size, double *p1, double *p2); // ��������� ������������ ��������
double length(int size, double *p1); // ����� �������
double vectorAngle(int size, double *p1, double *p2); // ���� ���� ���������
double *vectorProduct(int size, double *p1, double *p2); // ��������� ������������
double areaParallelogram(int size, double *p1, double *p2); // ������� ���������������
void vectorDelete(int size, double **pp); // �������� ������������ �������� � ���������� �� ��������� ������������ ������
// �������� ������������ ��������, n - ���������� ����������, ��������� ...
void vectorDelete(int n, ...);
*/


// ���� �������
template <typename T> 
void input(int size, T *p1, const char *vectorName)
{
	for (cout << "Enter vector " << vectorName << ":\n", cin >> *p1; --size; cin >> *++p1);
}

// ����� �������
template <typename T>
void output(int size, T *p1, const char *vectorName)
{
	for (cout << vectorName << " = (" << *p1; --size; cout << "; " << *++p1);
	cout << ")\n";
}

// ����� ��������
template <typename T>
T *sum(int size, T *p1, T *p2)
{
	T *c = new T[size]; // ������ �����
	T *last = c + size - 1;
	for (*c = *p1 + *p2; c != last; *++c = *++p1 + *++p2);
	return c - size + 1;
}

// �������� ��������
template <typename T>
T *dif(int size, T *p1, T *p2)
{
	T *c = new T[size]; // ������ ��������
	T *last = c + size - 1;
	for (*c = *p1 - *p2; c != last; *++c = *++p1 - *++p2);
	return c - size + 1;
}

// ��������� ������������ ��������
template <typename T>
T scalarProduct(int size, T *p1, T *p2)
{
	T product = *p1 * *p2;
	for (; --size; product += *++p1 * *++p2);
	return product;
}

// ����� �������
template <typename T>
T length(int size, T *p1)
{
	return sqrt(scalarProduct(size, p1, p1)); // |a|=sqrt((a*a))
}

// ���� ���� ���������
template <typename T>
double vectorAngle(int size, T *p1, T *p2)
{
	return acos(scalarProduct(size, p1, p2) / (length(size, p1)*length(size, p2))); // ���� ����� ��������� � ��������
}

// ��������� ������������
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

// ������� ���������������
template <typename T>
T areaParallelogram(int size, T *p1, T *p2)
{
	T *c = vectorProduct(size, p1, p2); // ������
	T len = length(size, c);
	delete[] c;
	return len;
}

// �������� ������������ �������� � ���������� �� ��������� ������������ ������
template <typename T>
void vectorDelete(int size, T **pp)
{
	for (delete[] * pp; --size; delete[] *++pp);
}

// �������� ������������ ��������
template <typename T>
void vectorDelete(int n, ...)
{
	int *p = &n; // ��������� �� ������ ���������� ����������
	++p; // ������ ������ ����������-����������
	// ������ *p �� **p
	union Pointer
	{
		T **pp;
		T *p0;
	};
	Pointer Change;
	Change.p0 = (T *)p;
	// �������� ������������ ��������
	for (delete[] *Change.pp; --n; delete[] *++Change.pp);
}