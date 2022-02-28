#include "headers.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
	int m, n; // размерность матрицы
	int **pp; // указатель на матрицу;
	int end = 0; // выход(из цикла программы)

	srand(time(NULL));
	pp = NULL;
	m = n = 0;

	do
	{
		pp = create(&m, &n);

		cout << "Random(1/0)?\n";
		cin >> end;
		if (!end) input(m, n, pp);
		output(m, n, pp);

		deleteStr(&m, &n, pp);
		deleteCol(&m, &n, pp);
		output(m, n, pp);
		
		delete2(m, pp);
		cout << "Continue(1/0)?\n";
		cin >> end;
	} while (end);
	return 0;
}