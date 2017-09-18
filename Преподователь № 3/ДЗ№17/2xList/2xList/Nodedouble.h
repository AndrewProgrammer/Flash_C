#pragma once
template <typename U>
class List;
template <typename T>
class Node//����� ����� ��������� ������ � ���������.
{
private:
	friend class List < T >;
	T m_value;
	Node* m_next;//��������� �� ������ ������ �� ������
	Node* m_prev;
public:
	Node(T value) : m_value(value){};
	T GetValue();
	Node*GetNext();
	Node*GetPrev();
	void SetPrev(Node * prev);
	void SetNext(Node * next);
	//��� value Getmethod.
	//��� m_node Setmethod, Getmethod
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