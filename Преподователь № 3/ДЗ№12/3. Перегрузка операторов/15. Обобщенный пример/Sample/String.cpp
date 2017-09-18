#include "String.h"

using namespace std;

String::String() : m_length(0U), m_string(new char[50])
{
    m_string[0] = '\0';
}

String::String(const char* const string) : m_length(0U), m_string(nullptr)
{
    m_length = strlen(string);

    unsigned int capacity = m_length + 1U;

    m_string = new char[capacity];

    strcpy_s(m_string, capacity, string);
}

String::String(const String& source) :m_length(0U), m_string(nullptr)
{
    m_length = source.m_length;

    unsigned int capacity = m_length + 1U;

    m_string = new char[capacity];

    strcpy_s(m_string, capacity, source.m_string);
}

String::~String()
{
    delete[] m_string;
}

String::operator char*() const
{
    return m_string;
}

String& String::operator=(const String& right)
{
    if (this != &right)
    {
        delete[] m_string;

        unsigned int capacity = right.m_length + 1U;

        m_length = right.m_length;
        m_string = new char[capacity];

        strcpy_s(m_string, capacity, right.m_string);
    }

    return *this;
}

unsigned int String::GetLength() const
{
    return m_length;
}


String operator+(const String& string1, const String& string2)
{
    String string;

    delete[] string.m_string;

    string.m_length = string1.m_length + string2.m_length;

    unsigned int capacity = string.m_length + 1U;

    string.m_string = new char[capacity];

    strcpy_s(string.m_string, capacity, string1.m_string);
    strcat_s(string.m_string, capacity, string2.m_string);

    return string;
}

istream& operator>>(istream& left, String& right)
{
    char buffer[255] = {};

    left.getline(buffer, 255U);

    delete[] right.m_string;

    right.m_length = strlen(buffer);

    unsigned int capacity = right.m_length + 1U;

    right.m_string = new char[capacity];

    strcpy_s(right.m_string, capacity, buffer);

    return left;
}

ostream& operator<<(ostream& left, const String& right)
{
    left << right.m_string;

    return left;
}