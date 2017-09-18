#pragma once

class Date
{
    // Доступ к этим полям будут иметь только методы класса.
private:
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;

    // Открытые методы класса (интерфейсная часть класса).
public:
    void Initialize(const unsigned int year, const unsigned int month, const unsigned int day);
    void Show();

    // Аксессоры.

    // Инспектор для поля m_day.
    unsigned int GetDay();

    // Инспектор для поля m_year.
    unsigned int GetYear();

    // Модификатор для поля m_month.
    void SetMonth(const unsigned int month);

    // Модификатор для поля m_year.
    void SetYear(const unsigned int year);
};