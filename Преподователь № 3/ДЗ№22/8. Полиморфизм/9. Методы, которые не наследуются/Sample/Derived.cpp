#include "Derived.h"

#include <iostream>

using namespace std;

Derived::Derived() : m_bufferB(nullptr)
{
    cout << "Default constructor Derived" << endl;
}

Derived::Derived(const Derived& obj) : Base(obj), m_bufferB(nullptr)
{
    cout << "Copy constructor Derived" << endl;

    Assign(obj.m_bufferB);
}

Derived::Derived(const char* const stringA, const char* const stringB) : Base(stringA), m_bufferB(nullptr)
{
    cout << "Constructor Derived" << endl;

    Assign(stringB);
}

Derived::~Derived()
{
    cout << "Destructor Derived" << endl;

    delete[] m_bufferB;
}

Derived& Derived::operator=(const Derived& right)
{
    cout << "operator= Base" << endl;

    if (this != &right)
    {
        Base::operator=(right);

        Assign(right.m_bufferB);
    }

    return *this;
}

void Derived::Assign(const char* const string)
{
    delete[] m_bufferB;

    unsigned int capacity = strlen(string) + 1;

    m_bufferB = new char[capacity];

    strcpy_s(m_bufferB, capacity, string);
}

void Derived::Show() const
{
    Base::Show();
    cout << m_bufferB << endl;
}