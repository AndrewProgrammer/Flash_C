#include <iostream>;
using namespace std;
void main()
{
	int chislo;
	int d1, d2, d3, d4, d5, d6,d7,d8;
	cout << "vedite chislo\n";
	cin >> chislo;
	d1 = chislo / 10000;
	d2 = chislo % 10;
	d3 = chislo % 100;
	d4 = d3 / 10;
	d5 = chislo % 1000;
	d6 = d5 / 100;
	d7 = chislo % 10000;
	d8 = d7 / 1000;
	chislo = d4 * 10000 + d2 * 1000 + d1 * 100 + d8 * 10 + d6;
	cout << "Novoe chislo\n" << chislo;
}