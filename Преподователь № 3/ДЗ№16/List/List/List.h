#pragma once
#include "Node.h"
#include "ListIterator.h"
template <typename U>
class List
{
private:
	Node<U> * m_head = nullptr;//Ссылка на первый узел
	int m_length;
	//int size;
public:
	~List();
	void Add(U value);
	void RemoveFirst();
	void RemoveLast();
	void Show();
	bool Remove(U value);
	ListIterator<U> begin();
	ListIterator<U> end();
	//bool Remove(U value, int size);Свой ремув
	void ClearList();
	bool IsEmpty();
	//List<U>(List<U>&& list);
	//List<U>(const List<U>& list);
	//List<U>& operator =(const List<U>& right);
	//List<U>& operator=(List<U>&& right);

	//void AddLast(U value);
};
template <typename U>
ListIterator<U> List<U>::begin()
{
	return ListIterator<U>(m_head);
}
template <typename U>
ListIterator<U>  List<U>::end()
{
	return nullptr;
}
template <typename U>
void List<U>::RemoveLast()
{
	Node<U> *last = m_head;
	Node<U> *newlast = m_head;
	while (last->GetNext() != nullptr)
	{
		last = last->GetNext();
		if (last->GetNext() != nullptr)
		{
			newlast = last;
		}
	}
	newlast->m_next = nullptr;
	delete last;
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
		Node<U> *pTemp = m_head;
		m_head = m_head->GetNext();
		delete pTemp;
	}
}
template <typename U>
void List<U> ::Add(U value)
{
	Node<U> * node = new Node<U>(value);
	//Node n(value);//Это не нужно так как это уходит
	if (m_head == nullptr)
	{
		m_head = node;
	}
	else
	{
		Node<U> * last = m_head;//Запоминаем элемаент который мы проверяем
		while (last->GetNext() != nullptr)//Есть ли следующий элемент
		{
			last = last->GetNext();//Смещение узла на +1
		}
		last->SetNext(node);//Связываем узел
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
		if (m_head != nullptr)
		{
			Node<U> *last = m_head;
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
			Node<U> *last = m_head;
			m_head = m_head->GetNext();
			delete last;
			return false;
		}
	}
	m_length--;
}
//template <typename U>
//bool List<U>::Remove(U value,int size)
//{
//	if (IsEmpty())
//	{
//		return false;
//	}
//	else
//	{
//		if (m_head != nullptr)
//		{
//			Node<U> *last = m_head;
//			if (m_length != 1)
//			{
//				for (int i = 1; i < (m_length - size); i++)
//				{
//					last = last->GetNext();
//				}
//				Node<U> *prelast = last->GetNext();
//				last->SetNext(prelast->GetNext());
//				delete prelast;
//				return true;
//			}
//		}
//		else
//		{
//			Node<U> *last = m_head;
//			m_head = m_head->GetNext();
//			delete last;
//			return false;
//		}
//	}
//}
template <typename U>
void List<U>::ClearList()
{
	Node<U> *current = m_head;
	Node<U> *to_del = m_head;
	while (to_del != nullptr)
	{
		current = current->GetNext();
		delete to_del;
		to_del = current;
	}
	m_head = nullptr;
	m_length = 0;
}
template <typename U>
void List<U>::Show()
{
	Node<U> * last = m_head;//То последний элемент это наше новое начало
	while (last != nullptr)//Пока прошлый элемент(то есть наше новое начало) не равно нулевому указателю
	{
		cout << last->GetValue() << endl;//Выводим на экран значения
		last = last->GetNext();//Смещение узла на количевство добавленных элементов
	}
}
template <typename U>
bool List<U> ::IsEmpty()
{
	return m_head == nullptr;
}
//template <typename U>
//List<U>& List<U>::operator = (const List<U>& right)
//{
//	if (this != &right)
//	{
//		delete m_head;
//		m_head = nullptr;
//		Node<U>*node = right.m_head;
//		for (size_t i = 0; i < right.m_length; i++)
//		{
//			this->Add(node->GetValue());
//			node = node->GetNext();
//		}
//	}
//	return *this;
//}
//
//template <typename U>
//List<U>& List<U>::operator = (List<U>&& right)
//{
//	if (this != &right)
//	{
//		delete m_head;
//		m_length = right.m_length;
//		m_head = right.m_head;
//		right.m_head = nullptr;
//	}
//	return *this;
//}
//template <typename U>
//List<U>::List(const List<U>& list)
//{
//	Node<U>*node = list.m_head;
//	for (size_t i = 0; i < list.m_length; i++)
//	{
//		this->Add(node->GetValue());
//		node = node->GetNext();
//	}
//}
//
//template <typename U>
//List<U>::List(List<U> && list)
//{
//	this->m_head = list.m_head;
//	this->m_length = list.m_length;
//	list.m_head = nullptr;
//	list.m_length = 0;
//}