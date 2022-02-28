#define _USE_MATH_DEFINES

#include "headers.h"
#include <iostream>
#include <cstdlib>

using namespace std;

union Pointer
{
	double **pp;
	double *p0;
};

void inputDim(int &n, int &m)
{
	cout << "Enter dimension and m:\n";
	cin >> n >> m;
	cout << "Creating multidimensional \"space\"...\n"; //?
}

// n-������ ������������ � m �������� � ������
double *newMultidimensionalSpace(int n, int m, double *p) // ��������
{
	static int nCount = n;
	if (n > 1)
	{
		//double *last = NULL;
		Pointer Change;
		Change.pp = new double*[m];
		//last = Change.p0;
		p = Change.p0;

		int i = 1;
		for (*Change.pp = newMultidimensionalSpace(n - 1, m, *Change.pp); i < m;
			++Change.pp, *Change.pp = newMultidimensionalSpace(n - 1, m, *Change.pp), ++i); //?
		Change.pp -= m - 1;
	}
	else
	{
		p = new double[m]; // ��� ������, ����� switch ������ ��������� ����������� ������
		*p = --m + rand() % 5;
		for (int i = m; i; *++p = --i + rand() % 5);
		p -= m;
	}
	if (n == nCount) cout << "Multidimensional \"space\" created successfully.\n";
	return p;
}

double *inputMultidimensionalSpace(int n, int m, double *p) // ���� (������)
{
	if (n > 1)
	{
		Pointer Change;
		Change.p0 = p;

		int i = 1;
		for (inputMultidimensionalSpace(n - 1, m, *Change.pp); i < m;
			inputMultidimensionalSpace(n - 1, m, *++Change.pp), ++i); //?
		Change.pp -= m - 1;
	}
	else
	{
		cin >> *p;
		for (int i = m; --i; cin >> *++p);
		p -= m - 1;
	}
	return p;
}

void input(int n, int m, double *p) // ����
{
	int N, M; // ������ �������� � "������������"

	cout << "Enter index (enter 0 0 to exit):\n";
	cin >> N >> M;
	while (N && M)
	{
		--N, --M;
		inputSearch(n, m, p, N, M, true);
		outputMultidimensionalSpace(n, m, p);
		cout << "Coordinate successfully replaced.\n";

		cout << "Enter index (enter 0 to exit):\n";
		cin >> N >> M;
	}
}

void inputSearch(int n, int m, double *p, int N, int M, bool flag) // ����� � ������ ��������
{
	//? ����� �� ������ �� �����, ����� �����
	static int numberI = 0; // ����� �� N
	if (flag) numberI = 0;
	int i;
	if (n > 1)
	{
		Pointer Change;
		Change.p0 = p;

		i = 1;
		for (inputSearch(n - 1, m, *Change.pp, N, M, false); i < m;
			inputSearch(n - 1, m, *++Change.pp, N, M, false), ++i); //?
		Change.pp -= m - 1; // sizeof(double *) = 4
	}
	else
	{
		if (N == numberI)
		{
			for (i = 0; i < m; ++i)
			{
				if (i == M)
				{
					double a;
					cout << "Enter the number: ";
					cin >> a;
					*p = a;
					//break;
				}
				++p;
			}
			p -= m; // sizeof(double) = 8
		}
		++numberI;
	}
}

void outputMultidimensionalSpace(int n, int m, double *p) // �����
{
	// ��������
	static int nCount = n;
	static int mCount = m;
	if (n == nCount) cout << "Multidimensional \"space\":\n";

	int space = nCount - n; // ���������� ��������
	int i;
	if (n > 1)
	{
		//for (i = space + 1; --i; cout << ' ');
		Pointer Change;
		Change.p0 = p;

		i = 1;
		for (outputMultidimensionalSpace(n - 1, m, *Change.pp); i < m;
			outputMultidimensionalSpace(n - 1, m, *++Change.pp), ++i); //?
		Change.pp -= m - 1; // sizeof(double *) = 4
		cout << '\n';
	}
	else
	{
		cout << *p;
		for (i = m; --i; cout << ' ' << *++p);
		p -= m; // sizeof(double) = 8
		cout << '\n';
	}
}

double *deleteMultidimensionalSpace(int n, int m, double *p) // ��������
{
	static int nCount = n;
	if (n > 1)
	{
		Pointer Change;
		Change.p0 = p;

		int i = 1;
		for (*Change.pp = deleteMultidimensionalSpace(n - 1, m, *Change.pp); i < m;
			++Change.pp, *Change.pp = deleteMultidimensionalSpace(n - 1, m, *Change.pp), ++i); //?
		Change.pp -= m - 1;
	}
	delete[] p;
	if (n == nCount) cout << "Multidimensional \"space\" deleted successfully.\n";
	return p;
}