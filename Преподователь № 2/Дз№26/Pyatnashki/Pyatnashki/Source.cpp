#include "Header.h"

void main()
{
	int field[row][cols]{};
	PrintField(COORD{ 2,2 });	
	InitArray(field);
	PrintArray(COORD{ 4,4 }, field);
	Navigation(COORD{ 3,3 },field);
	system("pause");
}