#include "Figura.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	Figura *f = new Circle(2);
	cout << f ->Area() << endl;
	Figura *R = new Rectangle(2,4);
	cout << endl << R->Area() << endl;
	Figura *S = new Square(4);
	cout << endl << S->Area() << endl;
	Figura *E = new Elipc(6,1);
	cout << endl << E->Area() << endl;
	Figura *T = new Triangle(13,14,15);
	cout << endl << T->Area() << endl;
	Figura *RT = new RectangularTriangle(13,14,15);
	cout << endl << RT->Area() << endl;
}