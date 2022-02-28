#pragma optimize("", off)
#include <iostream>

using namespace std;

template<typename LT>
class tlist
{
public:
	void output(); // ������� ������
	int input(); // ������� �����

				   // ��������� ������������ ��������
	template <typename LT>
	friend double scal(tlist &t1, tlist &t2);

	// ����� �������
	double norm();
	//�����
	tlist<LT> &sum(tlist<LT> &t1, tlist<LT> &t2);
	// ��������
	tlist<LT> &dif(tlist<LT> &t1, tlist<LT> &t2);

	// ����������� � �������
	tlist<LT> &add(tlist<LT> &t1);
	// ��������� �� �������
	tlist<LT> &sub(tlist<LT> &t1);

	// get(int index) l-value
	LT & get(int n);
	// get(int index) r-value
	const LT get(int n) const;

public:
	tlist();      // ����������� �� ���������
	tlist(const tlist&tl);  // ����������� �����������
	tlist(tlist&&tl);    // ����������� �����������
	~tlist();

protected:
	struct titem      // ������� ��������
	{
		LT m_value;    // �������� ������
		titem*m_pNext;  // ������ �� ��������� �������
		titem()
		{
			m_value = LT(0);  // 0 ��� ������� �����, ������ ��� ��������
			m_pNext = nullptr;
		};
	};

protected:
	titem*m_pFirst;    // ������ ������ ������
	LT m_null; // ��� ������
	const LT c_m_null = 0;
protected:
	void init();      // ������� �������������
	void destroy(titem*pi);  // ������� ������� ���������
	//void copy_insecure(tlist&tl);  // �����������
public:
	int push_back(LT val);  // ���������� � ����� ������
	int size(void);    // ���������� �������
	const int size(void) const;    // ���������� �������
	int copy(const tlist&tl);  // �����������
	int move(tlist&tl);  // ����������� ������������

public:
	class iterator
	{
		friend class tlist;  // �������� ����� ����� ������ ������ � ���������
	protected:
		titem*m_pItem;  // ������ �� ������� ������
	public:
		iterator()    // ����������� �� ��������� � ������� ������
		{
			m_pItem = nullptr;  // �� ��������� �� �� ��� �� ���������
		};
		iterator(const iterator&it) // ����������� ����������� - ������� ������
		{
			m_pItem = it.m_pItem;
		}
	protected:
		iterator(titem*p)  // ����������� ������������� � ������ ������ �� ������
		{
			m_pItem = p;
		};
	public:
		LT operator*()  // ��������* - ���������� �������� ������
		{
			if (m_pItem)return m_pItem->m_value; // ���� ���� ������ - ��������
			return LT(0);        // ��� ������ � ���������� 0
		}
		iterator&operator++()  // ���������� ++
		{
			if (m_pItem) m_pItem = m_pItem->m_pNext;
			return *this;
		}
		iterator operator++(int)  // ����������� ++
		{
			iterator it(*this);
			if (m_pItem) m_pItem = m_pItem->m_pNext;
			return it;
		}
		iterator&operator=(const iterator&it)  // ������������ ������������
		{
			m_pItem = it.m_pItem;
			return *this;
		}
		bool operator==(const iterator&it)  // ��������� �� ���������
		{
			return (m_pItem == it.m_pItem ? true : false);
		}
		bool operator!=(const iterator&it)  // ��������� �� �����������
		{
			return (m_pItem != it.m_pItem ? true : false);
		}
	};
public:
	iterator begin();
	iterator end();
};

template<typename LT>
tlist<LT>::tlist()
{
	init();
}

template<typename LT>
tlist<LT>::tlist(const tlist<LT>&tl)
{
	init();
	copy(tl);
}

template<typename LT>
tlist<LT>::tlist(tlist<LT>&&tl)
{
	init();
	move(tl);
}

template<typename LT>
tlist<LT>::~tlist()
{
	destroy(m_pFirst);
}

template<typename LT>
void tlist<LT>::init()
{
	m_pFirst = 0;
}

template<typename LT>
void tlist<LT>::destroy(titem*pi)
{
	titem*p;
	while (pi)      // ���� �� ��������� (���� ������� ����������)
	{
		p = pi->m_pNext;  // ���������� ��������� �������
		delete pi;    // ������� ������� �������
		pi = p;    // ��������� ���� �������
	}
}

template<typename LT>
int tlist<LT>::push_back(LT val)
{
	titem*pLast, *pNew;
	pNew = new titem;    // ������� �������
	if (pNew)      // ���� ������� ��������, �� ��������� � �����
	{
		if (m_pFirst)  // ���������, ���� �� �������� �> ���� ���������
		{
			pLast = m_pFirst;      // �������� � �������
			while (pLast->m_pNext)    // ���� ���� ���������
			{
				pLast = pLast->m_pNext;  // ��������� -> ���������
			}
			pLast->m_pNext = pNew;  // ����� ��������� -> ����� ���������
		}
		else          // ��������� �� ���� -> ����� ������
		{
			m_pFirst = pNew;
		}
		pNew->m_value = val;      // ��������� ������
		return size() - 1;      // ���������� ����� ������������ ��������
	}
	return -1;          // ������
}

template<typename LT>
int tlist<LT>::size(void)  // ���������� ������� ������
{
	titem*p;
	int s = 0;
	p = m_pFirst;      // �������� � �������
	while (p)      // ���� �������� ����
	{
		p = p->m_pNext;  // ��������� �������
		s++;      // ��������� �������
	}
	return s;
}

template<typename LT>
const int tlist<LT>::size(void) const
{
	titem*p;
	int s = 0;
	p = m_pFirst;      // �������� � �������
	while (p)      // ���� �������� ����
	{
		p = p->m_pNext;  // ��������� �������
		s++;      // ��������� �������
	}
	return s;
}

template<typename LT>
int tlist<LT>::copy(const tlist<LT>&lt)  // �����������
{
	if (this == &lt)return size();    // ��������� �� a = a
	titem*p;
	tlist nl;    // ������ ��� ����������� �����������
	p = lt.m_pFirst;  // �������� � ������� ��������
	while (p)    // ���� �������� ����
	{
		if (nl.push_back(p->m_value) < 0)return 0;  // ��������� ��������
													// ���� ������, �� �������
		p = p->m_pNext;          // ��������� �������
	}
	return move(nl);    // ������� ������ �������� � ������� ������
}

template<typename LT>
int tlist<LT>::move(tlist<LT>&lt)  // ����������� ������������
{
	if (this != &lt)       // ��������� �� a = a
	{
		destroy(m_pFirst);    // ������� ������ ������
		m_pFirst = lt.m_pFirst;  // �������� ����� ������
		lt.init();      // ������� ����������
	}
	return size();      // ����� ������
}

/*
template<typename LT>
inline void tlist<LT>::copy_insecure(tlist & lt)
{
	if ((this != &lt) && (this->m_pFirst) && lt.m_pFirst) // �������� �� lt = lt � �� �������
	{
		titem* p = lt.m_pFirst;
		titem* p0 = m_pFirst;

		while ((p->m_pNext) && (p0->m_pNext))
		{
			p0->m_value = p->m_value;
			p = p->m_pNext;
			p0 = p0->m_pNext;
		}
		p0->m_value = p->m_value;


		if (p0->m_pNext)
		{
			titem*pt = p0->m_pNext;
			p0->m_pNext = nullptr;
			p0 = pt;
			//destroy(p0);
			while (p0)
			{
				pt = p0->m_pNext;
				delete p0;    
				p0 = pt;    
			}
			// end
		}
		else if (p->m_pNext)
		{
			p = p->m_pNext;
			while (p)
			{
				//push_back(p->m_value);
				p0->m_pNext = new titem;
				p0 = p0->m_pNext;
				p0->m_value = p->m_value;
				//end
				p = p->m_pNext;
			}
		}
	}
}*/

template<typename LT>
typename tlist<LT>::iterator tlist<LT>::begin()  // ������ typename, ����� ���������� ����,
												 // ��� tlist<LT>::iterator �������� �����
{
	return iterator(m_pFirst);  // ������ �� ������ �������
}

template<typename LT>
typename tlist<LT>::iterator tlist<LT>::end()
{
	return iterator();      // ������ �� ��������� ������� ����� ����������
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
// �����
template <typename LT>
void tlist<LT>::output()
{
	cout << "Num: " << size();

	if (size() > 0)
	{
		cout << " Data:";
		for (auto it = begin(); it != end(); ++it)
		{
			cout << ' ' << *it;
		}
	}
	cout << '\n';
}

template<typename LT>
inline int tlist<LT>::input()
{
	int tempSize;
	cout << "Enter size: ";
	cin >> tempSize;
	if (tempSize > 0)
	{
		if (m_pFirst)
		{
			destroy(m_pFirst); // ~tlist<LT>();
			init(); // tlist<LT>();
		}
		LT number;
		for (int i = 0; i < tempSize; ++i)
		{
			cin >> number;
			push_back(number);
		}
		return size();
	}
	return 0; // ���������� ������ ���������� �������, ����� 0
}

// ��������� ������������
template <typename LT>
double scal(tlist<LT> &t1, tlist<LT> &t2)
{
	double product = 0;
	auto it1 = t1.begin();
	auto it2 = t2.begin();
	auto end1 = t1.end();
	auto end2 = t2.end(); // ��� �������, ��� �������� ������ ��� t2.end()
	while ((it1 != end1) && (it2 != end2))
	{
		product += *it1 * *it2;
		++it1, ++it2;
	}
	return product;
}

// �����
template <typename LT>
double tlist<LT>::norm()
{
	return sqrt(scal(*this, *this)); // |a|=sqrt((a,a))
}

//�����
template <typename LT>
tlist<LT> &tlist<LT>::sum(tlist<LT> &t1, tlist<LT> &t2)
{
	titem *p1 = t1.m_pFirst;
	titem *p2 = t2.m_pFirst;
	tlist nl;    // ������ ��� ����������� �����������
	
	while (p1 && p2)
	{
		nl.push_back(p1->m_value + p2->m_value);
		p1 = p1->m_pNext;    
		p2 = p2->m_pNext;
	}
	while (p1)
	{
		nl.push_back(p1->m_value);
		p1 = p1->m_pNext;
	}
	while (p2)
	{
		nl.push_back(p2->m_value);
		p2 = p2->m_pNext;
	}
	this->move(nl);
	return *this;
}

//��������
template <typename LT>
tlist<LT> &tlist<LT>::dif(tlist<LT> &t1, tlist<LT> &t2)
{
	titem *p1 = t1.m_pFirst;
	titem *p2 = t2.m_pFirst;
	tlist nl;    // ������ ��� ����������� �����������

	while (p1 && p2)
	{
		nl.push_back(p1->m_value - p2->m_value);
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}
	while (p1)
	{
		nl.push_back(p1->m_value);
		p1 = p1->m_pNext;
	}
	while (p2)
	{
		nl.push_back(-(p2->m_value));
		p2 = p2->m_pNext;
	}
	this->move(nl);
	return *this;
}

//����������
template <typename LT>
tlist<LT> &tlist<LT>::add(tlist<LT> &t1)
{
	titem *p1 = t1.m_pFirst;
	titem *p = m_pFirst;

	while (p1 && p)
	{
		p->m_value += p1->m_value;
		p1 = p1->m_pNext;
		p = p->m_pNext;
	}
	while (p1)
	{
		push_back(p1->m_value);
		p1 = p1->m_pNext;
	}
	return *this;
}

//���������
template <typename LT>
tlist<LT> &tlist<LT>::sub(tlist<LT> &t1)
{
	titem *p1 = t1.m_pFirst;
	titem *p = m_pFirst;

	while (p1 && p)
	{
		p->m_value -= p1->m_value;
		p1 = p1->m_pNext;
		p = p->m_pNext;
	}
	while (p1)
	{
		push_back(-(p1->m_value));
		p1 = p1->m_pNext;
	}
	return *this;
}

template<typename LT>
LT & tlist<LT>::get(int n)
{
	if ((n > 0) && (n <= size()))
	{
		titem*p = m_pFirst;
		for (int i = 1; i < n; ++i) p = p->m_pNext;
		return p->m_value;
	}
	cout << "\nError lvalue!\n";
	m_null = 0;
	return m_null;
}

template<typename LT>
const LT tlist<LT>::get(int n) const
{
	if ((n > 0) && (n <= size()))
	{
		titem*p = m_pFirst;
		for (int i = 1; i < n; ++i) p = p->m_pNext;
		return p->m_value;
	}
	cout << "\nError rvalue!\n";
	return c_m_null;
}