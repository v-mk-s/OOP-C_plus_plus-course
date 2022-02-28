// 8
#pragma optimize("", off)
#include "CVector.h"
#include "CVector2.h"
#include "CVector3.h"

// местный main()
template <typename T>
int mymain()
{
	// инициализация и ввод
	int size1;
	T *pData1;
	size1 = 0;
	pData1 = nullptr;

	if (!(pData1 = input<T>(size1))) return 0;
	CVector<T> a(size1, pData1);
	CVector<T>::iterator ptr1; // итератор
	
	for (ptr1 = a.begin(); ptr1 != a.end(); ++ptr1) cout << *ptr1 << ' ';

	delete[] pData1;

	/*
	// инициализация и ввод
	int size1, size2, size3;
	T *pData1, *pData2, *pData3;
	size1 = size2 = size3 = 0;
	pData1 = pData2 = pData3 = nullptr;
	
	//6 lab
	cout << "6+++++++++++++++++\n";
	if (!(pData1 = input<T>(size1))) return 0;
	if (!(pData2 = input<T>(size2))) return 0;
	CVector<T> a(size1, pData1), c, b;
	b = a;
	c = a + b;
	cout << a << b << c;
	b = a++;
	b = a--;
	b = ++a;
	b = --a;
	delete[] pData1;
	delete[] pData2;
	
	//7 lab
	cout << "7+++++++++++++++++\n";

	if (!(pData1 = input<T>(size1))) return 0;
	CVector<T> v01(size1, pData1), v04(v01);
	
	if (!(pData2 = input<T>(size2))) return 0;
	CVector<T> v02(size2, pData2);

	if (!(pData3 = input<T>(size3))) return 0;
	CVector<T> v03(size3, pData3);

	CVector<T> v1(v01), v2(v02), v3(v03), v4(v04);
	
	// вывод
	cout << "v1: ";
	v1.output();
	cout << "v2: ";
	v2.output();
	cout << "v3: ";
	v3.output();
	cout << "v4: ";
	v4.output();
	cout << '\n';

	cout << "1.1+++++++++++++++++\n";
	// копия
	v2.copy(size1, pData1);
	v3.copy(v2);
	v4.copy(v4);
	v1.output();
	v2.output();
	v3.output();
	v4.output();
	cout << '\n';

	cout << "1.2+++++++++++++++++\n";
	// скалярное произведение
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << "Scal v2 and v3 is: ";
	cout << scal(v2, v3) << '\n';

	cout << "1.3+++++++++++++++++\n";
	// норма
	cout << "Length v1 is: ";
	cout << v1.norm() << '\n';

	cout << "Length v2 is: ";
	cout << v2.norm() << '\n';

	cout << "1.4+++++++++++++++++\n";
	// сумма
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << "Sum v1 and v2 is:\n";
	v4.sum(v1, v2);
	v4.output();
	cout << '\n';

	cout << "Sum v2 and v3 is:\n";
	v3.sum(v2, v3);
	v3.output();
	cout << '\n';

	cout << "Sum v2 and v2 is:\n";
	v2.sum(v2, v2);
	v2.output();
	cout << '\n';

	cout << "1.5+++++++++++++++++\n";
	// разность
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << "Difference v1 and v2 is:\n";
	v4.dif(v1, v2);
	v4.output();
	cout << '\n';

	cout << "Difference v2 and v3 is:\n";
	v3.dif(v2, v3);
	v3.output();
	cout << '\n';

	cout << "Difference v2 and v2 is:\n";
	v2.dif(v2, v2);
	v2.output();
	cout << '\n';

	cout << "1.6+++++++++++++++++\n";
	// добавление
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << "v2.add(v1) is:\n";
	v2.add(v1);
	v2.output();
	cout << '\n';

	cout << "v3.add(v2) is:\n";
	v3.add(v2);
	v3.output();
	cout << '\n';

	cout << "v2.add(v2) is:\n";
	v2.add(v2);
	v2.output();
	cout << '\n';

	cout << "1.7+++++++++++++++++\n";
	// вычитание
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << "v1.sub(v2) is:\n";
	v1.sub(v2);
	v1.output();
	cout << '\n';

	cout << "v3.sub(v2) is:\n";
	v3.sub(v2);
	v3.output();
	cout << '\n';

	cout << "v2.sub(v2) is:\n";
	v2.sub(v2);
	v2.output();
	cout << '\n';

	//4
	cout << "4+++++++++++++++++\n";

	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия

	cout << "v1 = v2 = v4 = v4:\n";
	v1 = v2 = v4 = v4;
	v1.output();
	v2.output();
	v3.output();
	v4.output();
	cout << '\n';

	cout << v1() << '\n';

	cout << (v1 == v2);
	cout << (v1 != v2);
	cout << (v2 == v4);
	cout << (v2 != v4);
	cout << '\n';

	//4.1
	cout << "4.1+++++++++++++++++\n";
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	v1 = +v1;
	v1.output();
	v1 = -v1;
	v1.output();

	//4.2
	cout << "4.2+++++++++++++++++\n";
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	++v1;
	v1.output();
	--v1;
	v1.output();
	v2 = v1++;
	v1.output();
	v2.output();
	v2 = v1--;
	v1.output();
	v2.output();

	//4.4
	cout << "4.4+++++++++++++++++\n";
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << v1 << v2 << v3 << v4 << '\n';
	cout << v1 << v2;
	v1 = -+-v2-- + +-+-v2;
	cout << v1 << v2;
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << v2 + v3 - v4;
	v2 = v2 + v3 - v4;
	cout << v2;

	//4.5
	cout << "4.5+++++++++++++++++\n";
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << v1 << v2 << v3 << v4 << '\n';

	v1 += v2;
	v3 -= v4;

	cout << v1 << v2 << v3 << v4 << '\n';

	//4.6
	cout << "4.6+++++++++++++++++\n";
	v1.copy(v01), v2.copy(v02), v3.copy(v03), v4.copy(v04); // копия
	cout << v1 << v2 << v3 << v4 << '\n';

	v2.add(v1);
	v4.sub(v3);

	cout << v1 << v2 << v3 << v4 << '\n';
	
	//4.7
	cout << "4.7+++++++++++++++++\n";
	v1.copy(v01); // копия
	cout << v1;

	cout << "Enter 2 numbers\n";
	int i;
	cin >> i;
	cin >> v1[i];
	cout << v1[i];
	cout << v1[100];

	cout << '\n' << v1;

	delete[] pData1;
	delete[] pData2;
	delete[] pData3;
	*/

	return 0;
}

int main()
{
	mymain <double>();
	return 0;
}

// ввод
template <typename T>
T *input(int &size)
{
	T *pData = nullptr;
	cout << "Enter size: ";
	cin >> size;
	if (size > 0)
	{
		pData = new T[size];
		T *p = pData;
		int temp = size;
		cout << "Enter Data: ";
		for (cin >> *p; --temp; cin >> *++p);
		cout << '\n';
	}
	return pData;
}