#include "Bycicle.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
Bycicle::Bycicle()
{
	NameofBycicle = new char[20];
	Ves = 0;
}
void Bycicle::PrintBycicle(int v, char * nameofbycicle, int sizeofnamebycicle, int Speed)
{
	if (v <=0 || NameofBycicle == nullptr || Speed <= 0 || sizeofnamebycicle <= 0)
	{
		cout << "Error!\n" << endl;
	}
	else
	{
		Ves = v;
		cout << "���� ����������(��������): " << endl;
		NameofBycicle = nameofbycicle;
		cout << "��� ������ ����������: " << NameofBycicle << endl;
		//PrintVehicle(sizeofname, Speed);��������
		cout << "�������� ����������: " << Speed << endl;
		cout << "��� ������� ����� ��������� ���������: " << Ves << endl;
	}
}
Bycicle::~Bycicle()
{

}