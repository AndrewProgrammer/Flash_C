#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //����������� �����-������
#include <stdlib.h> //��������� ������� ������ ����������
#include <time.h> //��������� ���� � �������, ��������� � ����� � ��������
#include <conio.h>//���������� ����-�����
#include <windows.h>
using namespace std;
class Snake_EX
{
public:
	Snake_EX();
	void SetCur(int x, int y);//������� �������
	void setColor(int text, int background);// ������� �����
	void PrintLogo();
	void PrintLogo2();
	void Loading();
	void LOGOSNAKE();
	void LOGOEDITOR();
	void mainMenu();// ������� ���� ����
	void Level(int n);// �������� ���������� ������ � ������
	void editorLvl();// �������� �������
	void Gameprocces(bool career);//����
	void addApple();// ���������� ������
	void line(int n, char s);// ������ ����� ������������ ����� � �������
	void showLevelNumber(int n);// ����� �������� ������
	void addDiz(int k);// ��������� ��������� ����� ��������������
	void addLife();// ��������� ����� �� ������� ����
	void addSuperSpeed(int k);// ��������� ������������� �� ������� ����
	void ADDDELETE2(int k);
	~Snake_EX();
};

