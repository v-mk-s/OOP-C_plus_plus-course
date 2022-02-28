#pragma optimize("", off)
#include <iostream>

using namespace std;

template <typename T>
class CVector2: public CVector<T>
{
public:
	CVector2(const int size = 0, const T *pData = nullptr); // конструктор
	CVector2(const CVector2<T> &rv); // констурктор копии
	void output();
};

template<typename T>
void CVector2<T>::output()
{
	cout << "Num: " << m_size << '\n';
	if (m_size > 0)
	{
		int size = m_size;
		T *p = m_pData;//??
		for (int i = 0; i < size; ++i)
			cout << i+1 << ": " << p[i] << '\n';
	}
}

template <typename T>
CVector2<T>::CVector2(const int size, const T *pData): CVector(size, pData) {}

template <typename T>
CVector2<T>::CVector2(const CVector2<T> &rv): CVector(rv) {}