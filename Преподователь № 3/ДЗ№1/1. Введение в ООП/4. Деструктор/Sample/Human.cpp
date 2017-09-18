#include "Human.h"

#include <cstring>
#include <iostream>

using namespace std;

Human::Human()
{
    const char unknown[] = "Unknown";
    const unsigned int capacity = strlen(unknown) + 1U;

    m_age = 0U;

    m_name = new char[capacity];
    strcpy_s(m_name, capacity, unknown);

    m_surname = new char[capacity];
    strcpy_s(m_surname, capacity, unknown);
}

Human::Human(const char* const name, const char* const surname, const unsigned int age)
{
    m_age = age;

    const unsigned int capacityName = strlen(name) + 1U;
    const unsigned int capacitySurname = strlen(surname) + 1U;

    m_name = new char[capacityName];
    strcpy_s(m_name, capacityName, name);

    m_surname = new char[capacitySurname];
    strcpy_s(m_surname, capacitySurname, surname);
}

Human::~Human()
{
    cout << "~Destructor()" << endl;

    delete[] m_name;
    delete[] m_surname;
}

void Human::Show()
{
    cout << "Name: " << m_name << endl;
    cout << "Surname:" << m_surname << endl;
    cout << "Age: " << m_age << endl << endl;
}