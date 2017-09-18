#include "Vehicle.h"
#include <iostream>
using namespace std;
Vehicle::Vehicle()
{
	nameofvehicle = new char[20];
	speed = 0;
}
Vehicle::~Vehicle()
{

}
void Vehicle::PrintVehicle(int sizeofname,int Speed)
{
	cin.getline(nameofvehicle, sizeofname);
	cout << "Имя транспорта: " << nameofvehicle << endl;
	speed = Speed;
	cout << "Скорость: " << speed << endl;
}
