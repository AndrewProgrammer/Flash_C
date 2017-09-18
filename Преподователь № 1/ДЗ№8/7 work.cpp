#include <iostream>
using namespace std;
void main()
{
	int a, d1, d2, d3, d4, d5, d6, kol;
	cout << "Vedite chetirex znachnoe chislo a\n";
	cin >> a;
	d1 = a / 1000;
	d2 = a % 10;
	d3 = a % 100;
	d4 = d3 / 10;
	d5 = a % 1000;
	d6 = d5 / 100;
	kol = d1 + d6 + d4 + d2;
	cout << "Vashe kolichestvo zifor v chisle a = !\n" << kol << endl;
}
