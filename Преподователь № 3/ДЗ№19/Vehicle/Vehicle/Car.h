#include "Vehicle.h"
class Car : public Vehicle
{
private:
	int Kolesa, Fari, Dvigateli, Sideniy, Pasachirov;
	char *Nameofcar = nullptr;
public:
	Car();
	void PrintCar(int k, int f, int d, int s, int p, char * nameofcar,int sizeofname, int Speed);
	~Car();
};