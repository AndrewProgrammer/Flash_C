#define _CRT_SECURE_NO_WARNINGS
#include "Snake_EX.h"
#include <iostream> //����������� �����-������
#include <stdlib.h> //��������� ������� ������ ����������
#include <time.h> //��������� ���� � �������, ��������� � ����� � ��������
#include <conio.h>//���������� ����-�����
#include <windows.h>
using namespace std;
void main()
{
	system("title SNAKE");// ��������� ����
	system("mode con cols=120 lines=50");// ��������� ������� ����
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO x;// ������� ��������� �������
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