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
		cout << "Ваша велосипеда(описание): " << endl;
		NameofBycicle = nameofbycicle;
		cout << "Имя вашего велосипеда: " << NameofBycicle << endl;
		//PrintVehicle(sizeofname, Speed);Работает
		cout << "Скорость велосипеда: " << Speed << endl;
		cout << "Вес который может выдержать велосипед: " << Ves << endl;
	}
}
Bycicle::~Bycicle()
{

}