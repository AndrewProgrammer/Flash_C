#include "Vehicle.h"
class VehicleWithEngine : public Vehicle
{
	bool engine;
	double sizeofengine;
public:
	VehicleWithEngine();
	VehicleWithEngine(double SizeEngine, bool Engine);
	~VehicleWithEngine();
};