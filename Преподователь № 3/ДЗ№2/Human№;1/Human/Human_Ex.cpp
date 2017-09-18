#include "Human_Ex.h"
#include <cstring>
Human_Ex::Human_Ex()
{
	Name = "-";
	Surname = "-";
	Age = 0;
}
Human_Ex::Human_Ex(const char *name, const char *surname, unsigned int age)
{
	Age = age;
	const unsigned int size_of_Name = strlen(name) + 1;//объявляем размер для Name
	const unsigned int size_of_Surname = strlen(surname) + 1;// объявляем размер для Surname
	Name = new char[size_of_Name];//выделяем динамическую память для Name по размеру size_of_Name
	strcpy_s(Name, size_of_Name, name);//копируем размер из name в наш Name
	Surname = new char[size_of_Surname];//выделяем динамическую память для Surname по размеру size_of_Surname
	strcpy_s(Surname, size_of_Surname, surname);//копируем размер из surname в наш Surname
}
Human_Ex::~Human_Ex()
{
	//delete[]Name; не могу освободить динамическую память
	//delete[]Surname; не могу освободить динамическую память
}
unsigned int Human_Ex::GetAge()
{
	return Age;
}
char* Human_Ex::GetName()
{
	return Name;
}
char* Human_Ex::GetSurname()
{
	return Surname;
}
void Human_Ex::SetName(char *name)
{
	Name = name;
}
void Human_Ex::SetSurname(char *surname)
{
	Surname = surname;
}
void Human_Ex::SetAge(int age)
{
	Age = age;
}
