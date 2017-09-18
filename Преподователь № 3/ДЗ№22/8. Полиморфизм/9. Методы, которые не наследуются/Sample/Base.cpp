#include "Base.h"

#include <iostream>

using namespace std;

Base::Base() : m_bufferA(nullptr)
{
    cout << "Default constructor Base" << endl;
}

Base::Base(const Base& obj) : m_bufferA(nullptr)
{
    cout << "Copy constructor Base" << endl;

    Assign(obj.m_bufferA);
}

Base::Base(const char* const string) : m_bufferA(nullptr)
{
    cout << "Constructor Base" << endl;

    Assign(string);
}

Base::~Base()
{
    cout << "Destructor Base" << endl;

    delete[] m_bufferA;
}

Base& Base::operator=(const Base& right)
{
    cout << "operator= Base" << endl;

    if (this != &right)
    {
        Assign(right.m_bufferA);
    }

    return *this;
}

void Base::Assign(const char* const string)
{
    delete[] m_bufferA;

    unsigned int capacity = strlen(string) + 1;

    m_bufferA = new char[capacity];

    strcpy_s(m_bufferA, capacity, string);
}

void Base::Show() const
{
    cout << m_bufferA << endl;
}