#pragma once

class Date
{
private:
    // Поля класса.
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;

public:
    Date(const unsigned int year = 2008U, const unsigned int month = 12U, const unsigned int day = 31U);

    void Show();
};