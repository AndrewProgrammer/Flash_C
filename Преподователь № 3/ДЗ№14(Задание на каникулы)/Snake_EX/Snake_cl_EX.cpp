#define _CRT_SECURE_NO_WARNINGS
#include "Snake_EX.h"
#include <iostream> //организация ввода-вывода
#include <stdlib.h> //объявляет функции общего назначения
#include <time.h> //объявляет типы и функции, связанные с датой и временем
#include <conio.h>//консольный ввод-вывод
#include <windows.h>
using namespace std;
void main()
{
	system("title SNAKE");// Заголовок окна
	system("mode con cols=120 lines=50");// Изменение размера окна
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO x;// Скрытие мигающего курсора
	x.bVisible = false;
	x.dwSize = 100;
	SetConsoleCursorInfo(h, &x);
	Snake_EX s1;
	while (1)
	{
		s1.mainMenu();
	}
	system("pause");
}