#pragma once
#include "Human_Ex.h"
class GroupOfHuman
{
private: 
	//Human_Ex * pHuman;
	//GroupOfHuman(const int SizeOfH)
	//{
	//	pHuman = new Human_Ex[SizeOfH];
	//}
	//~GroupOfHuman()
	//{
	//	delete[] pHuman;//����� ������
	//}
	unsigned int Human_count;
	int m_capacity = 10;//����� ������
	void IncreaseCapacity();
	Human_Ex **pArHuman = new Human_Ex*[10];
	//����� �� ������������ ������ ���������� ������ Human_Ex
public:
	GroupOfHuman();
	GroupOfHuman(const GroupOfHuman & source);
	GroupOfHuman(const unsigned int hsize, Human_Ex *&h);
	~GroupOfHuman();
	void Add(const Human_Ex &human);
	void Show();
};
