#pragma once
template <typename U>
class List;
template <typename T>
class Node//Класс может содержать ссылки и указатели.
{
private:
	friend class List < T > ;
	T m_value;
	Node* m_next;//Указатель на объект такого же класса
public:
	Node(T value) : m_value(value){};
	T& GetValue();
	Node*GetNext();
	void SetNext(Node * next);
	const T& GetValue() const;
	//Для value Getmethod.
	//Для m_node Setmethod, Getmethod
};
template <typename T>
T& Node<T>::GetValue()
{
	return m_value;
}
template <typename T>
const T& Node<T>::GetValue() const
{
	return m_value;
}
template <typename T>
Node<T>* Node<T>::GetNext()
{
	return m_next;
}
template <typename T>
void Node<T>::SetNext(Node<T>* next)
{
	m_next = next;
}

