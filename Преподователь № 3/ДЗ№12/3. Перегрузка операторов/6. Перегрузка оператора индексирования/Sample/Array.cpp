#include "Array.h"

Array::Array(const unsigned int size)
{
    m_array = new int[size];
    m_size = size;

    for (unsigned int i = 0; i < m_size; ++i)
    {
        m_array[i] = i;
    }
}

Array::~Array()
{
    delete[] m_array;
}

int& Array::operator[](const unsigned int index)
{
    return m_array[index];
}