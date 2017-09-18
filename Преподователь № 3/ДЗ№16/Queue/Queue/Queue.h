#pragma once
template <typename T>
class Queue
{
private:
	T *m_queue;
	int index;
	int top;
	int min;
public:
	Queue(T size);
	~Queue();
	Queue(const Queue<T>& other);

	void Push(T value);
	T Pop();
	T Peek();
	void PrintQueue();

	int GetQueueTop() const;
	int GetIndex() const;
	T *GetOthQueuePtr() const;
};
template <typename T>
Queue<T>::Queue(T size)
{
	top = size;
	index = 0;
	min = 0;
	m_queue = new T[size];
}
template <typename T>
int Queue<T> ::GetQueueTop() const
{
	return top;
}
template <typename T>
int Queue<T> ::GetIndex() const
{
	return index;
}
template <typename T>
T* Queue<T> ::GetOthQueuePtr() const
{
	return m_queue;
}
template <typename T>
Queue<T> ::Queue(const Queue<T>& other) : top(other.GetQueueTop())
{
	m_queue = new T[top];
	index = other.GetIndex();
	for (int i = 0; i < index; i++)
	{
		m_queue[i] = other.GetOthQueuePtr()[i];
	}
}
template <typename T>
Queue<T>::~Queue()	
{
	delete[] m_queue;
}
template <typename T>
T Queue<T>::Peek()
{
	return m_queue[--index];
}
template <typename T>
void Queue<T>::Push(T value)
{
	if (index < top)
	{
		m_queue[index++] = value;
		//index++;Для последовательности
	}
}
template <typename T>
T Queue<T>::Pop()
{
	if (index > 0)
	{
		return m_queue[index--];
	}
}
template <typename T>
void Queue<T>::PrintQueue()
{
	for (int i = index - 1; i >= 0; i--)
		cout << m_queue[i] << endl;
}
