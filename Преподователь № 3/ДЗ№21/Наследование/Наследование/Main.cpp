#include "Figura.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	Square s;
	Rectangle * p = new Square();//������� ���������� ��� ��� virtual.
	p->SetHeight(10);
	delete p;
}