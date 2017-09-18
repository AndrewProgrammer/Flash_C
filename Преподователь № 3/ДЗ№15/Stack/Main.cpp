#include "Stack.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	Stack_EX<char> stackSymbol(5);
	char ch;
	for (int i = 0; i < 5; i++)
	{
		cin >> ch;
		stackSymbol.Push(ch); // помещаем элементы в стек
	}
	cout << endl;
	stackSymbol.PrintStack(); // Выводим стек на экран
	cout << "\n\n -1 элемент из стека\n";
	stackSymbol.Pop();
	stackSymbol.PrintStack();
	Stack_EX<char> newStack(stackSymbol);
	cout << "\n\nКонструктор копирования!\n";
	newStack.PrintStack();
	cout << "Самый верхний элемент в очереди: " << newStack.Peek() << endl;
	cout << "Полный ли стек:" << stackSymbol.IsEmpty() << endl;
}