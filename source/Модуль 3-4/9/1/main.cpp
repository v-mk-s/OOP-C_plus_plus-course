// 9
#pragma optimize("", off)
#include "CVector.h"

int main(void)
{
	tlist<double> l1, l2, l3;

	
	l1.push_back(1.0);
	l1.push_back(2.0);

	l2.push_back(2.0);
	l2.push_back(3.0);
	l2.push_back(4.0);

	l3.push_back(3.0);
	l3.push_back(4.0);
	l3.push_back(5.0);
	l3.push_back(6.0);
	
	/*if (!l1.input()) return 0;
	if (!l2.input()) return 0;
	if (!l3.input()) return 0;
	*/

	// 9
	cout << "\nl1, l2, l3\n";
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод
	
	cout << "\nScal(l1, l2)\n";
	cout << scal(l1, l2) << '\n';
	
	cout << "\nnorm()\n";
	cout << l1.norm() << '\n';
	cout << l2.norm() << '\n';
	cout << l3.norm() << '\n';

	cout << "\nl1 = l1 + l2\n";
	l1.sum(l1, l2);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод

	cout << "\nl2 = l1 + l3\n";
	l2.sum(l1, l3);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод

	cout << "\nl1 = l1 - l2\n";
	l1.dif(l1, l2);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод

	cout << "\nl1 = l2 - l1\n";
	l1.dif(l2, l1);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод
	
	cout << "\nl2 add l2\n";
	l2.add(l2);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод
	cout << "\nl1(new) sub l2\n";
	l1.sub(l2);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод
	cout << "\nl2 add l1\n";
	l2.add(l1);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод
	cout << "\nl2(new) sub l3\n";
	l2.sub(l3);
	l1.output(); // вывод
	l2.output(); // вывод
	l3.output(); // вывод

	
	cout << "\n l1.get(1) = l2.get(1);\n";
	l1.get(1) = l2.get(1);
	l1.output();
	l2.output();

	cout << "\n l1.get(100) = l2.get(100);\n";
	l1.get(100) = l2.get(100);
	l1.output();
	l2.output();


	const tlist<double> cl1;
	cout << cl1.get(4);

	return 0;
}