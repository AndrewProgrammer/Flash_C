#include <iostream>
using namespace std;
void main()
{
	double a;
	cout << "Vedite chislo a"
	cin >> a;
	a *= 100;
	a += 0.5;
	a = (int)a;
	a /= 100;
	cout << a;
}
