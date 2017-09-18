#include <iostream>
using namespace std;
void main()
{
	int a, d1, d2, d3, d4, d5, d6, d7, d8;
	cout << "Vedite pyati znachnoe chislo A\n";
	cin >> a;
	d1 = a / 10000;
	d2 = a % 10;
	d3 = a % 100;
	d4 = d3 / 10;
	d5 = a % 1000;
	d6 = d5 / 100;
	d7 = a % 10000;
	d8 = d7 / 1000;
	if (d1 == d2 && d8 == d4)
		cout << "Chislo A - eto palindrom!\n";
	else cout << "Chislo A - eto ne palindrom!\n";
}
