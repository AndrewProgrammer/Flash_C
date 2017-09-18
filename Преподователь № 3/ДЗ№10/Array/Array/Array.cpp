#define _CRT_SECURE_NO_WARNINGS
#include "Array.h"
#include <iostream>
#include <ostream>
#include <cstring>
#include <ctime>
using namespace std;

Array::Array(int ar[])
{
	m_arr = new int [m_lenght + 1u];
	for (int i = 0; i < m_lenght; i++)
	{
		m_arr[i] = ar[i];
	}
	cout << "Parametrized constructor" << endl;
}

Array::Array(const Array& ar)
{
	capacity = ar.capacity;
	m_lenght = ar.m_lenght;

	m_arr = new int[capacity];
	for (int i = 0; i < m_lenght; i++)
	{
		m_arr[i] = ar.m_arr[i];
	}
	cout << "Copy constructor" << endl;
}

Array::Array(Array&& ar)
{
	// Move!!!
	capacity = ar.capacity;
	m_lenght = ar.m_lenght;
	m_arr = ar.m_arr;

	ar.capacity = 0u;
	ar.m_lenght = 0u;
	ar.m_arr = nullptr; //!!!!!!
	cout << "Move constructor" << endl;
}

Array::~Array()
{
	delete[] m_arr;
	cout << "Destructor" << endl;
}

Array& Array::operator=(const Array& right)
{
	if (this != &right)
	{
		Array(right).Swap(*this);
	}
	cout << "Assignment operator" << endl;

	return *this;
}

Array& Array::operator=(Array&& right)
{
	if (this != &right)
	{
		Array(move(right)).Swap(*this);
	}
	cout << "Move assignment operator" << endl;

	return *this;
}

void Array::Swap(Array& ar)
{
	swap(capacity, ar.capacity);
	swap(m_lenght, ar.m_lenght);
	swap(m_arr, ar.m_arr);
}
const int*Array::GetArray() const
{
	return m_arr;
}
uint Array::GetArLength() const
{
	return m_lenght;
}
Array::Array()
{
	capacity = m_lenght;
	m_arr = new int[m_lenght];
	for (int i = 0; i < m_lenght; i++)
		m_arr[i] = rand() % 10;
}
void Array::PrintArr()
{
	for (int i = 0; i < capacity; ++i)
		cout << m_arr[i] << ' ';
}

void Array::Add(int value)
{
	capacity = m_lenght + 1;
	int *temp = new int[capacity];
	for (int i = 0; i < m_lenght; ++i)
		temp[i] = m_arr[i];
	temp[capacity - 1] = value;
	delete[]m_arr;
	m_arr = temp;
}

void Array::Remove(int valua)
{
	int count = 0;
	for (int i = 0; i < m_lenght; i++)
	{
		if (m_arr[i] != valua)
			++count;
	}
	capacity = count;
	int *temp = new int[capacity];
	int j = 0;
	for (int i = 0; i < m_lenght; ++i)
	{
		if (m_arr[i] != valua)
		{
			temp[j] = m_arr[i];
			++j;
		}
	}
	m_arr = temp;
}

void Array::RemoveAt(int index)
{
	capacity = m_lenght - 1;
	int *temp = new int[capacity];
	for (int i = 0; i < m_lenght; ++i)
	{
		if (i < index)
			temp[i] = m_arr[i];
		if (i > index)
			temp[i - 1] = m_arr[i];
	}
	m_arr = temp;

}

bool Array::Contains(int valua)
{
	for (int i = 0; i < m_lenght; ++i)
	{
		if (m_arr[i] == valua)
		{
			return true;
			break;
		}
	}
	return false;
}

int & Array:: operator[] (int index)
{
	if (index > m_lenght&&index<0)
		cout << "Error";
	else return m_arr[index];
}

bool Array:: operator == (int index)
{
	return m_arr[3] == m_arr[2] ? true : false;
}
bool Array:: operator != (int index)
{
	return m_arr[3] != m_arr[2] ? true : false;
}