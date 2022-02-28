#include "headers.h"

#include <iostream>

using namespace std;


int main()
{
	double a, b, c, x1, x2;
	int n;

	cout << "a: ";
	cin >> a;
	while (a)
	{
		cout << "b: ";
		cin >> b;
		cout << "c: ";
		cin >> c;

		n = Equation_pow2(a, b, c, &x1, &x2);


		if (a == -1) cout << "-x^2";
		else if (a == 1) cout << "x^2";
		else cout << a << "x^2";

		if (b)
		{
			if (b == 1) cout << "+x";
			else if (b == -1) cout << "-x";
			else if (b > 0) cout << '+' << b << 'x';
			else cout << b << 'x';
		}

		if (c)
		{
			if (c > 0) cout << '+' << c;
			else cout << c;
		}

		cout << "=0" << '\n';


		switch (n)
		{
		case 1:
			cout << "x = " << x1 << '\n';
			break;
		case 2:
			cout << "x = " << x1 << '\n';
			cout << "x = " << x2 << '\n';
			break;
		default:
			cout << "no solution\n";
		}
		cout << "\n\n";


		cout << "a: ";
		cin >> a;
	}
	return 0;
}

// -0
// fixed