#include <iostream>
using namespace std;
void main()
{
	int a, b;
	cout << "Enter a in hours from 0 to 24\n";
	cin >> a;
	cout << "Enter b in minutes from 0 to 60\n";
	cin >> b;
	if (a >= 6 && a < 12)
		cout << "Good morning!\n";
	else if (a >= 12 && a < 18)
		cout << "Good afternoon!\n";
	else if (a >= 18 && a <= 24)
		cout << "Good evening!\n";
	else if (a >= 0 && a < 6)
		cout << "Good night!\n";
}