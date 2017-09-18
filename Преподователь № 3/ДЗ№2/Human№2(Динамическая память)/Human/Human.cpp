#include "Human_Ex.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(0, "ru");
	Human_Ex human("Andrey", "Lykianchikov", 16);
	Human_Ex* humand = new Human_Ex("Igor", "Yuriovich", 55);
	delete humand;
	system("pause");
}
