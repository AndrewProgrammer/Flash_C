#include "Ship.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
Ship::Ship()
{
	Nameofship = new char[20];
	Gryz = 0;
	Dvigateli = 0;
	Pasachirov = 0;
}
void Ship::PrintShip(int g, int p, int d, char * nameofship, int sizeofname, int Speed)
{
	if (g <= 0 || p <= 0 || d <= 0 || nameofship == nullptr || Speed <= 0 || sizeofname <= 0)
	{
		cout << "Error!\n" << endl;
	}
	else
	{
		Gryz = g;
		Dvigateli = d;
		Pasachirov = p;
		cout << "���� �������(��������): " << endl;
		Nameofship = nameofship;
		cout << "��� ������ �������: " << Nameofship << endl;
		//PrintVehicle(sizeofname, Speed);��������
		cout << "�������� �������: " << Speed << endl;
		cout << "���������������� �������: " << Gryz << endl;
		cout << "����������: " << Dvigateli << endl;
		cout << "���������: " << Pasachirov << endl;
	}
}
Ship::~Ship()
{

}