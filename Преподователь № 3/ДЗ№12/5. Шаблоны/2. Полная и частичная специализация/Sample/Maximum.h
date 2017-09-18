#pragma once

#include <iostream>

template <typename TItem1, typename TItem2>
class Maximum
{
private:
    TItem1 m_value1;
    TItem2 m_value2;

public:
    Maximum(TItem1 value1, TItem2 value2);

    TItem1 MaxValue();
};

template <typename TItem1, typename TItem2>
Maximum<TItem1, TItem2>::Maximum(TItem1 value1, TItem2 value2) :m_value1(value1), m_value2(value2)
{
    std::cout << "<TItem1, TItem2>" << std::endl;
}

template <typename TItem1, typename TItem2>
TItem1 Maximum<TItem1, TItem2>::MaxValue()
{
    return m_value1 > m_value2 ? m_value1 : m_value2;
}


template <>
class Maximum<char*, char*>
{
private:
    char* m_value1;
    char* m_value2;

public:
    Maximum(char* value1, char* value2);

    char* MaxValue();
};

Maximum<char*, char*>::Maximum(char* value1, char* value2) : m_value1(value1), m_value2(value2)
{
    std::cout << "<char*, char*>" << std::endl;
}

char* Maximum<char*, char*>::MaxValue()
{
    return strcmp(m_value1, m_value2) > 0 ? m_value1 : m_value2;
}


template <typename TItem>
class Maximum<TItem, char>
{
private:
    TItem m_value1;
    char m_value2;

public:
    Maximum(TItem value1, char value2) : m_value1(value1), m_value2(value2)
    {
        std::cout << "<TItem, char>" << std::endl;
    }

    TItem MaxValue();
};

template <typename TItem>
TItem Maximum<TItem, char>::MaxValue()
{
    return m_value1 > m_value2 ? m_value1 : m_value2;
}


template <typename TItem>
class Maximum<double, TItem>
{
private:
    double m_value1;
    TItem m_value2;

public:
    Maximum(double value1, TItem value2);

    TItem MaxValue();
};

template <typename TItem>
Maximum<double, TItem>::Maximum(double value1, TItem value2) : m_value1(value1), m_value2(value2)
{
    std::cout << "<double, TItem>" << std::endl;
}

template <typename TItem>
TItem Maximum<double, TItem>::MaxValue()
{
    return m_value1 > m_value2 ? m_value1 : m_value2;
}