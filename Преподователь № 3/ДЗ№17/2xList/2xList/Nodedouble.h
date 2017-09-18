#pragma once
template <typename U>
class List;
template <typename T>
class Node//Класс может содержать ссылки и указатели.
{
private:
	friend class List < T >;
	T m_value;
	Node* m_next;//Указатель на объект такого же класса
	Node* m_prev;
public:
	Node(T value) : m_value(value){};
	T GetValue();
	Node*GetNext();
	Node*GetPrev();
	void SetPrev(Node * prev);
	void SetNext(Node * next);
	//Для value Getmethod.
	//Для m_node Setmethod, Getmethod
};
template <typename T>
T Node<T>::GetValue()
{
	return m_value;
}
template <typename T>
Node<T>* Node<T>::GetNext()
{
	return m_next;
}
template <typename T>
Node<T> * Node<T>::GetPrev()
{
	return m_prev;
}
template <typename T>
void Node<T>::SetPrev(Node<T> * prev)
{
	m_prev = prev;
}
template <typename T>
void Node<T>::SetNext(Node<T>* next)
{
	m_next = next;
}