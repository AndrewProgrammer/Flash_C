#include "SmartPtr.h"
#include <iostream>

using namespace std;

void main()
{
	SmartPtr<int> p1 = new int;
	SmartPtr<int> p2 = p1;
	SmartPtr<int> p3 = p2;
	SmartPtr<int> p4 = new int;
	SmartPtr<int> p5 = p4;
	p4 = p1;
	p4.GetCounter();
}