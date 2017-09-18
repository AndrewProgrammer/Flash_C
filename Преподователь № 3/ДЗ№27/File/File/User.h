#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
class User
{
public:
	User() = default;
	~User() = default;
	//void OpenSource()
	//{
	//	ofstream of("E:\\Test.txt");
	//	if (of.is_open())
	//	{
	//		of << 3 << 4.18 << "Hello";//ofstream принимает все так как он конвертирует сразу все данные 
	//		//Date d;Для того чтобы это работало нужно перегрузить operator << в классе Date
	//		//of << d;
	//		of.close();
	//	}
	//}
	void WriteInFile()
	{
		FILE * f = fopen("E:\\Test.txt", "wb");//Создаем файл и записываем туда
		if (f != nullptr)
		{
			char name[255];
			char surname[255];
			int age;
			int name_length = strlen(name);
			int surname_length = strlen(surname);
			cout << "Enter your name: " << endl;
			cin >> name;
			cout << "Enter your surname: " << endl;
			cin >> surname;
			cout << "Enter your age: " << endl;
			cin >> age;
			fwrite(&name_length, sizeof(int), 1, f);//Записывает размер имя в файл
			fwrite(name, sizeof(char),name_length + 1, f);//Записывает имя в файл
			fwrite(&surname_length, sizeof(int), 1, f);//Записывает имя в файл
			fwrite(surname, sizeof(char),surname_length + 1, f);//Записывает фамилию в файл
			fwrite(&age, sizeof(int), 1, f);

			fclose(f);
		}
		else cout << "Error! File is undefined\n";
	}
	void ReadFile()
	{
		system("cls");
		FILE * f = fopen("E:\\Test.txt", "rb");
		if(f != nullptr)
		{
			int age;
			int name_length;
			int surname_length;
			fread(&name_length, sizeof(int), 1, f);
			char * name = new char[name_length + 1];
			fread(name, name_length + 1, 1, f);
			fread(&surname_length, sizeof(int), 1, f);
			char * surname = new char[surname_length + 1];
			fread(surname, surname_length + 1, 1, f);
			fread(&age, sizeof(int), 1, f);
			cout << "Your name is: " << name << endl;
			cout << "Your surname is: " << surname << endl;
			cout << "Your age is: " << age << endl;
			delete name;
			delete surname;

			fclose(f);
		}
		else cout << "Error! File is undefined\n";
	}
};