#include <iostream>
using namespace std;


/*
	Функции которые возвращают значение типа bool и используются для проверки какого-то утверждения условно называют "предикатом".
*/

// Функция, которая проверяет, является ли передаваемый символ или цифрой.
// Если это цифра - утверждение истинно - результат true. Если нет - утверждение ложно - результат false.
bool isNumber (char symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return true;
	else 
		return false;
}

// Проверка, четное ли число или нет.
bool isEven (int number)
{
	// Возвращаем результат логического выражения.
	// Если остаток от деления на 2 это 0 - результат выражения true - число четное
	return number % 2 == 0;
}


void main ()
{
	char sym = 0;
	cout << "Enter symbol: ";
	cin >> sym;

	if (isNumber (sym))
		cout << "This is number!" << endl;
	else
		cout << "This is not number!" << endl;
	


	int number = 11;

	cout << "Number " << number << " is " << ( isEven (number) ? "" : "not " ) << "even" << endl;
}