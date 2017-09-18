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
	Human_Ex(const char *name, const char *surname, unsigned int age);
	~Human_Ex();
	char* GetName();
	char* GetSurname();
	unsigned int GetAge();
	void SetName(char *name);
	void SetSurname(char *surname);
	void SetAge(int age);

};

