#include "Listdouble.h"
#include "Nodedouble.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int N; //Число элементов в список
	int x; //Элементы вводимые в список
	List<int> lst; //Переменная, тип которой список
	cout << "Введите количевство элементов в списке: " << endl;
	cout << "N = "; cin >> N; //Указали сколько элементов вводить в список
	cout << "Введите эти элементы: " << endl;
	for (int i = 0; i<N; i++)
	{
		cout << i + 1 << ". x = "; cin >> x; //Ввод x с клавиатуры
		lst.Add(x); //Добавление элемента в список
	}
	lst.Show();
	cout << "Удаляем первый элемент: " << endl;
	lst.RemoveFirst();
	lst.Show();
	cout << "Удаляем элемент по индексу: " << endl;
	lst.Remove(3);
	lst.Show();
	cout << "Удаляем последний элемент : " << endl;
	lst.RemoveLast();
	lst.Show();
	cout << "Очищаем список" << endl;
	lst.ClearList();
}