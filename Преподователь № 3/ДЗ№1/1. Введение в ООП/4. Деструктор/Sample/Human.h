#pragma once

class Human
{
private:
    unsigned int m_age;
    char* m_name;
    char* m_surname;

public:
    Human();
    Human(const char* const name, const char* const surname, const unsigned int age);

    ~Human();

    void Show();
};