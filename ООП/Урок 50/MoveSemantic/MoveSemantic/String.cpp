#include "String.h"

#include <cstring>
#include <iostream>

using namespace std;

String::String(const char* const string)
{
    m_length = strlen(string);
    m_capacity = m_length + 1u;

    m_string = new char[m_capacity];

    strcpy_s(m_string, m_capacity, string);
    cout << "Parametrized constructor" << endl;
}

String::String(const String& string)
{
    m_capacity = string.m_capacity;
    m_length = string.m_length;

    m_string = new char[m_capacity];

    strcpy_s(m_string, m_capacity, string.m_string);
    cout << "Copy constructor" << endl;
}

String::String(String&& string)
{
    // Move!!!
    m_capacity = string.m_capacity;
    m_length = string.m_length;
    m_string = string.m_string;

    string.m_capacity = 0u;
    string.m_length = 0u;
    string.m_string = nullptr; //!!!!!!
    cout << "Move constructor" << endl;
}

String::~String()
{
    delete[] m_string;
    cout << "Destructor" << endl;
}

String& String::operator=(const String& right)
{
    if (this != &right)
    {
        String(right).Swap(*this);
    }
    cout << "Assignment operator" << endl;

    return *this;
}

String& String::operator=(String&& right)
{
    if (this != &right)
    {
        String(move(right)).Swap(*this);
    }
    cout << "Move assignment operator" << endl;

    return *this;
}

void String::Swap(String& string)
{
    swap(m_capacity, string.m_capacity);
    swap(m_length, string.m_length);
    swap(m_string, string.m_string);
}