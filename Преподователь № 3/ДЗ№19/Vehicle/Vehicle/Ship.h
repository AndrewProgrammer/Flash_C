#include "Vehicle.h"
class Ship : public Vehicle
{
private:
	int Gryz, Pasachirov, Dvigateli;
	char *Nameofship = nullptr;
public:
	Ship();
	void PrintShip(int g,int p, int d, char * nameofship, int sizeofname, int Speed);
	~Ship();
};