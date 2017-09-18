#define _CRT_SECURE_NO_WARNINGS
#include "Array.h"
#include <iostream>
#include <ostream>
#include <cstring>
#include <ctime>
using namespace std;

Array::Array(int ar[])
{
	m_arr = new int [m_length + 1u];
	for (int i = 0; i < m_length; i++)
	{
		m_arr[i] = ar[i];
	}
	cout << "Parametrized constructor" << endl;
}

Array::Array(const Array& ar)
{
	m_capacity = ar.m_capacity;
	m_length = ar.m_length;

	m_arr = new int[m_capacity];
	for (int i = 0; i < m_length; i++)
	{
		m_arr[i] = ar.m_arr[i];
	}
	cout << "Copy constructor" << endl;
}

Array::Array(Array&& ar)
{
	// Move!!!
	m_capacity = ar.m_capacity;
	m_length = ar.m_length;
	m_arr = ar.m_arr;

	ar.m_capacity = 0u;
	ar.m_length = 0u;
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
	swap(m_capacity, ar.m_capacity);
	swap(m_length, ar.m_length);
	swap(m_arr, ar.m_arr);
}
const int*Array::GetArray() const
{
	return m_arr;
}
uint Array::GetArLength() const
{
	return m_length;
}
Array::Array()
{
	m_capacity = m_length;
	m_arr = new int[m_length];
	for (int i = 0; i < m_length; i++)
		m_arr[i] = rand() % 10;
}
void Array::PrintArr()
{
	for (int i = 0; i < m_capacity; ++i)
		cout << m_arr[i] << ' ';
}

void Array::Add(int value)
{
	m_capacity = m_length + 1;
	int *temp = new int[m_capacity];
	for (int i = 0; i < m_length; i++)
		temp[i] = m_arr[i];
	temp[m_capacity - 1] = value;
	delete[]m_arr;
	m_arr = temp;
}

void Array::Remove(int valua)
{
	int count = 0;
	for (int i = 0; i < m_length; i++)
	{
		if (m_arr[i] != valua)
			++count;
	}
	m_capacity = count;
	int *temp = new int[m_capacity];
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

void Array::RemoveAt(int index)
{
	m_capacity = m_length - 1;
	int *temp = new int[m_capacity];
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

bool Array::Contains(int valua)
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

int & Array:: operator[] (int index)
{
	if (index > m_length&&index<0)
		cout << "Error";
	else return m_arr[index];
}

bool Array:: operator == (int index)
{
	return m_arr[m_length] == m_arr[m_index] ? true : false;
}
bool Array:: operator != (int index)
{
	return m_arr[m_length] == m_arr[m_index] ? true : false;
}