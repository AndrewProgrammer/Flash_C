#define _CRT_SECURE_NO_WARNINGS
#pragma once
class Human_Ex
{

private:
	char * Name;
	char * Surname;
	unsigned int Age;

public:
	Human_Ex();
	Human_Ex(const Human_Ex &source);
	Human_Ex(const char *name, const char *surname, unsigned int age);
	~Human_Ex();
	void SetName(const char *adding_name);
	void SetSurname(const char *adding_surname);
	void Show_Name();
	void Show_Surname();
	void Show();

};