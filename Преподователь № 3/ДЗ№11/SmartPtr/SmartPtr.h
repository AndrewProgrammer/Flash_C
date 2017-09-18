#pragma once
template<typename T>
class SmartPtr
{
private:
	T * m_ptr = nullptr;
	T* m_counter = nullptr;
public:
	SmartPtr(T*ptr);
	~SmartPtr();
	void Clean();
	SmartPtr<T> & operator = (const SmartPtr<T>& right);
	SmartPtr(const SmartPtr<T> & p);
	T& operator*();
	T ** operator &();
	T * operator ->();
	T* GetCounter()const;
};
template<typename T>
SmartPtr<T>::SmartPtr(T * ptr = nullptr) : m_ptr(ptr)
{
	m_counter = new T(1);
}
template<typename T>
SmartPtr<T>& SmartPtr<T>::  operator = (const SmartPtr<T> & right)
{
	if (m_ptr != nullptr)
	{
		Clean();
	}
	m_ptr = right.m_ptr;
	m_counter = right.m_counter;
	(*m_counter)++;
	return  *this;
}
template<typename T>
SmartPtr<T>::SmartPtr<T>(const SmartPtr<T> & p)
{
	m_ptr = p.m_ptr;
	m_counter = p.m_counter;
	(*m_counter)++;
}
template<typename T>
SmartPtr<T>:: ~SmartPtr()
{
	Clean();
}
template<typename T>
void SmartPtr<T>::Clean()
{
	(*m_counter)--;
	if (*m_counter == 0)
	{
		delete m_ptr;
	}
}
template<typename T>
T& SmartPtr<T>:: operator *()
{
	return *m_ptr;
}
template<typename T>
T** SmartPtr<T>:: operator &()
{
	return &m_ptr;
}
template<typename T>
T*SmartPtr<T>:: operator ->()
{
	return m_ptr;
}
template<typename T>
T*SmartPtr<T>::GetCounter()const
{
	return m_counter;
}