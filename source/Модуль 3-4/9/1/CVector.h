#pragma optimize("", off)
#include <iostream>

using namespace std;

template<typename LT>
class tlist
{
public:
	void output(); // функция вывода
	int input(); // функция ввода

				   // скалярное произведение векторов
	template <typename LT>
	friend double scal(tlist &t1, tlist &t2);

	// длина вектора
	double norm();
	//сумма
	tlist<LT> &sum(tlist<LT> &t1, tlist<LT> &t2);
	// разность
	tlist<LT> &dif(tlist<LT> &t1, tlist<LT> &t2);

	// прибавление к вектору
	tlist<LT> &add(tlist<LT> &t1);
	// вычитание из вектора
	tlist<LT> &sub(tlist<LT> &t1);

	// get(int index) l-value
	LT & get(int n);
	// get(int index) r-value
	const LT get(int n) const;

public:
	tlist();      // конструктор по умолчанию
	tlist(const tlist&tl);  // конструктор копирования
	tlist(tlist&&tl);    // конструктор перемещения
	~tlist();

protected:
	struct titem      // элемент хранения
	{
		LT m_value;    // значение данных
		titem*m_pNext;  // ссылка на следующий элемент
		titem()
		{
			m_value = LT(0);  // 0 для простых типов, пустой для объектов
			m_pNext = nullptr;
		};
	};

protected:
	titem*m_pFirst;    // храним начало списка
	LT m_null; // для ошибок
	const LT c_m_null = 0;
protected:
	void init();      // функция инициализации
	void destroy(titem*pi);  // функция очистки элементов
	//void copy_insecure(tlist&tl);  // копирование
public:
	int push_back(LT val);  // добавление в конец списка
	int size(void);    // вычисление размера
	const int size(void) const;    // вычисление размера
	int copy(const tlist&tl);  // копирование
	int move(tlist&tl);  // копирование перемещением

public:
	class iterator
	{
		friend class tlist;  // основной класс имеет полный доступ к итератору
	protected:
		titem*m_pItem;  // ссылка на элемент списка
	public:
		iterator()    // конструктор по умолчанию – внешний доступ
		{
			m_pItem = nullptr;  // по умолчанию ни на что не ссылается
		};
		iterator(const iterator&it) // конструктор копирования - внешний доступ
		{
			m_pItem = it.m_pItem;
		}
	protected:
		iterator(titem*p)  // конструктор инициализации – доступ только из списка
		{
			m_pItem = p;
		};
	public:
		LT operator*()  // оператор* - возвращает значение данных
		{
			if (m_pItem)return m_pItem->m_value; // если есть ссылка - значение
			return LT(0);        // нет ссылки – возвращает 0
		}
		iterator&operator++()  // префиксный ++
		{
			if (m_pItem) m_pItem = m_pItem->m_pNext;
			return *this;
		}
		iterator operator++(int)  // постфиксный ++
		{
			iterator it(*this);
			if (m_pItem) m_pItem = m_pItem->m_pNext;
			return it;
		}
		iterator&operator=(const iterator&it)  // присваивание копированием
		{
			m_pItem = it.m_pItem;
			return *this;
		}
		bool operator==(const iterator&it)  // сравнение на равенство
		{
			return (m_pItem == it.m_pItem ? true : false);
		}
		bool operator!=(const iterator&it)  // сравнение на неравенство
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
	while (pi)      // цикл по элементам (пока элемент существует)
	{
		p = pi->m_pNext;  // запоминаем следующий элемент
		delete pi;    // удаляем текущий элемент
		pi = p;    // следующий стал текущим
	}
}

template<typename LT>
int tlist<LT>::push_back(LT val)
{
	titem*pLast, *pNew;
	pNew = new titem;    // создаем элемент
	if (pNew)      // если элемент создался, то добавляем в конец
	{
		if (m_pFirst)  // проверяем, были ли элементы –> ищем последний
		{
			pLast = m_pFirst;      // начинаем с первого
			while (pLast->m_pNext)    // пока есть следующий
			{
				pLast = pLast->m_pNext;  // следующий -> последний
			}
			pLast->m_pNext = pNew;  // нашли последний -> новый следующий
		}
		else          // элементов не было -> новый первый
		{
			m_pFirst = pNew;
		}
		pNew->m_value = val;      // сохраняем данные
		return size() - 1;      // возвращаем номер добавленного элемента
	}
	return -1;          // ошибка
}

template<typename LT>
int tlist<LT>::size(void)  // вычисление размера списка
{
	titem*p;
	int s = 0;
	p = m_pFirst;      // начинаем с первого
	while (p)      // пока элементы есть
	{
		p = p->m_pNext;  // следующий элемент
		s++;      // добавляем счетчик
	}
	return s;
}

template<typename LT>
const int tlist<LT>::size(void) const
{
	titem*p;
	int s = 0;
	p = m_pFirst;      // начинаем с первого
	while (p)      // пока элементы есть
	{
		p = p->m_pNext;  // следующий элемент
		s++;      // добавляем счетчик
	}
	return s;
}

template<typename LT>
int tlist<LT>::copy(const tlist<LT>&lt)  // копирование
{
	if (this == &lt)return size();    // проверяем на a = a
	titem*p;
	tlist nl;    // объект для безопасного копирования
	p = lt.m_pFirst;  // начинаем с первого элемента
	while (p)    // пока элементы есть
	{
		if (nl.push_back(p->m_value) < 0)return 0;  // добавляем значение
													// если ошибка, то выходим
		p = p->m_pNext;          // следующий элемент
	}
	return move(nl);    // готовые данные передаем в текущий объект
}

template<typename LT>
int tlist<LT>::move(tlist<LT>&lt)  // копирование перемещением
{
	if (this != &lt)       // проверяем на a = a
	{
		destroy(m_pFirst);    // удаляем старые данные
		m_pFirst = lt.m_pFirst;  // передаем новые данные
		lt.init();      // удаляем информацию
	}
	return size();      // новый размер
}

/*
template<typename LT>
inline void tlist<LT>::copy_insecure(tlist & lt)
{
	if ((this != &lt) && (this->m_pFirst) && lt.m_pFirst) // проверка на lt = lt и на пустоту
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
typename tlist<LT>::iterator tlist<LT>::begin()  // указан typename, чтобы компилятор знал,
												 // что tlist<LT>::iterator является типом
{
	return iterator(m_pFirst);  // ссылка на первый элемент
}

template<typename LT>
typename tlist<LT>::iterator tlist<LT>::end()
{
	return iterator();      // ссылка на следующий элемент после последнего
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
// вывод
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
	return 0; // возвращает размер введенного вектора, иначе 0
}

// скалярное произведение
template <typename LT>
double scal(tlist<LT> &t1, tlist<LT> &t2)
{
	double product = 0;
	auto it1 = t1.begin();
	auto it2 = t2.begin();
	auto end1 = t1.end();
	auto end2 = t2.end(); // так быстрее, чем вызывать каждый раз t2.end()
	while ((it1 != end1) && (it2 != end2))
	{
		product += *it1 * *it2;
		++it1, ++it2;
	}
	return product;
}

// норма
template <typename LT>
double tlist<LT>::norm()
{
	return sqrt(scal(*this, *this)); // |a|=sqrt((a,a))
}

//сумма
template <typename LT>
tlist<LT> &tlist<LT>::sum(tlist<LT> &t1, tlist<LT> &t2)
{
	titem *p1 = t1.m_pFirst;
	titem *p2 = t2.m_pFirst;
	tlist nl;    // объект для безопасного копирования
	
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

//разность
template <typename LT>
tlist<LT> &tlist<LT>::dif(tlist<LT> &t1, tlist<LT> &t2)
{
	titem *p1 = t1.m_pFirst;
	titem *p2 = t2.m_pFirst;
	tlist nl;    // объект для безопасного копирования

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

//добавление
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

//вычитание
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