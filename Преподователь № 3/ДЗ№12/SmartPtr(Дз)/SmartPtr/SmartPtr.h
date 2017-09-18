#pragma once
#include "Delete.h"
#include <type_traits>
//template<typename T>
template<typename TArr, typename Tdel = Delete<TArr>>
class SmartPtr
{
private:
	/*T * m_ptr = nullptr;
	T* m_counter = nullptr;*/
	Tdel m_del;
	std::remove_all_extents_t<TArr>* m_ptr = nullptr;
public:
	/*SmartPtr(T*ptr);*/
	~SmartPtr()
	{
		m_del(m_ptr);
	}
	//~SmartPtr();
	//void Clean();
	//SmartPtr<T> & operator = (const SmartPtr<T>& right);
	//SmartPtr(const SmartPtr<T> & p);
	//T& operator*();
	//T ** operator &();
	//T * operator ->();
	//T* GetCounter()const;

	SmartPtr() = default;
	SmartPtr(std::remove_all_extents_t<TArr>* const p) : m_ptr(p){};
	std::remove_all_extents_t<TArr>* operator->() const
	{
		return m_ptr;
	}

	TArr& operator*() const
	{
		return *m_ptr;
	}

};
//template<typename T>
//SmartPtr<T>::SmartPtr(T * ptr = nullptr) : m_ptr(ptr)
//{
//	m_counter = new T(1);
//}
//template<typename T>
//SmartPtr<T>& SmartPtr<T>::  operator = (const SmartPtr<T> & right)
//{
//	if (m_ptr != nullptr)
//	{
//		Clean();
//	}
//	m_ptr = right.m_ptr;
//	m_counter = right.m_counter;
//	(*m_counter)++;
//	return  *this;
//}
//template<typename T>
//SmartPtr<T>::SmartPtr<T>(const SmartPtr<T> & p)
//{
//	m_ptr = p.m_ptr;
//	m_counter = p.m_counter;
//	(*m_counter)++;
//}
//template<typename T>
//SmartPtr<T>:: ~SmartPtr()
//{
//	Clean();
//}
//template<typename T>
//void SmartPtr<T>::Clean()
//{
//	(*m_counter)--;
//	if (*m_counter == 0)
//	{
//		delete m_ptr;
//	}
//}
//template<typename T>
//T& SmartPtr<T>:: operator *()
//{
//	return *m_ptr;
//}
//template<typename T>
//T** SmartPtr<T>:: operator &()
//{
//	return &m_ptr;
//}
//template<typename T>
//T*SmartPtr<T>:: operator ->()
//{
//	return m_ptr;
//}
//template<typename T>
//T*SmartPtr<T>::GetCounter()const
//{
//	return m_counter;
//}