#pragma optimize("", off)
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <utility>
#include <initializer_list>

using namespace std;

template <typename T>
class CVector
{
public:
	typedef T* iterator; // �������� CVector`a
	T* begin();
	T* end();

public:

	explicit CVector(const int size = 0, const T *pData = nullptr); // �����������
	CVector(const CVector<T> &rv); // ����������� �����
	CVector(CVector<T> &&rv); // ������������ �����������
	CVector(std::initializer_list<T> init_list); //����������� �������������
	~CVector(); // ����������

	virtual void voutput() { output(); }; // ����������� �������

	int copy(const int size, const T *pData); // ����� 
	int copy(const CVector<T> &rv); // ����� �������
	int copy(CVector<T> &&rv); // ����������� ������������
	void output();

	// ��������� ������������ ��������
	template <typename T>
	friend double scal(const CVector<T> &v1, const CVector<T> &v2);
	// ����� �������
	double norm();
	// ����� �������� (�������������)
	template <typename T>
	friend void sum(CVector<T> &v, const CVector<T> &v1, const CVector<T> &v2);
	// �������� �������� (�������������)
	template <typename T>
	friend void dif(CVector<T> &v, const CVector<T> &v1, const CVector<T> &v2);
	// ����� ��������
	CVector<T> &sum(const CVector<T> &v1, const CVector<T> &v2);
	// �������� ��������
	CVector<T> &dif(const CVector<T> &v1, const CVector<T> &v2);

	// ����������� � �������
	CVector<T> &add(const CVector<T> &v1);
	// ��������� �� �������
	CVector<T> &sub(const CVector<T> &v1);

	// ������������
	CVector<T> &operator=(const CVector<T>& rv);
	CVector<T> &operator=(CVector<T> &&rv); // ������������ ������������
	// �������� ����������
	T & operator[](int n);
	const T operator[](int n) const;
	// ������� �����
	double operator()(void);

	//���������
	template <typename T>
	friend bool operator==(const CVector<T> &v1, const CVector<T> &v2);
	template <typename T>
	friend bool operator!=(const CVector<T> &v1, const CVector<T> &v2);

	//������� +
	template <typename T>
	friend CVector<T> operator+(const CVector<T> &v1);
	//������� -
	template <typename T>
	friend CVector<T> operator-(const CVector<T> &v1);
	//���������� ���������
	template <typename T>
	friend CVector<T> &operator++(CVector<T> &v1);
	//����������� ���������
	template <typename T>
	friend CVector<T> operator++(CVector<T> &v1, int);
	//���������� ���������
	template <typename T>
	friend CVector<T> &operator--(CVector<T> &v1);
	//����������� ���������
	template <typename T>
	friend CVector<T> operator--(CVector<T> &v1, int);

	// ��������� ������������
	template <typename T>
	friend double operator^(const CVector<T> &v1, const CVector<T> &v2);
	//�����, ��������
	template <typename T>
	friend CVector<T> operator+(const CVector<T> &v1, const CVector<T> &v2);
	template <typename T>
	friend CVector<T>& operator+=(CVector<T> &v1, const CVector<T> &v2);
	template <typename T>
	friend CVector<T> operator-(const CVector<T> &v1, const CVector<T> &v2);
	template <typename T>
	friend CVector<T>& operator-=(CVector<T> &v1, const CVector<T> &v2);

	// ����, �����
	template <typename T>
	friend std::istream& operator >> (std::istream &in, CVector<T> &v1);
	template <typename T>
	friend std::ostream& operator<< (std::ostream &out, const CVector<T> &v1);

protected:
	int m_size;
	T *m_pData;
	T m_null; // ��� ������
	const T c_m_null = 0;

	void init(); // �������������
	void destroy(); // ���������������
};

template<typename T>
inline CVector<T>::CVector(std::initializer_list<T> init_list)
{
	init(); // ��������� �������������
	m_size = init_list.size();
	m_pData = new T[m_size];
	T *p = m_pData;
	for (auto v : init_list) *p = v, ++p;
}

// ��������
template <typename T>
T* CVector<T>::begin()
{
	return m_pData;
}

template <typename T>
T* CVector<T>::end()
{
	return (m_pData + m_size);
}
// ��������

template <typename T>
CVector<T>::CVector(const int size, const T *pData)
{
	//cout << "\n Constructor \n";
	init();
	copy(size, pData);
}

template <typename T>
CVector<T>::~CVector()
{
	destroy();
}

template <typename T>
CVector<T>::CVector(const CVector<T> &rv)
{
	cout << "\n Copy constructor \n";
	init();
	copy(rv);
}

template <typename T>
int CVector<T>::copy(const CVector<T> &rv)
{
	return copy(rv.m_size, rv.m_pData);
}

template<typename T>
inline void CVector<T>::init()
{
	m_size = 0;
	m_pData = nullptr;
}

template <typename T>
void CVector<T>::destroy()
{
	//cout << "\n destructor \n";
	if (m_pData == nullptr) delete [] m_pData;
}

// �����
template <typename T>
int CVector<T>::copy(const int size, const T *pData)
{
	if (m_pData == pData) return m_size;
	if (size > 0)
	{
		T *p = new T[size];
		if (p) // ���� �� ������� �������� ������, �� return 0
		{
			for (int i = 0; i < size; ++i)
				p[i] = pData[i];
			destroy();
			m_size = size;
			m_pData = p;
			return m_size;
		}
	}
	return 0;
}

// ������������
template <typename T>
CVector<T> & CVector<T>::operator=(const CVector<T>& rv) {
	//�������� �� ����������������
	cout << "\n Copy = \n";
	if (this == &rv) {
		return *this;
	}
	copy(rv);
	return *this;
}

template <typename T>
CVector<T> & CVector<T>::operator=(CVector<T> &&rv)
{
	cout << "\n Move = \n";
	copy(move(rv)); // �������������� lvalue � rvalue
	return *this;
}

template <typename T>
CVector<T>::CVector(CVector<T> &&rv)
{
	cout << "\n Move constructor \n";
	copy(move(rv));
}

template <typename T>
int CVector<T>::copy(CVector<T> &&rv)
{
	destroy();
	m_size = rv.m_size;
	m_pData = rv.m_pData;
	rv.init();
	return m_size;
}

// �����
template <typename T>
void CVector<T>::output()
{
	cout << "Num: " << m_size;
	if (m_size > 0)
	{
		cout << " Data: ";
		int size = m_size;
		T *p = m_pData;//??
		for (cout << *p; --size; cout << ' ' << *++p);
	}
	cout << '\n';
}

// ������������� ��������
template <typename T>
void sum(CVector<T> &v, const CVector<T> &v1, const CVector<T> &v2)
{
	if ((v1.m_size == v2.m_size) && (v2.m_size == v.m_size) && (v2.m_size > 0))
	{
		for (int i = 0; i < v.m_size; ++i)
			v.m_pData[i] = v1.m_pData[i] + v2.m_pData[i];
	}
}

// ������������� ��������
template <typename T>
void dif(CVector<T> &v, const CVector<T> &v1, const CVector<T> &v2)
{
	if ((v1.m_size == v2.m_size) && (v2.m_size == v.m_size) && (v2.m_size > 0))
	{
		for (int i = 0; i < v.m_size; ++i)
			v.m_pData[i] = v1.m_pData[i] -
			v2.m_pData[i];
	}
}

//��������
template <typename T>
CVector<T> & CVector<T>::sum(const CVector<T> &v1, const CVector<T> &v2)
{
	if (v2.m_size > 0)
	{
		int i = 0;
		if (v1.m_size > v2.m_size)
		{
			T *p = new T[v1.m_size];
			if (p)
			{
				for (i = 0; i < v2.m_size; ++i)
					p[i] = v1.m_pData[i] + v2.m_pData[i];
				for (; i < v1.m_size; ++i)
					p[i] = v1.m_pData[i];

				destroy();
				m_size = v1.m_size;
				m_pData = p;
			}
		}
		else
		{
			T *p = new T[v2.m_size];
			if (p)
			{
				for (i = 0; i < v1.m_size; ++i)
					p[i] = v1.m_pData[i] + v2.m_pData[i];
				for (; i < v2.m_size; ++i)
					p[i] = v2.m_pData[i];

				destroy();
				m_size = v2.m_size;
				m_pData = p;
			}
		}
	}
	return *this;
}

//��������
template <typename T>
CVector<T> & CVector<T>::dif(const CVector<T> &v1, const CVector<T> &v2)
{
	if (v2.m_size > 0)
	{
		int i = 0;
		if (v1.m_size > v2.m_size)
		{
			T *p = new T[v1.m_size];
			if (p)
			{
				for (i = 0; i < v2.m_size; ++i)
					p[i] = v1.m_pData[i] - v2.m_pData[i];
				for (; i < v1.m_size; ++i)
					p[i] = v1.m_pData[i];

				destroy();
				m_size = v1.m_size;
				m_pData = p;
			}
		}
		else
		{
			T *p = new T[v2.m_size];
			if (p)
			{
				for (i = 0; i < v1.m_size; ++i)
					p[i] = v1.m_pData[i] - v2.m_pData[i];
				for (; i < v2.m_size; ++i)
					p[i] = -v2.m_pData[i];

				destroy();
				m_size = v2.m_size;
				m_pData = p;
			}
		}
	}
	return *this;
}

// ����������� � �������
template <typename T>
CVector<T> & CVector<T>::add(const CVector<T> &v1)
{
	if (v1.m_size > 0)
	{
		if (v1.m_size < m_size)
		{
			for (int i = 0; i < v1.m_size; ++i)
				m_pData[i] += v1.m_pData[i];
		}
		else
		{
			CVector<T> vTemp (v1);
			for (int i = 0; i < m_size; ++i)
				vTemp.m_pData[i] += m_pData[i];
			copy(vTemp);
		}
	}
	return *this;
}

// ��������� �� �������
template <typename T>
CVector<T> & CVector<T>::sub(const CVector<T> &v1)
{
	if (v1.m_size > 0)
	{
		if (v1.m_size < m_size)
		{
			for (int i = 0; i < v1.m_size; ++i)
				m_pData[i] -= v1.m_pData[i];
		}
		else
		{
			CVector<T> vTemp (v1);
			int i = 0;
			for (; i < m_size; ++i)
				vTemp.m_pData[i] = m_pData[i] - vTemp.m_pData[i];
			for (; i < v1.m_size; ++i)
				vTemp.m_pData[i] = -vTemp.m_pData[i];
			copy(vTemp);
		}
	}
	return *this;
}

// ��������� ������������
template <typename T>
double scal(const CVector<T> &v1, const CVector<T> &v2)
{
	return scalarProduct(min(v1.m_size, v2.m_size), v1.m_pData, v2.m_pData);
}

// ����� �������
template <typename T>
double CVector<T>::norm()
{
	return length(m_size, m_pData); // |a|=sqrt((a*a))
}

template<typename T>
const T CVector<T>::operator[](int n) const
{
	if ((n >= 0) && (n < m_size)) 
		return m_pData[n];
	cout << "Invalid array offsets\n";
	return c_m_null;
}

template<typename T>
T & CVector<T>::operator[](int n)
{
	if ((n >= 0) && (n < m_size))
		return m_pData[n];
	cout << "\nError!\n";
	m_null = 0;
	return m_null;
}

template<typename T>
double CVector<T>::operator()(void)
{
	return norm();
}

template <typename T>
bool operator==(const CVector<T> &v1, const CVector<T> &v2)
{
	if (v1.m_size != v2.m_size) return false;
	int i = 0;
	for (; ((i < v1.m_size) && (v1.m_pData[i] == v2.m_pData[i])); ++i);
	if (i == v1.m_size) return true;
	else return false;
}

template <typename T>
bool operator!=(const CVector<T> &v1, const CVector<T> &v2)
{
	return !(v1 == v2);
}

template<typename T>
CVector<T> operator+(const CVector<T>& v1)
{
	CVector<T> res(v1);
	return res;
}

template<typename T>
CVector<T> operator-(const CVector<T>& v1)
{
	CVector<T> res(v1);
	for (int i = 0; i < res.m_size; ++i)
		res.m_pData[i] = -res.m_pData[i];
	return res;
}

template<typename T>
CVector<T>& operator++(CVector<T>& v1)
{
	for (int i = 0; i < v1.m_size; ++i)
		++v1.m_pData[i];
	return v1;
}

template<typename T>
inline CVector<T> operator++(CVector<T>& v1, int)
{
	CVector<T> oldValue(v1);
	for (int i = 0; i < v1.m_size; ++i)
		++v1.m_pData[i];
	return oldValue;
}

template<typename T>
inline CVector<T>& operator--(CVector<T>& v1)
{
	for (int i = 0; i < v1.m_size; ++i)
		--v1.m_pData[i];
	return v1;
}

template<typename T>
inline CVector<T> operator--(CVector<T>& v1, int)
{
	CVector<T> oldValue(v1);
	for (int i = 0; i < v1.m_size; ++i)
		--v1.m_pData[i];
	return oldValue;
}

template<typename T>
inline double operator^(const CVector<T>& v1, const CVector<T>& v2)
{
	return scal(v1, v2);
}

template<typename T>
inline CVector<T> operator+(const CVector<T>& v1, const CVector<T>& v2)  // !!
{
	CVector<T> res;
	res.sum(v1, v2);
	return res;
}

template<typename T>
inline CVector<T>& operator+=(CVector<T>& v1, const CVector<T>& v2)
{
	v1.add(v2);
	return v1;
}

template<typename T>
inline CVector<T> operator-(const CVector<T>& v1, const CVector<T>& v2)
{
	CVector<T> res;
	res.dif(v1, v2);
	return res;
}

template<typename T>
inline CVector<T>& operator-=(CVector<T>& v1, const CVector<T>& v2)
{
	v1.sub(v2);
	return v1;
}

template<typename T>
inline std::istream & operator >> (std::istream & in, CVector<T>& v1)
{
	int size1;
	T *pData1;
	size1 = 0;
	pData1 = nullptr;
	if (!(pData1 = input<T>(size1))) return in;
	v1.copy(size1, pData1);
	return in;
}

template<typename T>
inline std::ostream & operator<<(std::ostream & out, const CVector<T>& v1)
{
	out << "Num: " << v1.m_size;
	if (v1.m_size > 0)
	{
		out << " Data: ";
		int size = v1.m_size;
		T *p = v1.m_pData;
		for (out << *p; --size; out << ' ' << *++p);
	}
	out << '\n';
	return out;
}

// min
template <typename T>
T min(const T m1, const T m2)
{
	if (m1 > m2) return m2;
	return m1;
}

// max
template <typename T>
T max(const T m1, const T m2)
{
	if (m1 > m2) return m1;
	return m2;
}


// ������� 1 ������
// ����� ��������
template <typename T>
T *sum(int size, T *p1, T *p2)
{
	T *c = new T[size]; // ������ �����
	T *last = c + size - 1;
	for (*c = *p1 + *p2; c != last; *++c = *++p1 + *++p2);
	return c - size + 1;
}

// �������� ��������
template <typename T>
T *dif(int size, T *p1, T *p2)
{
	T *c = new T[size]; // ������ ��������
	T *last = c + size - 1;
	for (*c = *p1 - *p2; c != last; *++c = *++p1 - *++p2);
	return c - size + 1;
}

// ��������� ������������ ��������
template <typename T>
T scalarProduct(int size, T *p1, T *p2)
{
	T product = *p1 * *p2;
	for (; --size; product += *++p1 * *++p2);
	return product;
}

// ����� �������
template <typename T>
T length(int size, T *p1)
{
	return sqrt(scalarProduct(size, p1, p1)); // |a|=sqrt((a*a))
}

// ���� ���� ���������
template <typename T>
double vectorAngle(int size, T *p1, T *p2)
{
	return acos(scalarProduct(size, p1, p2) / (length(size, p1)*length(size, p2))); // ���� ����� ��������� � ��������
}

// ��������� ������������
template <typename T>
T *vectorProduct(int size, T *p1, T *p2)
{
	T *c = new T[size];
	//for (int i = 0; i < size; *c++ = *(p1 + (i + 1) % 3) * *(p2 + (i + 2) % 3) - *(p1 + (i + 2) % 3) * *(p2 + (i + 1) % 3), ++i);
	*c = *(p1 + 1) * *(p2 + 2) - *(p1 + 2) * *(p2 + 1);
	*++c = *(p1 + 2) * *p2 - *p1 * *(p2 + 2);
	*++c = *p1 * *(p2 + 1) - *(p1 + 1) * *p2;
	return c - size + 1;
}

// ������� ���������������
template <typename T>
T areaParallelogram(int size, T *p1, T *p2)
{
	T *c = vectorProduct(size, p1, p2); // ������
	T len = length(size, c);
	delete[] c;
	return len;
}

// �������� ������������ �������� � ���������� �� ��������� ������������ ������
template <typename T>
void vectorDelete(int size, T **pp)
{
	for (delete[] * pp; --size; delete[] * ++pp);
}

// �������� ������������ ��������
template <typename T>
void CVectorDelete(int n, ...)
{
	int *p = &n; // ��������� �� ������ ���������� ����������
	if (n > 0)
	{
		++p; // ������ ������ ����������-����������
			 // ������ *p �� **p
		union Pointer
		{
			T **pp;
			T *p0;
		};
		Pointer Change;
		Change.p0 = (T *)p;
		// �������� ������������ ��������
		if (Change.pp) delete[] * Change.pp;
		for (int i = 1; i < n; ++i)
			if (++Change.pp) delete[] * Change.pp;
	}
}