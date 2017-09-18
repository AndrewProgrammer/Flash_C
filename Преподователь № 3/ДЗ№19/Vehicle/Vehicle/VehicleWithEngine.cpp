#include "VehicleWithEngine.h"
#include <iostream>
using namespace std;
VehicleWithEngine::VehicleWithEngine()
{
	sizeofengine = 0;
}
VehicleWithEngine::~VehicleWithEngine()
{

}
VehicleWithEngine::VehicleWithEngine(double SizeEngine, bool Engine)
{
	sizeofengine = SizeEngine;
	if (Engine == false)
	{
		cout << "Error!\n";
	}
	else Engine = true;
	engine = Engine;
}