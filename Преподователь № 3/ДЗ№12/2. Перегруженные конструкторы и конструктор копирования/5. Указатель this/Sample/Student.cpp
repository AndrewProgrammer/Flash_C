#include "Student.h"

#include <iostream>

using namespace std;

Student::Student(const char name[], const char surname[], const unsigned int age)
{
    // Компоненты и одноименные параметры.
    this->age = age;

    strcpy_s(this->name, name);
    strcpy_s(this->surname, surname);
}

void Student::Show()
{
    // Здесь this является необязательным, однако использовать его можно.
    cout << "Name: " << this->name << endl;
    cout << "Surname: " << this->surname << endl;
    cout << "Age: " << this->age << endl;
}