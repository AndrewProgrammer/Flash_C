#pragma once
#include <iostream>
#include <ostream>
using namespace std;
typedef unsigned int uint;
template < typename T>
class Array
{
private:
	uint m_length = 5;
	T *m_arr = 0;
	uint m_capacity = 0;

public:
	Array();
	~Array();
	void Add(T valua);
	void PrintArr();
	void Remove(T valua);
	void RemoveAt(int index);
	bool Contains(T valua);


	T& operator[] (int index);
	bool operator== (int index);
	bool operator!= (int index);
	Array<T>& operator =(const Array<T>& right);

	const T* GetArray() const;
	uint GetArLength() const;

	Array<T> (T ar[]);
	Array<T> (Array<T>&& ar);
	Array<T> (const Array<T>& ar);
	Array<T>& operator=(Array<T>&& right);
	void Swap(Array<T>& ar);
};

//void operator <<(std::ostream& os, const Array& right)
//{
//	for (int i = 0; i < right.GetArLength(); i++)
//	{
//		return os << right.GetArray[i] << " ";
//	}
//}
template <typename T>
Array<T> ::Array()
{
	m_capacity = m_length;
	m_arr = new T[m_length];
	for (int i = 0; i < m_length; i++)
		m_arr[i] = rand() % 10;
}
template <typename T>
Array<T> :: ~Array()
{
	delete[] m_arr;
	cout << "Destructor" << endl;
}
template <typename T>
void Array<T>::Add(T valua)
{
	m_capacity = m_length + 1;
	T *temp = new T[m_capacity];
	for (int i = 0; i < m_length; i++)
		temp[i] = m_arr[i];
	temp[m_capacity - 1] = valua;
	delete[]m_arr;
	m_arr = temp;
}
template <typename T>
void Array<T>::PrintArr()
{
	for (int i = 0; i < m_capacity; ++i)
		cout << m_arr[i] << ' ';
}
template <typename T>
void Array<T>::Remove(T valua)
{
	int count = 0;
	for (int i = 0; i < m_length; i++)
	{
		if (m_arr[i] != valua)
			++count;
	}
	m_capacity = count;
	T*temp = new T[m_capacity];
	int j = 0;
	for (int i = 0; i < m_length; i++)
	{
		if (m_arr[i] != valua)
		{
			temp[j] = m_arr[i];
			++j;
		}
	}
	delete[] m_arr;
	m_arr = temp;
}
template <typename T>
void Array<T>::RemoveAt(int index)
{
	m_capacity = m_length - 1;
	T *temp = new T[m_capacity];
	for (int i = 0; i < m_length; i++)
	{
		if (i < index)
			temp[i] = m_arr[i];
		if (i > index)
			temp[i - 1] = m_arr[i];
	}
	delete[] m_arr;
	m_arr = temp;
}
template <typename T>
bool Array<T>::Contains(T valua)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_arr[i] == valua)
		{
			return true;
			break;
		}
	}
	return false;
}
template <typename T>
T& Array<T>:: operator[] (int index)
{
	if (index > m_length && index<0)
		cout << "Error";
	else return m_arr[index];
}
template <typename T>
bool Array<T>:: operator== (int index)
{
	return m_arr[m_length] == m_arr[m_index] ? true : false;
}
template <typename T>
bool Array<T>::operator!= (int index)
{
	return m_arr[m_length] == m_arr[m_index] ? true : false;
}
template <typename T>
Array<T>& Array<T> :: operator =(const Array<T>& right)
{
	if (this != &right)
	{
		Array<T>(right).Swap(*this);
	}
	cout << "Assignment operator" << endl;

	return *this;
}
template <typename T>
const T* Array<T>::GetArray() const
{
	return m_arr;
}
template <typename T>
uint Array<T> ::GetArLength() const
{
	return m_length;
}
template <typename T>
Array<T>::Array<T>(T ar[])
{
	m_arr = new T[m_length + 1u];
	for (int i = 0; i < m_length; i++)
	{
		m_arr[i] = ar[i];
	}
	cout << "Parametrized constructor" << endl;
}
template <typename T>
Array<T>::Array<T>(Array<T> && ar)
{
	m_capacity = ar.m_capacity;
	m_length = ar.m_length;
	m_arr = ar.m_arr;

	ar.m_capacity = 0u;
	ar.m_length = 0u;
	ar.m_arr = nullptr;//!!!!!
}
template <typename T>
Array<T>::Array<T>(const Array<T>& ar)
{
	m_capacity = ar.m_capacity;
	m_length = ar.m_length;

	m_arr = new T[m_capacity];
	for (int i = 0; i < m_length; i++)
	{
		m_arr[i] = ar.m_arr[i];
	}
	cout << "Copy constructor" << endl;
}
template <typename T>
Array<T>& Array<T>:: operator=(Array<T>&& right)
{
	if (this != &right)
	{
		Array<T>(move(right)).Swap(*this);
	}
	cout << "Move assignment operator" << endl;

	return *this;
}
template <typename T>
void Array<T>::Swap(Array<T>& ar)
{
	swap(m_capacity, ar.m_capacity);
	swap(m_length, ar.m_length);
	swap(m_arr, ar.m_arr);
}