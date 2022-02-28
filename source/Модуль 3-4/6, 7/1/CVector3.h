#pragma optimize("", off)
#include <iostream>

using namespace std;

template <typename T>
class CVector3 : public CVector<T>
{
public:
	CVector3(const int size = 0, const T *pData = nullptr); // конструктор
	CVector3(const CVector3<T> &rv); // констурктор копии
	void voutput();
};

template <typename T>
void CVector3<T>::voutput()
{
	cout << "Num: " << m_size << '\n';
	if (m_size > 0)
	{
		int size = m_size;
		T *p = m_pData;
		for (int i = 0; i < size; ++i)
			cout << i + 1 << ": " << p[i] << '\n';
	}
}

template <typename T>
CVector3<T>::CVector3(const int size, const T *pData): CVector(size, pData) {}

template <typename T>
CVector3<T>::CVector3(const CVector3<T> &rv): CVector(rv) {}