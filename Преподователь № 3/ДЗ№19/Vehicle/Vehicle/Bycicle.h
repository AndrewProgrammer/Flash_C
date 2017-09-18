#include "Vehicle.h"
class Bycicle : public Vehicle
{
private:
	int Ves;
	char *NameofBycicle= nullptr;
public:
	Bycicle();
	void PrintBycicle(int v, char * nameofbycicle, int sizeofnamebycicle, int Speed);
	~Bycicle();
};