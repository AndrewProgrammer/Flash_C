#include "Car.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
Car::Car()
{
	Nameofcar = new char[20];
	Kolesa = 0;
	Fari = 0;
	Dvigateli = 0;
	Sideniy = 0;
	Pasachirov = 0;
}
void Car::PrintCar(int k, int f, int d, int s, int p, char *nameofcar, int sizeofname, int Speed) 
{
	if (k <= 0 || f <= 0 || d <= 0 || s <= 0 || p <= 0 || nameofcar == nullptr || Speed <= 0 || sizeofname <=0)
	{
		cout << "Error!\n" << endl;
	}
	else
	{
		Kolesa = k;
		Fari = f;
		Dvigateli = d;
		Sideniy = s;
		Pasachirov = p;
		cout << "���� ������(��������): " << endl;
		Nameofcar = nameofcar;
		cout << "��� ����� ������: " << Nameofcar << endl;
		//PrintVehicle(sizeofname, Speed);��������
		cout << "�������� ������: " << Speed << endl;
		cout << "�����: " << Kolesa << endl;
		cout << "����: " << Fari << endl;
		cout << "����������: " << Dvigateli << endl;
		cout << "�������: " << Sideniy << endl;
		cout << "���������: " << Pasachirov << endl;
	}
}
Car::~Car()
{

}