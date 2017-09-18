#include "GroupOfHuman.h"
#include "Human_Ex.h"
#include <iostream>
using namespace std;

//GroupOfHuman::GroupOfHuman()
//{
//	Human_Ex humans[5] =
//	{
//		Human_Ex("Andrew", "Sidorov", 16),
//		Human_Ex("Nano", "Smart", 20),
//		Human_Ex("Monolithic", "Obelisks", 21),
//		Human_Ex("Fleep", "Sider", 22),
//		Human_Ex(),
//	};
//}
GroupOfHuman::GroupOfHuman() :pArHuman(new Human_Ex*[10]), Human_count(0), m_capacity(10){};
GroupOfHuman::GroupOfHuman(const GroupOfHuman &source) : pArHuman(new Human_Ex*[source.Human_count]), m_capacity(source.m_capacity), Human_count(0)
{
	for (int i = 0; i < source.Human_count; i++)
	{
		Add(*(source.pArHuman[i]));
	}
}
GroupOfHuman::GroupOfHuman(const unsigned int hsize, Human_Ex *&h)
{
	if (hsize > 0)
	{
		Human_count = hsize;
	}
	else if (h != nullptr)
	{
		*pArHuman = h;
	}
	else cout << "Error!\n";
}
void GroupOfHuman::IncreaseCapacity()
{
	m_capacity *= 2;//Умножаем объем на 2
	Human_Ex ** temp = new Human_Ex*[m_capacity];//объем который нам нужно добавить
	for (int i = 0; i < Human_count; i++)//уже существующий размер
	{
		temp[i] = pArHuman[i];
	}
	delete[] pArHuman;
	pArHuman = temp;
}
void GroupOfHuman::Add(const Human_Ex &human)
{
	//111111Human_Ex * TempArHuman = new Human_Ex[Human_count + 1];//Создаем новый указатель типа данных Human_Ex который в свою очередь ссылается на динамическую память размером на один больше от массива кдасса Human_Ex
	////Циклом проходимся по размеру массива класса Human_Ex который копирует массив объектов класса Human_Ex в новый динамический массив созданный ранее
	//for (int i = 0; i < Human_count; i++)
	//{
	//	TempArHuman[i] = pArHuman[i];
	//}
	//TempArHuman[Human_count] = *&human;//Указываем на то что размер указателя который хранит массив динамической памяти будет иметь размер массива класса Human_Ex
	//delete[] pArHuman;// Удаляем память ранее созданого указателя Human_Ex
	////pArHuman[Human_count + 1];
	//pArHuman = TempArHuman;//присваиваем ранее созданный указатель Human_Ex к указателю Human_Ex
	if (Human_count == m_capacity)
	{
		IncreaseCapacity();
	}
	pArHuman[Human_count] = new Human_Ex(human);//вызов конструктора копирования для динамического объекта
	++Human_count;
}
void GroupOfHuman::Show()
{
	for (int i = 0; i < Human_count; i++)
	{
		for (int j = 0; j < Human_count; j++)
		{
			pArHuman[i][j].Show();
		}
	}
}
GroupOfHuman::~GroupOfHuman()
{
	for (int i = 0; i < Human_count; i++)
	{
		delete pArHuman[i];
	}
	delete[] pArHuman;//может быть ошибка
}