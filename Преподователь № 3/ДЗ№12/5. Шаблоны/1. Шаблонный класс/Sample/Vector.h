#pragma once

#include <iostream>

template <typename TItem>
class Vector
{
private:
    TItem* m_array;
    unsigned int m_size;

public:
    Vector();
    Vector(unsigned int size);
    Vector(const Vector<TItem>& vector);

    ~Vector();

    Vector<TItem>& operator=(const Vector<TItem>& right);

    void Fill();
    void Show();
};

template <typename TItem>
Vector<TItem>::Vector()
{
    m_array = nullptr;
    m_size = 0U;
}

template <typename TItem>
Vector<TItem>::Vector(unsigned int size)
{
    m_array = new TItem[size];

    memset(m_array, 0, sizeof(TItem) * size);

    m_size = size;
}

template <typename TItem>
Vector<TItem>::Vector(const Vector<TItem>& vector)
{
    m_array = new TItem[vector.m_size];
    m_size = vector.m_size;

    for (unsigned int i = 0U; i < m_size; ++i)
    {
        m_array[i] = vector.m_array[i];
    }
}

template <typename TItem>
Vector<TItem>::~Vector()
{
    delete[] m_array;
}

template <typename TItem>
Vector<TItem>& Vector<TItem>::operator=(const Vector<TItem>& right)
{
    if (this != &right)
    {
        delete[] m_array;

        m_size = right.m_size;

        if (m_size > 0U)
        {
            m_array = new TItem[m_size];

            for (unsigned int i = 0U; i < m_size; ++i)
            {
                m_array[i] = right.m_array[i];
            }
        }
        else
        {
            m_array = nullptr;
        }
    }

    return *this;
}

template <typename TItem>
void Vector<TItem>::Fill()
{
    for (unsigned int i = 0U; i < m_size; ++i)
    {
        std::cin >> m_array[i];
    }
}

template <typename TItem>
void Vector<TItem>::Show()
{
    std::cout << endl;

    for (unsigned int i = 0U; i < m_size; ++i)
    {
        std::cout << m_array[i] << std::endl;
    }
}