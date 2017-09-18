#include "Human_Ex.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	Human_Ex humancasual;
	humancasual.SetName("Andrew");
	humancasual.SetSurname("Lykianchikov");
	humancasual.SetAge(16);
	cout << "Your name is: " << humancasual.GetName() << endl;
	cout << "Your surname is: " << humancasual.GetSurname() << endl;
	cout << "Your age is: " << humancasual.GetAge() << endl;
	system("pause");
}
