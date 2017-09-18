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
		stackSymbol.Push(ch); // �������� �������� � ����
	}
	cout << endl;
	stackSymbol.PrintStack(); // ������� ���� �� �����
	cout << "\n\n -1 ������� �� �����\n";
	stackSymbol.Pop();
	stackSymbol.PrintStack();
	Stack_EX<char> newStack(stackSymbol);
	cout << "\n\n����������� �����������!\n";
	newStack.PrintStack();
	cout << "����� ������� ������� � �������: " << newStack.Peek() << endl;
	cout << "������ �� ����:" << stackSymbol.IsEmpty() << endl;
}