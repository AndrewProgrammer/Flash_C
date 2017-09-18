#pragma once

class Date
{
private:
    // Поля класса.
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;

public:
    // Конструктор класса по умолчанию.
    Date();

    // Конструктор класса с одним параметром.
    Date(const unsigned int year);

    // Конструктор класса с двумя параметрами.
    Date(const unsigned int year, const unsigned int month);

    // Конструктор класса с тремя параметрами.
    Date(const unsigned int year, const unsigned int month, const unsigned int day);

    void Show();
};