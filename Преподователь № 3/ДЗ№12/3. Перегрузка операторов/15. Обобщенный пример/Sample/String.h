#pragma once

#include <iostream>

// Объявление строкового класса.
class String
{
private:
    // Длина строки.
    unsigned int m_length;

    // Строка.
    char* m_string;

public:
    // Конструктор по умолчанию.
    String();

    // Перегруженный конструктор.
    String(const char* const string);

    // Конструктор копирования.
    String(const String& source);

    // Деструктор.
    ~String();

    // Оператор преобразование объекта класса к типу char*.
    operator char*() const;

    // Оператор присваивания.
    String& operator=(const String& right);

    // Дружественные функции.

    // Функция конкатенации строк.
    friend String operator+(const String& left, const String& right);

    // Функция реализует ввод объектов класса с клавиатуры.
    friend std::istream& operator>>(std::istream& left, String& right);

    // Функция реализует вывод объектов класса на экран.
    friend std::ostream& operator<<(std::ostream& left, const String& right);

    // Метод возвращает длину строки.
    unsigned int GetLength() const;
};