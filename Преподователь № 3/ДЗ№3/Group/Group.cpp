#include <iostream>
#include "GroupOfHuman.h"
#include "Human_Ex.h"
using namespace std;
void main()
{
	setlocale(0, "ru");
	GroupOfHuman GroupAdd;
	GroupAdd.Add(Human_Ex("PUP", "PIP", 2));
	GroupAdd.Show();
}