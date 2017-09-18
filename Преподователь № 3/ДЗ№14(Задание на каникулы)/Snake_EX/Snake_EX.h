#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //организация ввода-вывода
#include <stdlib.h> //объявляет функции общего назначения
#include <time.h> //объявляет типы и функции, связанные с датой и временем
#include <conio.h>//консольный ввод-вывод
#include <windows.h>
using namespace std;
class Snake_EX
{
public:
	Snake_EX();
	void SetCur(int x, int y);//Позиция курсора
	void setColor(int text, int background);// Задание цвета
	void PrintLogo();
	void PrintLogo2();
	void Loading();
	void LOGOSNAKE();
	void LOGOEDITOR();
	void mainMenu();// Главное меню игры
	void Level(int n);// Загрузка выбранного уровня в массив
	void editorLvl();// Редактор уровней
	void Gameprocces(bool career);//ИГРА
	void addApple();// Добавление яблока
	void line(int n, char s);// Рисует линию произвольной длины и символа
	void showLevelNumber(int n);// Показ заставки уровня
	void addDiz(int k);// Добавляет указанное число дизориетаторов
	void addLife();// Добавляет жизнь на игровое поле
	void addSuperSpeed(int k);// Добавляет суперскорость на игровое поле
	void ADDDELETE2(int k);
	~Snake_EX();
};

