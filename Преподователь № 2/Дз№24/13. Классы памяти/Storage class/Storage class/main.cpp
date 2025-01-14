#include <iostream>
#include "show.h"
using namespace std;


int myVar = 10;

void main ()
{
	/*
		В С/С++ существует понятие класса памяти (storage class).
		Класс памяти это характеристика, которая указывается при объявлении или определении объекта и регулирует его время жизни и/или область видимости,
			кроме того, некоторые классы памяти задают свои уникальные характеристики объекту.

		Существует 4 класса памяти (В С++11 их 3):
			1) auto - это класс памяти, который используется по умолчанию для всех переменных с локальной областью видимости и локальным временем жизни.
						Задает объекту локальное время жизни. (до С++11, в С++11 его использовать нельзя, т.к. ключевое слово auto потеряло прежнее значение)
			2) register - задает объекту локальное время жизни, и ЕСЛИ ВОЗМОЖНО то компилятор размещает переменную не в стэке (в спец. участке оперативной памяти),
							а в регистре процессора
			3) static - задает объекту глобальное время жизни (или если объект и так глобальный, то ограничивает область видимости в пределах одного файла)
			4) extern - время жизни глобальное. Запись с классом памяти extern - это ОБЪЯВЛЕНИЕ.
				Пример использования extern:
					extern int myVar; // Это ОБЪЯВЛЕНИЕ переменной. Указывает на то, что такая переменная есть, но неизвестно где. Возможно в другом файле.
					int myVar; // Это ОПРЕДЕЛЕНИЕ переменной. Здесь происходит выделение памяти.
	*/
	
	
	register int value = 5; // Переменная с классом памяти register даёт указание компилятору напрямую разместить переменную в регистре процессора, если такое возможно

	ShowMe (); // Функция, которая выводит значение переменной myVar, ОПРЕДЕЛЕННОЙ в этом .cpp файле
	// Функция узнает, что такая переменная существует где-то благодаря ОБЪЯВЛЕНИЮ с классом памяти extern (см. show.h)

	cout << "'value' variable with 'register' storage class: " << value << endl;
}