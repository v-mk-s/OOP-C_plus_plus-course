#include <iostream>

using namespace std;


int main()
{
	double a, min, max, aver;
	double n;

	cin >> a;
	max = min = aver = a;
	n = 0;

	while (a)
	{
		if (min > a)
			min = a;
		else if (max < a)
			max = a;

		++n;
		aver += (a - aver) / n;

		cout << "min: " << min;
		cout << "\naverage: " << aver;
		cout << "\nmax: " << max << "\n\n";
		cin >> a;
	}

	return 0;
}