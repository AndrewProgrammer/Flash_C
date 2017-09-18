#pragma once

// Класс студент.
class Student
{
private:
    // Возраст.
    unsigned int age;

    // Имя.
    char name[50];

    // Фамилия.
    char surname[50];

public:
    Student(const char name[], const char surname[], const unsigned int age);

    void Show();
};