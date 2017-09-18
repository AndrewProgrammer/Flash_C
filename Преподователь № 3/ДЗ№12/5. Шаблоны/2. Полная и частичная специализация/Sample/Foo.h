#pragma once

#include <iostream>

template <typename TItem>
class Foo
{
private:
    TItem* m_value;

public:
    Foo(const TItem& value);
    Foo(const Foo& obj);

    ~Foo();

    void Show();
};

template <typename TItem>
Foo<TItem>::Foo(const TItem& value)
{
    std::cout << "<TItem>" << std::endl;

    m_value = new TItem(value);
}

template <typename TItem>
Foo<TItem>::Foo(const Foo<TItem>& obj)
{
    m_value = new TItem(*obj.m_value);
}

template <typename TItem>
Foo<TItem>::~Foo()
{
    delete[] m_value;
}

template <typename TItem>
void Foo<TItem>::Show()
{
    std::cout << *m_value << std::endl << std::endl;
}


template <>
class Foo<char>
{
private:
    char* m_value;

public:
    Foo(const char& value);
    Foo(const Foo& obj);

    ~Foo();

    void Show();
};

Foo<char>::Foo(const char& value)
{
    std::cout << "<char>" << std::endl;

    m_value = new char(value);
}

Foo<char>::Foo(const Foo<char>& obj)
{
    m_value = new char(*obj.m_value);
}

Foo<char>::~Foo()
{
    delete[] m_value;
}

void Foo<char>::Show()
{
    std::cout << *m_value << std::endl << std::endl;
}