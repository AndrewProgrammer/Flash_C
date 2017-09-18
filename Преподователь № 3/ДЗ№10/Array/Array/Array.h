#pragma once
#include <iostream>
#include <ostream>
typedef unsigned int uint;
class Array
{
private:
	uint m_lenght = 5;
	int *m_arr = 0;
	int valua = 0;
	uint capacity = 0;
	int index = 0;

public:
	Array();
	~Array();
	void Add(int valua);
	void PrintArr();
	void Remove(int valua);
	void RemoveAt(int index);
	bool Contains(int valua);

	int& operator[] (int index);
	bool operator== (int index);
	bool operator!= (int index);
	Array& operator =(const Array& right);

	const int* GetArray() const;
	uint GetArLength() const;

	Array(int ar[]);
	Array(Array&& ar);
	Array(const Array& ar);
	Array& operator=(Array&& right);
	void Swap(Array& ar);
};

//void operator <<(std::ostream& os, const Array& right)
//{
//	for (int i = 0; i < right.GetArLength(); i++)
//	{
//		return os << right.GetArray[i] << " ";
//	}
//}