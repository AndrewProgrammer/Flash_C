#pragma once

#include <iostream>

template <typename T1, typename T2>
class Foo
{
private:
    T1 m_field1;
    T2 m_field2;

public:
    static unsigned int s_count;

    Foo(T1 param1, T2 param2);

    void Show();
};

template<typename T1, typename T2>
Foo<T1, T2>::Foo(T1 param1, T2 param2)
{
    m_field1 = param1;
    m_field2 = param2;

    ++s_count;
}

template<typename T1, typename T2>
void Foo<T1, T2>::Show()
{
    std::cout << m_field1 << std::endl;
    std::cout << m_field2 << std::endl;
    std::cout << std::endl;
}