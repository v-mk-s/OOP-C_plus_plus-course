#include "headers.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// n-������ ������������ � m �������� � ������
int main()
{
	srand(time(NULL)); // ������������� �������

	int n, m; //  ������ ��������
	double *p = NULL; // ������ �� "������������"
	int f; // ���� �� ����
	//n = m = 8;
	inputDim(n, m);
	//for (int e = 0; e < 1000; ++e)
	p = newMultidimensionalSpace(n, m, p);
	cout << "Size is " << pow(double(m), n) / 131072 << " MB\n";
	//cout << p << '\n';
	if (n < 6) outputMultidimensionalSpace(n, m, p);

	cout << "Enter \"space\" (0 - to exit): ";
	cin >> f;
	if (f)
	{
		inputMultidimensionalSpace(n, m, p);
		outputMultidimensionalSpace(n, m, p);
	}

	cout << "Enter index (0 - to exit): ";
	cin >> f;
	if (f) input(n, m, p);

	p = deleteMultidimensionalSpace(n, m, p);

	return 0;
}