#include "Human_Ex.h"
#include <cstring>
#include <iostream>
using namespace std;
Human_Ex::Human_Ex()
{
	Age = 0;
	const char unknown[] = "Unknown"; // по умолчанию строковый массив
	const unsigned int sizestr = strlen(unknown) + 1    ; // размер этого массива
	Name = new char[sizestr]; // задаем размер динамического массива имени
	strcpy_s(Name, sizestr, unknown);// копируем массив по умолчанию в наш именной динамический массив
	Surname = new char[sizestr];// задаем размер динамического массива фамилии
	strcpy_s(Surname, sizestr, unknown);// копируем массив по умолчанию в наш динамический массив с фамилией
}

Human_Ex::Human_Ex(const char *name, const char *surname, unsigned int age)
{
	if (age >= 0)
		Age = age;
	else cout << "Error!\n";
	const unsigned int size_of_Name = strlen(name) + 1;//объявляем размер для Name
	const unsigned int size_of_Surname = strlen(surname) + 1;// объявляем размер для Surname
	Name = new char[size_of_Name];//выделяем динамическую память для Name по размеру size_of_Name
	strcpy_s(Name, size_of_Name, name);//копируем размер из name в наш Name
	Surname = new char[size_of_Surname];//выделяем динамическую память для Surname по размеру size_of_Surname
	strcpy_s(Surname, size_of_Surname, surname);//копируем размер из surname в наш Surname
}

void Human_Ex::SetName(const char *adding_name)
{
	const unsigned int size_of_addingName = strlen(adding_name) + 1;
	delete[] Name;
	Name = new char[size_of_addingName];
	strcpy_s(Name,size_of_addingName,adding_name);
}

void Human_Ex::SetSurname(const char *adding_surname)
{
	const unsigned int size_of_addingSurname = strlen(adding_surname) + 1;
	delete[] Surname;
	Surname= new char[size_of_addingSurname];
	strcpy_s(Name,size_of_addingSurname,adding_surname);
}

Human_Ex::~Human_Ex()
{
	delete[]Name; 
	delete[]Surname; 
}

void Human_Ex::Show()
{
	cout << "Your Name is: " << Name << endl;
	cout << "Your Surname is: " << Surname << endl;
	cout << "Your Age is: " << Age << endl;
	cout << "Your Adding name is:" << Name << endl;
	cout << "Your Adding surname is: " << Surname << endl;
}