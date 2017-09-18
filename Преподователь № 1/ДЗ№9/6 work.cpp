#include <iostream>
using namespace std;
void main()
{
	int ticket,summa1,summa2, d1, d2, d3, d4, d5, d6, d7, d8,d9,d10;
	cout << "Enter a six-digit number\n";
	cin >> ticket;
	d1 = ticket / 100000;
	d2 = ticket % 10;
	d3 = ticket % 100;
	d4 = d3 / 10;
	d5 = ticket % 1000;
	d6 = d5 / 100;
	d7 = ticket  % 10000;
	d8 = d7 / 1000;
	d9 = ticket % 100000;
	d10 = d9 / 10000;
	summa1 = d1 + d10 + d8;
	summa2 = d2 + d4 + d6;
	if (summa1 == summa2)
	{
		cout << "It is lucky ticket!\n";
	}
	else cout << "It isn`t lucky ticket!\n";
}