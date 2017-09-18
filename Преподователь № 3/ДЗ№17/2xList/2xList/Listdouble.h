#pragma once
#include "Nodedouble.h"
template <typename U>
class List
{
private:
	Node<U> * m_head = nullptr;//Ссылка на первый узел
	Node<U> * m_tail = nullptr;
	int m_length;
public:
	~List();
	void Add(U value);
	void RemoveFirst();
	void RemoveLast();
	void Show();
	bool Remove(U value);
	void ClearList();
	bool IsEmpty();
	/*List<U>(List && list);
	List<U>(const List& list);
	List<U>& operator =(const List& right);
	List<U>& operator=(List && right);*/
};
template <typename U>
void List<U>::RemoveLast()
{
	Node<U>* prev = m_tail;
	if (prev != nullptr)
	{
		prev = prev->GetPrev();
		m_tail = prev;
	}
	m_length--;
}
template <typename U>
void List<U> ::RemoveFirst()
{
	Node<U> *last = m_head;
	if (last != nullptr)
	{
		last = last->GetNext();
		m_head = last;
	}
	m_length--;
}
template <typename U>
List<U>::~List()
{
	while (m_head != nullptr)
	{
		m_tail = m_head->GetNext();
		delete m_head;
		m_head = m_tail;
	}
}
template <typename U>
void List<U> ::Add(U value)
{
	Node<U> * node = new Node<U>(value);
	//Node n(value);//Это не нужно так как это уходит
	if (m_head == nullptr || m_tail == nullptr)
	{
		m_head = node;
		m_tail = node;
	}
	else
	{
		Node<U> * last = m_head;//Запоминаем элемаент который мы проверяем
		Node<U> * prev = m_tail;
		while (last->GetNext() != nullptr && prev->GetPrev() != nullptr)//Есть ли следующий элемент
		{
			last = last->GetNext();//Смещение узла на +1
			prev = prev->GetPrev();
		}
		last->SetNext(node);//Связываем узел
		prev->SetPrev(node);
	}
	++m_length;
}
template <typename U>
bool List<U> ::Remove(U value)
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		if (m_tail != nullptr)
		{
			Node<U> *last = m_tail;
			if (m_length != 1)
			{
				for (int i = 1; i < (m_length - 3); i++)
				{
					last = last->GetNext();
				}
				Node<U> *prelast = last->GetNext();
				last->SetNext(prelast->GetNext());
				delete prelast;
				return true;
			}
		}
		else
		{
			Node<U> *last = m_tail;
			m_tail = m_tail->GetNext();
			delete last;
			return false;
		}
	}
}
template <typename U>
void List<U>::ClearList()
{
	Node<U> *current2 = m_tail;
	Node<U> * to_del2 = m_tail;
	while (to_del2 != nullptr)
	{
		current2 = current2->GetNext();
		delete to_del2;
		to_del2 = current2;
	}
	m_tail = nullptr;
	m_length = 0;
}
template <typename U>
void List<U>::Show()
{
	Node<U> * node = m_head;//То последний элемент это наше новое начало
	while (node != nullptr)//Пока прошлый элемент(то есть наше новое начало) не равно нулевому указателю
	{
		cout << node->GetValue() << endl;//Выводим на экран значения
		node = node->GetNext();//Смещение узла на количевство добавленных элементов
	}
}
template <typename U>
bool List<U> ::IsEmpty()
{
	return m_head == nullptr;
}
//template <typename U>
//List<U>& List<U>::operator = (const List& right)
//{
//	if (this != &right)
//	{
//		delete m_head;
//		delete m_tail;
//		m_head = nullptr;
//		m_tail = nullptr;
//		Node<U>*node = right.m_head;
//		Node<U>*node2 = right.m_tail;
//		for (size_t i = 0; i < right.m_length; i++)
//		{
//			this->Add(node->GetValue());
//			node = node->GetNext();
//			this->Add(node2->GetValue());
//			node2 = node2->GetPrev();
//		}
//	}
//	return *this;
//}
//template <typename U>
//List<U>& List<U>::operator = (List&& right)
//{
//	if (this != &right)
//	{
//		delete m_head;
//		delete m_tail;
//		m_length = right.m_length;
//		m_head = right.m_head;
//		m_tail = right.m_tail;
//		right.m_head = nullptr;
//		right.m_tail = nullptr;
//	}
//	return *this;
//}
//template <typename U>
//List<U>::List(const List& list)
//{
//	Node<U>*node = list.m_head;
//	Node<U>*node2 = list.m_tail;
//	for (size_t i = 0; i < list.m_length; i++)
//	{
//		this->Add(node->GetValue());
//		node = node->GetNext();
//		this->Add(node2->GetValue());
//		node2 = node2->GetPrev();
//	}
//}
//
//template <typename U>
//List<U>::List(List && list)
//{
//	this->m_head = list.m_head;
//	this->m_tail = list.m_tail;
//	this->m_length = list.m_length;
//	list.m_head = nullptr;
//	list.m_tail = nullptr;
//	list.m_length = 0;
//}