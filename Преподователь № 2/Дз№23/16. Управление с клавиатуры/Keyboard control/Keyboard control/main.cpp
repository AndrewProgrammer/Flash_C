#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// Рекомендуется к прочтению: http://www.cplusplus.com/doc/tutorial/other_data_types/
// Секция: Enumerated types (enum) и Enumerated types with enum class

enum keys { W = 87, w = 119, A = 65, a = 97, S = 83, s = 115, d = 100, D = 68, Esc = 27, Enter = 13,
			UpArrow = 72, DownArrow = 80, LeftArrow = 75, RightArrow = 77};

void main ()
{
	/*
		Для обработки нажатий на клавиатуре используется функция _getch. (см. пример 11)
		Эта функция возвращает код нажатой клавиши, при этом останавливает выполнение программы, до тех пор, пока клавиша не будет нажата.
		И кроме всего прочего, не выводит символ на экран.
		Для алфавитно-цифровых клавиш - всё предельно просто - возвращается ASCII код.
	*/
	
	int code = 0;
	bool looping = true;

	cout << "Test WASD keys. Press WASD keys to see action, or any other key to stop!" << endl;
	while (looping)
	{
		code = _getch ();
		switch (code)
		{
			case W:
			case w:
				cout << "Up" << endl;
				break;
			case A:
			case a:
				cout << "Left" << endl;
				break;
			case S:
			case s:
				cout << "Down" << endl;
				break;
			case d:
			case D:
				cout << "Right" << endl;
				break;
			default:
				looping = false;
				break;
		}
	}

	looping = true;

	/*
		Если с алфавитно-цифровыми клавишами всё просто, то с остальными не всё так просто. 
		Причем, с клавишами наподобие Escape, Enter тоже всё просто. Их коды есть среди первых 32 (управляющих) таблицы ASCII.
		Например, Esc - это 27, а Enter - 13.

		Но вот с клавишами наподобие стрелок, F1-F12 ситуация чуть сложнее.
		Проблема в том, что их надо как-то отличать от алфавитно цифровых, т.к. их коды пересекаются.
		Если пользователь нажмёт какую-то спец.клавишу (стрелку, или F1-F12) функция _getch вернет либо 224 либо 0.
		Для того, чтобы узнать, что за клавиша конкретно была нажата необходимо будет вызвать функцию _getch ещё раз.

	
	*/
	system ("cls");
	cout << "Testing special keys. Press Esc to stop." << endl;
	while (looping)
	{
		code = _getch ();
		
		

		if (code == 0 || code == 224) // Если была нажата спец. клавиша, то вызываем _getch ещё раз
		{
			code = _getch ();

			// Т.к. коды алфавитно-цифровых и спец.клавиш перескаются, switch находится внутри if, чтобы не потерять возможность реагировать
			// на ASCII клавиши
			switch (code)
			{
				case UpArrow:
					cout << "Up" << endl;
					break;
				case DownArrow:
					cout << "Down" << endl;
					break;
				case LeftArrow:
					cout << "Left" << endl;
					break;
				case RightArrow:
					cout << "Right" << endl;
					break;
			}


			// Существует проблема с клавишей для русской буквы "р" в таблице кодировки .866, т.к. она имеет код 224
			// И тогда будет условие истинным, но т.к. это не спец. клавиша, то второго кода в буфере не будет
			// И вызов _getch остановит программу для ожидания нажатия. Разумеется такое поведение некорректно
			// Решить эту проблему можно при помощи функции _kbhit() из conio.h
			// Эта функция проверяет, есть ли в буфере код нажатой клавиши. Если да - возвращает ненулевое значение, если нет - 0.
			// С её помощью можно решить данную проблему. Кроме того, она полезна, когда не нужно останавливать выполнение программы для ожидания нажатия клавиши.
			// Информация о _kbhit: https://msdn.microsoft.com/ru-ru/library/58w7c94c.aspx
		}
		else if (code == Esc)
			looping = false;

	}
	
	// В заголовочном файле Windows.h содержится довольно полезная функция Sleep
	// Функция Sleep останавливает программу на определенное кол-во милисекунд
	Sleep (2000); // Выдерживаем драматическую паузу в 2 секунды, а затем продолжаем
	cout << "After 2sec delay\n";
}