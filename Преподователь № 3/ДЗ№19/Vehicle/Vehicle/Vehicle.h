#pragma once
class Vehicle
{
private:
	char *nameofvehicle = nullptr;
	int speed;
public:
	Vehicle();
	void PrintVehicle(int sizeofname, int Speed);
	~Vehicle();
};

