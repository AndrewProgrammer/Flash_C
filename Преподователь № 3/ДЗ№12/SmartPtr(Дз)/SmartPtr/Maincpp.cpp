#include "Default.h"
#include "SmartPtr.h"
#include "Delete.h"
void main()
{
	SmartPtr<Default> p1(new Default); 
	SmartPtr<Default[]> p2(new Default[10]);
	Default * ptr = new Default[10];
	Delete<Default[]> del;
	del(ptr);
}