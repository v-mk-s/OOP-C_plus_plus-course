// 10
#pragma optimize("", off)
#include "CVector.h"

// местный main()
template <typename T>
int mymain()
{
	CVector<double> a{ 1,2.3,3.3,4,5,6 };  // инициализаци€ списка

	CVector<T>::iterator ptr1 = a.begin(); // итератор
	for (ptr1 = a.begin(); ptr1 != a.end(); ++ptr1) cout << *ptr1 << ' ';

	const CVector<double> b{ 1,2,3 };
	cout << a[10];
	cout << b[3];
	
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