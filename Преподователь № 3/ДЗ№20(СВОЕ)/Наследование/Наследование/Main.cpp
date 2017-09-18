#include "Figura.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	Figura f;
	cin >> f;
	Circle c(f);
	cout << c.Radius();
	Rectangle g(f);
	cout << endl << g.Area() << endl;
	Square s(f);
	cout << endl << s.Area() << endl;
	Elipc e(f);
	cout << endl << e.Area() << endl;
}