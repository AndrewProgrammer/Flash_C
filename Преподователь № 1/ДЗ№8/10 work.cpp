#include <iostream>
using namespace std;
void main()
{
	int a, b, c, d, e, e1, e2;
	cout << "Vedite chetire chisla\n";
	cin >> a >> b >> c >> d;
	e1 = (a > b) ? a : b;
	e2 = (c > d) ? c : d;
	e = (e1 > e2) ? e1 : e2;
	cout << "Maks eto = " << e << endl;
}