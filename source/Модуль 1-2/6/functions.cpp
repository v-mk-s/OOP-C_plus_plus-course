#include "headers.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

// ���� �������
int **create(int *m, int *n)
{
	// ���� n � m
	cout << "Enter the m and n:\n";
	cin >> *m >> *n;
	while (!((*n > 0) && (*n < 20) && (*m > 0) && (*m < 20)))
	{
		cout << "ERROR!\nEnter correct n and m:\n";
		cin >> *m >> *n;
	}

	// ��������
	int i, j;
	int **pp = new int*[*m];
	//cout << pp << '\n';
	for (i = 0; i < *m; ++i)
	{
		*pp = new int[*n];
		//cout << *pp << '\n';
		for (j = 0; j < *n; ++j)
		{
			**pp = rand() % 1000;
			++(*pp);
		}
		*pp-=*n;
		//cout << *pp << "\n\n";
		++pp;
	}
	return pp - *m;
}

// ���� �������
void input(int m, int n, int **pp)
{
	int i, j;
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cin >> **pp;
			++(*pp);
		}
		*pp-=n;
		++pp;
	}
	pp-=m;
}

// ����� �������
void output(int m, int n, int **pp)
{
	//cout << pp << '\n';
	//cout << *pp << '\n';
	int i, j;
	cout << "Matrix (" << m << 'x' << n << "):\n";
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cout.width(6);
			cout << **pp;
			++(*pp);
		}
		cout << "\n\n";
		*pp-=n;
		++pp;
	}
	pp-=m;
}

// �������� ������
void deleteStr(int *m, int *n, int **pp)
{
	int i, j;
	int max, temp; // ������������ ����� � ������ � ���������
	int max_i = 0; // ��������� ������

	// ����� ������
	max = **pp;
	++(*pp);
	for (j = 1; j < *n; ++j)
	{
		max += **pp;
		++(*pp);
	}
	//cout << *pp << '\n';
	*pp -= *n;
	//cout << *pp << '\n';
	++pp;

	for (i = 1; i < *m; ++i)
	{
		temp = **pp;
		++(*pp);
		for (j = 1; j < *n; ++j)
		{
			temp += **pp;
			++(*pp);
		}
		//cout << *pp << '\n';
		*pp -= *n;
		//cout << *pp << '\n';
		if (max < temp)
		{
			max = temp;
			max_i = i;
		}
		++pp;
	}
	pp -= *m;

	//�������� ������
	delete[] pp[max_i];
	for (i = max_i+1; i < *m; ++i)
		pp[i-1] = pp[i];

	--*m;
	pp[*m] = NULL;
}

// �������� �������
void deleteCol(int *m, int *n, int **pp)
{
	int i, j;
	int max, temp; // ������������ ����� � ������� � ���������
	int max_i = 0; // ��������� �������

	// ����� �������
	max = pp[0][0];
	for (i = 1; i < *m; ++i)
		max += pp[i][0];

	for (j = 1; j < *n; ++j)
	{
		temp = pp[0][j];
		for (i = 1; i < *m; ++i)
			temp += pp[i][j];
		if (max > temp)
		{
			max = temp;
			max_i = j;
		}
	}

	//�������� ������
	for (j = 0; j < *m; ++j)
	{
		for (i = max_i+1; i < *n; ++i)
			pp[j][i-1] = pp[j][i];
		pp[j][i-1] = 0;
	}
	--*n;
}

// �������� �������
void delete2(int m, int **pp)
{
	int i;
	for (i = 0; i < m; ++i)
	{
		delete[] *pp;
		//cout << *pp << '\n';
		++pp;
	}
	pp-=m;
	delete[] pp;
	//cout << pp << '\n';
}