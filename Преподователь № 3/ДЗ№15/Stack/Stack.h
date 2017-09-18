#pragma once
#include <iostream>
template < typename T>
class Stack_EX
{
private:
	const int size;
	T *m_stack;
	int index;
public:
	Stack_EX(int size = 10);
	Stack_EX(const Stack_EX<T>& other);
	Stack_EX<T>& operator=(const Stack_EX<T>& right);
	void Swap(Stack_EX<T>& other);
	void Push(T value);//��������� �������� ������ � �����.
	T Pop();//��������� ������� �� �����,� ������� �������� ��� ����, � ������� ���������� ��������.
	T Peek();//���������� ����� ������� ���������� �� �������.
	//T Peek(int num);//��� ����
	bool IsEmpty();//�������� �� ����.
	void PrintStack();
	int GetStackSize() const;
	int GetIndex() const;
	T *GetOthStackPtr() const;
	~Stack_EX();
};
template <typename T>
Stack_EX<T>::Stack_EX(int MaxSize) :size(MaxSize)
{
	m_stack = new T[size];
	index = 0;
}
template <typename T>
Stack_EX<T> ::Stack_EX(const Stack_EX<T>& other) : size(other.GetStackSize())
{
	m_stack = new T[size];
	index = other.GetIndex();
	for (int i = 0; i < index; i++)
	{
		m_stack[i] = other.GetOthStackPtr()[i];
	}
}
template < typename T>
Stack_EX<T> ::~Stack_EX()
{
	delete[] m_stack;
}
template <typename T>
int Stack_EX<T> ::GetStackSize() const
{
	return size;
}
template <typename T>
int Stack_EX<T> ::GetIndex() const
{
	return index;
}
template <typename T>
T* Stack_EX<T> ::GetOthStackPtr() const
{
	return m_stack;
}
template < typename T>
void Stack_EX<T> ::Push(T value)//��������� �������� ������ � �����.
{
	if (index < size)
	{
		m_stack[index++] = value;
	}
}
template < typename T>
T Stack_EX<T> ::Pop()//��������� ������� �� �����,� ������� �������� ��� ����, � ������� ���������� ��������.
{
	if (index > 0)
	{
		return m_stack[--index];
	}
	else if (index == 0)
	{
		cout << "Error!\n";
	}
}
//template <typename T>
//T Stack_EX<T> ::Peek(int num) 
//{
//	if (num <= index)
//	{
//		return m_stack[index - num];
//	}
//}
template <typename T>
T Stack_EX<T> ::Peek()//����� ������� ���������� �� �������
{
	return m_stack[--index];
}
template < typename T>
bool Stack_EX<T> ::IsEmpty()//�������� �� ����.
{
	if (index < 0)
	{
		return false;
	}
	return true;
}
template < typename T>
Stack_EX<T>& Stack_EX<T> :: operator =(const Stack_EX<T>& right)
{
	if (this != &right)
	{
		Stack_EX<T>(right).Swap(*this);
	}
	cout << "Assignment operator" << endl;

	return *this;
}
template < typename T>
void Stack_EX<T>::Swap(Stack_EX<T>& other)
{
	swap(size, other.size);
	swap(m_stack, other.m_stack);
	swap(index, other.index);
}
template <typename T>
void Stack_EX<T>::PrintStack()
{
	for (int i = index - 1; i >= 0; i--)
		cout << m_stack[i] << endl;
}
