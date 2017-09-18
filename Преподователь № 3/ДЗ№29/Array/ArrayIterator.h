#pragma once
#include "Array.h"
template <typename U>
class Array;
template <typename T>
class ArrayIterator
{
private:
	Array<T> *m_arrptr = nullptr;
	int index;
public:
	ArrayIterator(Array<T> * const ptrar, int in);
	~ArrayIterator() = default;
	ArrayIterator<T>& operator ++();
	bool operator != (const ArrayIterator<T> & rightit);
	T& operator*();
	const T& operator*() const;
};
template < typename T >
ArrayIterator<T>::ArrayIterator(Array<T> * const ptrar,int in) : m_arrptr(ptrar), index(in){}
template < typename T >
ArrayIterator<T>& ArrayIterator<T> :: operator ++()
{
	++index;
	return *this;
}
template <typename T>
bool ArrayIterator<T>::operator!= (const ArrayIterator<T> & rightit)
{
	return  m_arrptr!= rightit.m_arrptr || index != rightit.index;
}
template <typename T>
T& ArrayIterator<T>::operator*()
{
	return (*m_arrptr)[index];
}
template <typename T>
const T& ArrayIterator<T>::operator*() const
{
	return (*m_arrptr)[index];
}