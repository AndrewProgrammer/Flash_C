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
	m_capacity *= 2;//�������� ����� �� 2
	Human_Ex ** temp = new Human_Ex*[m_capacity];//����� ������� ��� ����� ��������
	for (int i = 0; i < Human_count; i++)//��� ������������ ������
	{
		temp[i] = pArHuman[i];
	}
	delete[] pArHuman;
	pArHuman = temp;
}
void GroupOfHuman::Add(const Human_Ex &human)
{
	//111111Human_Ex * TempArHuman = new Human_Ex[Human_count + 1];//������� ����� ��������� ���� ������ Human_Ex ������� � ���� ������� ��������� �� ������������ ������ �������� �� ���� ������ �� ������� ������ Human_Ex
	////������ ���������� �� ������� ������� ������ Human_Ex ������� �������� ������ �������� ������ Human_Ex � ����� ������������ ������ ��������� �����
	//for (int i = 0; i < Human_count; i++)
	//{
	//	TempArHuman[i] = pArHuman[i];
	//}
	//TempArHuman[Human_count] = *&human;//��������� �� �� ��� ������ ��������� ������� ������ ������ ������������ ������ ����� ����� ������ ������� ������ Human_Ex
	//delete[] pArHuman;// ������� ������ ����� ��������� ��������� Human_Ex
	////pArHuman[Human_count + 1];
	//pArHuman = TempArHuman;//����������� ����� ��������� ��������� Human_Ex � ��������� Human_Ex
	if (Human_count == m_capacity)
	{
		IncreaseCapacity();
	}
	pArHuman[Human_count] = new Human_Ex(human);//����� ������������ ����������� ��� ������������� �������
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
	delete[] pArHuman;//����� ���� ������
}