#pragma once
#include"Node.h"
#include "List.h"
typedef unsigned int uint;
template <typename N>
class Node;
template <typename U>
class List;
template <typename T>
class ListIterator
{
private:
	Node<T>*current = nullptr;
public:
	ListIterator(Node<T> * const node);
	~ListIterator() = default;
	ListIterator<T>& operator ++();
	bool operator != (const ListIterator<T> & rightit);
	T& operator*();
	const T& operator*() const;
};
template < typename T >
ListIterator<T>::ListIterator(Node<T> * const node) : current(node){}
template < typename T >
ListIterator<T>& ListIterator<T> :: operator ++()
{
	current = current->GetNext();
	//Аналогично return current;
	return *this;
}
template <typename T>
bool ListIterator<T>::operator!= (const ListIterator<T> & rightit)
{
	return  current != rightit.current;
}
template <typename T>
T& ListIterator<T>::operator*()
{
	return current->GetValue();
}
template <typename T>
const T& ListIterator<T>:: operator*() const
{
	return current->GetValue();
}